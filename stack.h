#ifndef STACK_H
#define STACK_H

#include <vector>
#include <stdexcept>

// Use inheritance from std::vector (choose public/private) as appropriate
template <typename T>
class Stack : private std::vector<T>
{
public:
    Stack<T>(){

    }
    
    ~Stack<T>(){

    }

    bool empty() const {
        return std::vector<T>::empty();
    }

    size_t size() const {
        return std::vector<T>::size();
    }

    void push(const T& item) {
        std::vector<T>::push_back(item);
    }

    void pop() { // throws std::underflow_error if empty
        if(this->empty()){
            throw std::underflow_error("Stack underflow");
        }
        std::vector<T>::pop_back();
    }
    T const & top() const { // throws std::underflow_error if empty
        if(this->empty()){
            throw std::underflow_error("Stack underflow");
        }
        return std::vector<T>::back();
    }
    // Add other members only if necessary
};


#endif