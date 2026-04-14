#include <iostream>
#include <stack>

using namespace std;
class MinStack
{
private:
    // Stack to store actual values
    stack<int> mainStack;
    // Stack to keep track of minimum values
    stack<int> minStack;

public:
    MinStack()
    {
        // Constructor doesn't need any initialization here
    }

    void push(int val)
    {
        // Push to the main stack
        mainStack.push(val);

        // For the minStack, only push if:
        // 1. It's empty, or
        // 2. New value is less than or equal to the current minimum
        if (minStack.empty() || val <= minStack.top()) {
            minStack.push(val);
        }
    }

    void pop()
    {
        // If the top of main stack is the same as the top of min stack,
        // pop from min stack as well
        if (mainStack.top() == minStack.top()) {
            minStack.pop();
        }
        // Always pop from the main stack
        mainStack.pop();
    }

    int top()
    {
        // Return the top value of the main stack
        return mainStack.top();
    }

    int getMin()
    {
        // Return the top value of min stack, which is the current minimum
        return minStack.top();
    }
};

int main() {

 //Your MinStack object will be instantiated and called as such:
    MinStack* obj = new MinStack();
    obj->push(3);
    obj->pop();
    int param_3 = obj->top();
    int param_4 = obj->getMin();
    std::cout <<param_3 << param_4<< std::endl;
    return 0;
}