#include <OpenGlassBox/OpenGlassBox.hpp>

#include <cstdlib>
#include <iostream>

namespace
{

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

	mapRule CreateGrass
		rate 7 ticks
		map Water remove 10 randomTilesPercent 90
		map Grass add 1
	end

	unitRule SendPeopleToWork
		rate 20 ticks
		local People remove 1
		agent People to Work add [ People 1 ]
	end

	unitRule SendPeopleToHome
		rate 100 ticks
		map Water greater 70
		local People remove 1
		agent Worker to Home add [ People 1 ]
	end
end

units
	unit Home color 0xFF00FF mapRadius 1 rules [ SendPeopleToWork ] targets [ Home ] caps [ People 4 ] resources [ People 4 ]
	unit Work color 0x00AAFF mapRadius 3 rules [ SendPeopleToHome ] targets [ Work ] caps [ People 2 ] resources [ ]
end

maps
	map Water color 0x0000FF capacity 100 rules [  ]
	map Grass color 0x00FF00 capacity 10 rules [ CreateGrass ]
end
)ogs";

} // namespace

int main()
{
    const uint32_t grid_size = 64u;

    // Create the simulation
    ogb::Simulation simulation(grid_size, grid_size);

    // Parse the script. Alternatively, you can load a script from a file.
    if (!simulation.script().parseString(kScript))
    {
        std::cout << "Error parsing script: "
                  << simulation.script().formatErrors()
                  << std::endl;
        return EXIT_FAILURE;
    }

    // Add a city to the simulation
    ogb::City& city = simulation.addCity("MyCity", ogb::Vector3f(0.f, 0.f, 0.f));

    // Install the Dijkstra router needed for agent routing
    ogb::installDijkstraRouter(city, simulation.config());

    // Add the maps to the city. Water and Grass are the only maps used in this example.
    city.addMap(simulation.script().getMapType("Water"));
    city.addMap(simulation.script().getMapType("Grass"));

    // Define "dirty road" as the way type for road segments
    ogb::Path& road = city.addPath(simulation.script().getPathType("Road"));
    ogb::WayType const& dirt = simulation.script().getWayType("Dirt");

    // Add the nodes as road junctions: define a triangle shape
    ogb::Node& a = road.addNode(ogb::Vector3f(0.f, 0.f, 0.f));
    ogb::Node& b = road.addNode(ogb::Vector3f(60.f, 0.f, 0.f));
    ogb::Node& c = road.addNode(ogb::Vector3f(30.f, 52.f, 0.f));

    // Add the dirty ways as road segments
    road.addWay(dirt, a, b);
    road.addWay(dirt, b, c);
    road.addWay(dirt, c, a);

    // Add the buildings to the city
    city.addUnit(simulation.script().getUnitType("Home"), a);
    city.addUnit(simulation.script().getUnitType("Work"), b);

    // Set the simulation time to 8:00 AM and the total ticks to the number of ticks in a day
    simulation.clock().setTimeOfDay(0u, 8u, 0u);
    simulation.setTotalTicks(simulation.clock().ticks());

    // Run the simulation for 200 ticks
    for (uint32_t tick = 0u; tick < 200u; ++tick)
    {
        simulation.update(simulation.config().tickDuration());
    }

    // Print the number of units and agents in the city
    std::cout << city.units().size() << " units, "
              << city.agents().size() << " agents\n";

    return EXIT_SUCCESS;
}
