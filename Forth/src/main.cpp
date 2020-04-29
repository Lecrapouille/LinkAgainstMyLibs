#include <SimForth/SimForth.hpp>
#include "Config.hpp"
#include <iostream>

//------------------------------------------------------------------------------
int main()
{
    forth::Forth forth;

    // Boot the minimal system
    if (!forth.boot())
      return -1;

    // Access to the parameters stack
    forth::DataStack& DS = forth.dataStack();

    // Push input parameters
    DPUSH(2); // int
    DPUSH(2.5f); // float

    // Do a computation
    forth.interpreter.options.quiet = true; // FIXME
    if (!forth.interpretString(": FOO + + ; 2.4 FOO"))
      return -1;

    // Get the
    if (DS.depth() == 0)
    {
        std::cout << "No result returned!" << std::endl;
    }
    else
    {
       forth::Cell tos = DPOP();
       std::cout << "Result " << tos << std::endl;
    }

    return 0;
}
