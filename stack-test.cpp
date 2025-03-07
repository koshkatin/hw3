#include "stack.h"
#include <iostream>
#include <string>
#include <stdexcept>

int main()
{
    // Test Stack<int>
    Stack<int> nums;
    std::cout << "Testing Stack<int>..." << std::endl;

    // Test empty stack
    std::cout << "Is empty: " << nums.empty() << std::endl;

    // Test push and top
    nums.push(1);
    nums.push(2);
    nums.push(3);
    std::cout << "Top element: " << nums.top() << std::endl;

    // Test size
    std::cout << "Size: " << nums.size() << std::endl;

    // Test pop
    nums.pop();
    std::cout << "Top element after pop: " << nums.top() << std::endl;
    std::cout << "Size after pop: " << nums.size() << std::endl;

    // Test pop until empty
    nums.pop();
    nums.pop();
    std::cout << "Is empty after popping all elements: " << nums.empty() << std::endl;

    // Test pop on empty stack (should throw exception)
    try {
        nums.pop();
    } catch (const std::underflow_error& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Test top on empty stack (should throw exception)
    try {
        nums.top();
    } catch (const std::underflow_error& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Test Stack<std::string>
    Stack<std::string> strs;
    std::cout << "Testing Stack<std::string>..." << std::endl;

    // Test push and top
    strs.push("hello");
    strs.push("world");
    std::cout << "Top element: " << strs.top() << std::endl;

    // Test size
    std::cout << "Size: " << strs.size() << std::endl;

    // Test pop
    strs.pop();
    std::cout << "Top element after pop: " << strs.top() << std::endl;
    std::cout << "Size after pop: " << strs.size() << std::endl;

    // Test pop until empty
    strs.pop();
    std::cout << "Is empty after popping all elements: " << strs.empty() << std::endl;

    // Test pop on empty stack (should throw exception)
    try {
        strs.pop();
    } catch (const std::underflow_error& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Test top on empty stack (should throw exception)
    try {
        strs.top();
    } catch (const std::underflow_error& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}