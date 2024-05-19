#include <iostream>
#include <forward_list>

using namespace std;

template<typename T>
class Stack {
private:
    forward_list<T> data;
    size_t count; 

public:
    Stack() : count(0) {} 
    
    bool empty() const {
        return data.empty();
    }

    void push(const T& value) {
        data.push_front(value);
        ++count; 
    }

    void pop() {
        if (!empty()) {
            data.pop_front();
            --count; 
        } else {
            cerr << "Stack is empty. Cannot pop.\n";
        }
    }

    T& top() {
        if (!empty()) {
            return data.front();
        } else {
            cerr << "Stack is empty.\n";
            exit(EXIT_FAILURE);
        }
    }

    size_t size() const {
        return count; 
    }
};
