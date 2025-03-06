#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T> // chosen private inheritence from vector
{
public:
    Stack() = default;
    ~Stack() = default;

    bool empty() const
    {
        return std::vector<T>::empty(); // uses the empty function provided by the vector library
    }

    size_t size() const
    {
        return std::vector<T>::size(); // uses the size function provided by the vector library 
    }

    void push(const T& item)
    {
        std::vector<T>::push_back(item); // uses the push_back function provided by the vector library
    }

    void pop()  // throws std::underflow_error if empty
    {
        if ( empty() ) { // if statement to check if their is anything in the stack
          throw std::underflow_error("STACK IS EMPTY");
        }
        std::vector<T>::pop_back(); // uses the pop_back function provided by the vector library
    }

    const T& top() const // throws std::underflow_error if empty
    {
        if ( empty() ) { // if statement to check if their is anything in the stack
          throw std::underflow_error("STACK IS EMPTY");
        }
        return std::vector<T>::back(); // uses the back function provided by the vector library
    }
    
    // Add other members only if necessary
};


#endif