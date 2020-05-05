#include <SimForth/SimForth.hpp> // Forth interpreter
#include "config.hpp"

//------------------------------------------------------------------------------
// This file shows a basic example of using a Forth interpreter embedded in your
// C or C++ project.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
void info(forth::Cell const& tos)
{
    switch (tos.tag)
    {
        case forth::Cell::INT:
            std::cout << "Result is an integer: " << tos.i << std::endl;
            break;
        case forth::Cell::FLOAT:
            std::cout << "Result is an double: " << tos.f << std::endl;
            break;
        default: break;
    }
}

//------------------------------------------------------------------------------
int main()
{
    forth::Forth forth;
    forth.interpreter.options.quiet = true; // FIXME

    // Boot a minimal Forth system (else the Forth dictionary is totaly empty).
    if (!forth.boot())
      return -1;

    // Access to the Foarth Data-Stack (aka parameters stack).
    // Give the name DS to this variable for faster notations using macros:
    // DPUSH(x), x = DPOP(), x = DPICK(n), DDROP().
    forth::DataStack& DS = forth.dataStack();

    // Push some input parameters
    DS.push(2);   // int    // alternative: DPUSH(2) iff variable DS is defined
    DS.push(2.5); // float  // alternative: DPUSH(2.5) iff variable DS is defined

    // Show data content in hexadecimal
    std::cout << "Inputs: ";
    int base = 16;
    DS.display(std::cout, base);

    // Interpret a script:
    std::string script(".\" Hello Forth\" : FOO f+ f+ ; 2.4 FOO DUP DUP >INT");
    std::cout << "Interprete the script: " << script << std::endl;
    if (!forth.interpretString(script.c_str()))
      return -1;

    // Possible alternatives:
    //   - script file: forth.interpretFile("the/path/file.fth")
    //   - interactive prompt: forth.interactive(); The word BYE makes quit the function

    // Get the result of the computation (if any)
    if (DS.depth() == 0)
    {
        std::cout << DS.name() << "-Stack is empty" << std::endl;
    }
    else
    {
       std::cout << DS.depth() << " elements remaining in " << DS.name() << "-Stack:";

       // TOS: Top Of Stack
       forth::Cell tos1 = DS.pick(0); // alternative: tos1 = DPICK(0) iff variable DS is defined
       forth::Cell tos2 = DS.pick(1); // alternative: tos2 = DPICK(1) iff variable DS is defined
       forth::Cell tos3 = DS.pick(2); // alternative: tos3 = DPICK(2) iff variable DS is defined
       std::cout << " " << tos3 << " " << tos2 << " " << tos1 << std::endl;

       // Cell structure
       forth::Cell tos = DS.pop(); // alternative: tos = DPOP() iff variable DS is defined
       info(tos);
       info(DS.pop());

       // Clear the stack
       std::cout << "Stack depth before clearing the " << DS.name() << "-Stack: "
                 << DS.depth() << std::endl;
       DS.reset();
       std::cout << "Stack depth after clearing the " << DS.name() << "-Stack: "
                 << DS.depth() << std::endl;
    }

    return 0;
}
