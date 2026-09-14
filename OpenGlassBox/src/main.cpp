// A whole game in one file: load a ruleset, found a city, lay a triangle of
// roads with a house and a factory on it, and let the morning commute run.
//
// This example only sees the installed headers, so it doubles as a check that
// the public API is enough on its own.

#include <OpenGlassBox/OpenGlassBox.hpp>
#include <cstdlib>
#include <iostream>

namespace {

// The gameplay: nothing below is hard-coded in the engine. Resources, roads,
// buildings and rules are all declared here, and the engine only knows the
// names this script gives them.
char const* const kScript = R"ogs(
resources
	resource Water
	resource Grass
	resource People
end

paths
	path Road color 0xAAAAAA
end

segments
	segment Dirt color 0xAAAAAA
end

agents
	agent People color 0xFFFF00 speed 10
	agent Worker color 0xFFFFFF speed 10
end

rules

	layerRule CreateGrass
		rate 7 ticks
		layer Water remove 10 randomTilesPercent 90
		layer Grass add 1
	end

	buildingRule SendPeopleToWork
		rate 20 ticks
		local People remove 1
		agent People to Work add [ People 1 ]
	end

	buildingRule SendPeopleToHome
		rate 100 ticks
		layer Water greater 70
		local People remove 1
		agent Worker to Home add [ People 1 ]
	end
end

buildings
	building Home color 0xFF00FF layerRadius 1 rules [ SendPeopleToWork ] targets [ Home ] caps [ People 4 ] resources [ People 4 ]
	building Work color 0x00AAFF layerRadius 3 rules [ SendPeopleToHome ] targets [ Work ] caps [ People 2 ] resources [ ]
end

layers
	layer Water color 0x0000FF capacity 100 rules [  ]
	layer Grass color 0x00FF00 capacity 10 rules [ CreateGrass ]
end
)ogs";

}  // namespace

int main() {
  // Runtime settings. Everything has a default, so only say what differs
  // from it: here, how many cells wide a city is when no size is given.
  ogb::Config config;
  config.grid.defaultCitySizeU = 64u;
  config.grid.defaultCitySizeV = 64u;

  // The whole game. This is the only object an application has to hold: the
  // ruleset, the world, the cities and the clock all live inside it.
  ogb::Simulation simulation(config);

  // Load the gameplay before founding anything. A building keeps a reference
  // to the recipe it was built from, and those recipes live in the ruleset,
  // so the ruleset has to be in place first and outlive every city.
  // loadScriptFile() reads a .ogs file instead.
  if (!simulation.loadScriptString(kScript)) {
    std::cerr << "Error parsing script: " << simulation.formatScriptErrors()
              << std::endl;
    return EXIT_FAILURE;
  }

  // Found a city. The size comes from GridConfig above; the position is
  // where its top-left cell sits in the world.
  ogb::City& city = simulation.addCity("MyCity", ogb::Vector3f(0.f, 0.f, 0.f));

  // Give the city a router before anything travels. An agent with no router
  // never leaves the crossroads it was sent from, and nothing says so: the
  // city simply looks asleep.
  ogb::installDijkstraRouters(simulation);

  // Ask for the layers of the environment the rules read and write. They are
  // owned by the world and shared by every city, so this creates each one
  // once whatever how many cities ask.
  ogb::Ruleset const& rules = simulation.getRuleset();
  city.addLayer(rules.getLayerType("Water"));
  city.addLayer(rules.getLayerType("Grass"));

  // A network of roads, and the recipe its segments are built from. An agent
  // never leaves the network it started on, so a city with a road network
  // and a rail network has two of these.
  ogb::Path& road = city.addPath(rules.getPathType("Road"));
  ogb::SegmentType const& dirt = rules.getSegmentType("Dirt");

  // Three crossroads, in world coordinates.
  ogb::Node& a = road.addNode(ogb::Vector3f(0.f, 0.f, 0.f));
  ogb::Node& b = road.addNode(ogb::Vector3f(60.f, 0.f, 0.f));
  ogb::Node& c = road.addNode(ogb::Vector3f(30.f, 52.f, 0.f));

  // The streets joining them. Segments are undirected: one-way traffic is
  // not modelled.
  road.addSegment(dirt, a, b);
  road.addSegment(dirt, b, c);
  road.addSegment(dirt, c, a);

  // Two buildings, each standing on a crossroads so that agents can reach
  // them. A building may also stand along a street, at an offset.
  city.addBuilding(rules.getBuildingType("Home"), a);
  city.addBuilding(rules.getBuildingType("Work"), b);

  // Open the working day. Rules may be written as "hour between 8 18", so
  // starting at midnight would mean watching a city where nothing is awake.
  simulation.setTimeOfDay(0u, 8u, 0u);

  // A new simulation starts paused, so that a game can be built before
  // anything moves.
  simulation.setPaused(false);

  // The game loop. update() is handed seconds of wall time, not ticks: it
  // scales them, accumulates them and runs as many fixed ticks as fit. That
  // is what makes the simulation advance at the same rate whatever the frame
  // rate. Here there is no frame to wait for, so feed it exactly one tick at
  // a time.
  for (uint32_t tick = 0u; tick < 200u; ++tick) {
    simulation.update(simulation.getConfig().time.tickDuration());
  }

  std::cout << city.getBuildings().size() << " buildings, "
            << city.getAgents().size() << " agents\n";

  return EXIT_SUCCESS;
}
