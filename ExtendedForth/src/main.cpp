#include <SimForth/SimForth.hpp> // Forth interpreter
#include "AnyStacks.hpp"
#include "project_info.hpp"

// FIXME: to be removed {

#ifndef USE_COMPUTED_GOTO
#  define CODE(xt) CASE(forth::ExtendedPrimitives::xt)
#endif // USE_COMPUTED_GOTO

//------------------------------------------------------------------------------
//! \brief Store a non-immediate primitive
//------------------------------------------------------------------------------
#define PRIMITIVE(tok, name)                                                   \
    CREATE_ENTRY(forth::ExtendedPrimitives::tok, name, false, true)

//------------------------------------------------------------------------------
//! \brief Store an immediate primitive
//------------------------------------------------------------------------------
#define IMMEDIATE(tok, name)                                                   \
    CREATE_ENTRY(forth::ExtendedPrimitives::tok, name, true, true)

//------------------------------------------------------------------------------
//! \brief Store an private non-immediate primitive
//------------------------------------------------------------------------------
#define HIDDEN(tok, name)                                                      \
    CREATE_ENTRY(forth::ExtendedPrimitives::tok, name, false, false)

// } FIXME: to be removed

//------------------------------------------------------------------------------
// Example class that will stored in Forth stack
class Foo
{
public:
   Foo(int i = 0) : a(i) {}
   int a;
};

//------------------------------------------------------------------------------
//! \brief Extend SimForth primitives
namespace forth
{
   enum ExtendedPrimitives
   {
      FOO = forth::Primitives::MAX_PRIMITIVES_,
      MAX_EXTENDED_PRIMITIVES_
   };
}

//------------------------------------------------------------------------------
//! \brief Extend SimForth interpreter by adding an new stack and new primitives
class ExtendedInterpreter: public forth::Interpreter
{
public:

    ExtendedInterpreter(forth::Dictionary& dico, forth::Options const& options)
        : forth::Interpreter(dico, options)
    {}

    virtual forth::Token countPrimitives() const override
    {
        return forth::ExtendedPrimitives::MAX_EXTENDED_PRIMITIVES_;
    }

    Stacks& anyStacks()
    {
        return HS;
    }

private:

    virtual void executePrimitive(forth::Token const xt) override
    {
        forth::ExtendedPrimitives const primitive = static_cast<forth::ExtendedPrimitives>(xt);
        DISPATCH(primitive)
        {
            // ---------------------------------------------------------------------
            CODE(FOO)
                HS.push<Foo>(Foo(42));
                DS.push(forth::Cell::integer(45));
                DS.tos() += forth::Cell::integer(HS.pop<Foo>().a);
            NEXT;

            // ---------------------------------------------------------------------
            CODE(MAX_EXTENDED_PRIMITIVES_)
            UNKNOWN
                forth::Interpreter::executePrimitive(xt);
            NEXT;
        }
    }

private:

    Stacks HS;
};

//------------------------------------------------------------------------------
//! \brief Extend SimForth facade
class ExtendedForth: public SimForth
{
public:

    ExtendedForth(forth::Options const& options = forth::Options())
    {
        extend<forth::Dictionary, ExtendedInterpreter>(options);
    }

    Stacks& anyStacks()
    {
        return interpreter<ExtendedInterpreter>().anyStacks();
    }

private:

    virtual void bootCore() override
    {
        SimForth::bootCore();
        PRIMITIVE(FOO, "FOO");
    }

    virtual bool bootThirdParts() override
    {
        return SimForth::bootThirdParts();
    }
};

//------------------------------------------------------------------------------
int main()
{
    using namespace forth;

    ExtendedForth forth;

    if (!forth.boot())
        return -1;

    //forth.interactive();
    forth.interpretString("FOO .");

    Stacks& AS = forth.anyStacks();
    AS.push<Cell>(Cell::integer(45));
    AS.push<Foo>(Foo(42));
    AS.tos<Cell>() += Cell::integer(AS.pop<Foo>().a);
    std::cout << AS.pop<Cell>() << std::endl;

    return 0;
}
