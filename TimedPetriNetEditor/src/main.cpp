#include <TimedPetriNetEditor/PetriNet.hpp>
//#include <Editor/DearImGui/Editor.hpp> // FIXME poor header: shall be <TimedPetriNetEditor/Editor/DearImGui/Editor.hpp>
// and calling "Application.hpp" which forec use to use -I
#include <stdio.h>

//------------------------------------------------------------------------------
int main()
{
    tpne::Net net(tpne::TypeOfNet::TimedPetriNet);
    assert(net.places() == 0);
    assert(net.transitions() == 0);

    tpne::Place& p0 = net.addPlace(3.5f, 4.0f, 1u);
    tpne::Transition& t0 = net.addTransition(3.14f, 2.16f);
    net.addArc(p0, t0);

    assert(net.places() == 1);
    assert(net.transitions() == 1);
    assert(net.arcs() == 1);

    // FIXME: ahrd to compile
    //tpne::Editor editor;
    //editor.run("");

    return EXIT_SUCCESS;
}
