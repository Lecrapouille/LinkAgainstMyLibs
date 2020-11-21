#ifndef ANYSTACKS_HPP
#define ANYSTACKS_HPP

#include <SimForth/Stack.hpp>
#include <functional>
#include <unordered_map>

class Stacks
{
public:

    template<class T> void clear() { stack<T>().clear(); }
    template<class T> int32_t depth() { return stack<T>().depth(); }
    template<class T> void push(T const& t) { stack<T>().push(t); }
    template<class T> T& pop() { return stack<T>().pop(); }
    template<class T> void drop() { stack<T>().drop(); }
    template<class T> T& tos() { return stack<T>().tos(); }
    template<class T> bool hasOverflowed() { return stack<T>().hasOverflowed(); }
    template<class T> bool hasUnderflowed() { return stack<T>().hasUnderflowed(); }

    // Destroy all created heterogeneous stacks
    void erase()
    {
        for (auto&& erase_func : m_erase_functions)
        {
            erase_func(*this);
        }
    }

    ~Stacks() { erase(); }

private:

    template<class T>
    forth::Stack<T>& stack()
    {
        auto it = stacks<T>.find(this);
        if (it == std::end(stacks<T>))
        {
            // Hold list of created heterogeneous stacks for their destruction
            m_erase_functions.emplace_back([](Stacks& s)
            {
                std::cout << "Erasing stack " << typeid(T).name() << std::endl;
                stacks<T>.erase(&s);
            });

            return stacks<T>[this];
        }
        return it->second;
    }

    template<class T>
    static std::unordered_map<const Stacks*, forth::Stack<T>> stacks;

    std::vector<std::function<void(Stacks&)>> m_erase_functions;
};

template<class T>
std::unordered_map<const Stacks*, forth::Stack<T>> Stacks::stacks;

#endif
