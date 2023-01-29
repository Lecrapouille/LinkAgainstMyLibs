#include <OpenGlassBox/Simulation.hpp>
#include <stdio.h>

//------------------------------------------------------------------------------
int main()
{
    Simulation simulation(12u, 12u);

    if (!simulation.parse("TestCity.txt"))
        return EXIT_FAILURE;

    // --- Paris city
    City& paris = simulation.addCity("Paris", Vector3f(400.0f, 200.0f, 0.0f));
    Path& road = paris.addPath(simulation.getPathType("Road"));
    Node& n1 = road.addNode(Vector3f(60.0f, 60.0f, 0.0f) + paris.position());
    Node& n2 = road.addNode(Vector3f(300.0f, 300.0f, 0.0f) + paris.position());
    Node& n3 = road.addNode(Vector3f(60.0f, 300.0f, 0.0f) + paris.position());
    Way& w1 = road.addWay(simulation.getWayType("Dirt"), n1, n2);
    Way& w2 = road.addWay(simulation.getWayType("Dirt"), n2, n3);
    Way& w3 = road.addWay(simulation.getWayType("Dirt"), n3, n1);
    Unit& u1 = paris.addUnit(simulation.getUnitType("Home"), road, w1, 0.66f);
    Unit& u2 = paris.addUnit(simulation.getUnitType("Home"), road, w1, 0.5f);
    Unit& u3 = paris.addUnit(simulation.getUnitType("Work"), road, w2, 0.5f);
    Unit& u4 = paris.addUnit(simulation.getUnitType("Work"), road, w3, 0.5f);
    Map& m1 = paris.addMap(simulation.getMapType("Grass"));
    Map& m2 = paris.addMap(simulation.getMapType("Water"));

    // --- Versailles city
    City& versailles = simulation.addCity("Versailles", Vector3f(0.0f, 30.0f, 0.0f));
    versailles.addMap(simulation.getMapType("Grass"));
    versailles.addMap(simulation.getMapType("Water"));
    Path& road2 = versailles.addPath(simulation.getPathType("Road"));
    Node& n4 = road2.addNode(Vector3f(40.0f, 20.0f, 0.0f) + versailles.position());
    Node& n5 = road2.addNode(Vector3f(200.0f, 200.0f, 0.0f) + versailles.position());
    Way& w4 = road2.addWay(simulation.getWayType("Dirt"), n4, n5);
    Way& w5 = road2.addWay(simulation.getWayType("Dirt"), n5, n1);
    Unit& u5 = versailles.addUnit(simulation.getUnitType("Work"), road2, w4, 0.9f);

    // Do X simulation steps. Place this code in your runtime game loop
    float delta_time = 0.1f; // as seconds
    simulation.update(delta_time);
    simulation.update(delta_time);
    simulation.update(delta_time);

    // Debug Paris Agents. Not debuged here: Units, Maps, Paths
    for (auto const& agent: paris.agents())
    {
        printf("Agent %u (%s):\n", agent->id(), agent->type().c_str());
        printf("  Position %.3f, %.3f\n", agent->position().x, agent->position().y);
        printf("  Has %zu Resources:\n", agent->resources().size());
        for (auto const& r: agent->resources())
        {
            printf("    %s: %u / %u\n", r.type().c_str(), r.getAmount(), r.getCapacity());
        }
    }

    return EXIT_SUCCESS;
}
