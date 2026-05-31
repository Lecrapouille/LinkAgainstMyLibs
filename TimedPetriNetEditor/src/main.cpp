#include <PetriNet/PetriNet.hpp>

#include <cassert>
#include <cstdlib>
#include <iostream>

//------------------------------------------------------------------------------
int main()
{
    tpne::Net net(tpne::TypeOfNet::TimedPetriNet);
    assert(net.places().empty());
    assert(net.transitions().empty());

    tpne::Place& p0 = net.addPlace(3.5f, 4.0f, 1u);
    tpne::Transition& t0 = net.addTransition(3.14f, 2.16f);
    net.addArc(p0, t0);

    assert(net.places().size() == 1u);
    assert(net.transitions().size() == 1u);
    assert(net.arcs().size() == 1u);

    std::cout << net.places()[0].key << std::endl;
    std::cout << net.transitions()[0].key << std::endl;

    // GUI (TimedPetriGUI) is provided by pkg-config TimedPetriGUI, not TimedPetriNet.
    // tpne::Editor editor;
    // editor.run("");

    return EXIT_SUCCESS;
}
