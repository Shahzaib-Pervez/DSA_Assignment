#include <iostream>
using namespace std;

/* ===============================================================
    CLASS: StackArray
    ----------------------------------------------------------------
    The StackArray class represents a stack data structure
    implemented using a fixed-size array. It follows the LIFO
    (Last In First Out) principle.
     - The array has a maximum capacity (default 100).
     - 'stack_top' is an index that points to the position of
       the topmost element (-1 means the stack is empty).
     - push() adds elements to the top
     - pop() removes elements from the top
     - peek() views the top element without removing it
==================================================================*/
class StackArray {
private:
    static const int MAX_SIZE = 100;  // Maximum capacity of the stack
    int arr[MAX_SIZE];                // Array to store stack elements
    int stack_top;                    // Index of the top element (-1 if empty)

public:
    /* ------------------------------------------------------------
        CONSTRUCTOR: StackArray()
        ------------------------------------------------------------
        Initializes the stack to an empty state.
        'stack_top' is set to -1 to indicate no elements exist.
    -------------------------------------------------------------*/
    StackArray() : stack_top(-1) {}

    /* ------------------------------------------------------------
        FUNCTION: bool empty() const
        ------------------------------------------------------------
        Checks whether the stack has any elements.
        Returns true if stack_top is -1, otherwise false.
    -------------------------------------------------------------*/
    bool empty() const {
        return (stack_top == -1);
    }

    /* ------------------------------------------------------------
        FUNCTION: bool full() const
        ------------------------------------------------------------
        Checks whether the stack has reached its maximum capacity.
        Returns true if stack_top equals MAX_SIZE - 1, otherwise false.
    -------------------------------------------------------------*/
    bool full() const {
        return (stack_top == MAX_SIZE - 1);
    }

    /* ------------------------------------------------------------
        FUNCTION: int size() const
        ------------------------------------------------------------
        Returns the current number of elements in the stack.
        Since stack_top is the index of the top element, the size
        is simply stack_top + 1.
    -------------------------------------------------------------*/
    int size() const {
        return stack_top + 1;
    }

    /* ------------------------------------------------------------
        FUNCTION: int peek() const
        ------------------------------------------------------------
        Returns the data value of the top element in the stack
        without removing it. If the stack is empty, prints an
        error message and returns -1.
    -------------------------------------------------------------*/
    int peek() const {
        if (empty()) {
            cerr << "Stack is empty! Cannot peek.\n";
            return -1;
        }
        return arr[stack_top];
    }

    /* ------------------------------------------------------------
        FUNCTION: void push(int n)
        ------------------------------------------------------------
        Adds a new element 'n' to the top of the stack.
        1. Check if the stack is full.
        2. Increment stack_top.
        3. Store the new value at the new top position.
        This operation is O(1) - constant time.
    -------------------------------------------------------------*/
    void push(int n) {
        if (full()) {
            cerr << "Stack is full! Cannot push " << n << ".\n";
            return;
        }
        arr[++stack_top] = n;
        cout << "Pushed " << n << " onto the stack.\n";
    }

    /* ------------------------------------------------------------
        FUNCTION: int pop()
        ------------------------------------------------------------
        Removes the top element from the stack and returns its value.
        1. Check if the stack is empty.
        2. Store the value of the top element.
        3. Decrement stack_top to effectively remove the element.
        This operation is O(1) - constant time.
    -------------------------------------------------------------*/
    int pop() {
        if (empty()) {
            cerr << "Stack is empty! Cannot pop.\n";
            return -1;
        }
        return arr[stack_top--];
    }

    /* ------------------------------------------------------------
        FUNCTION: void display() const
        ------------------------------------------------------------
        Prints all elements of the stack from top to bottom.
        Shows the stack structure vertically for better visualization.
    -------------------------------------------------------------*/
    void display() const {
        if (empty()) {
            cout << "Stack is empty.\n";
            return;
        }

        cout << "Stack (top to bottom):\n";
        cout << "TOP\n";
        cout << " |\n";
        for (int i = stack_top; i >= 0; --i) {
            cout << " " << arr[i] << "\n";
            if (i > 0)
                cout << " |\n";
        }
        cout << "BOTTOM\n";
    }

    /* ------------------------------------------------------------
        FUNCTION: void clear()
        ------------------------------------------------------------
        Removes all elements from the stack, making it empty.
        Simply resets stack_top to -1. No need to actually clear
        the array since the elements will be overwritten.
    -------------------------------------------------------------*/
    void clear() {
        stack_top = -1;
        cout << "Stack cleared.\n";
    }

    /* ------------------------------------------------------------
        FUNCTION: int capacity() const
        ------------------------------------------------------------
        Returns the maximum capacity of the stack (MAX_SIZE).
    -------------------------------------------------------------*/
    int capacity() const {
        return MAX_SIZE;
    }
};

/* ===============================================================
    MAIN FUNCTION
    ----------------------------------------------------------------
    Demonstrates how all the stack functions work using an array
    implementation. It performs various operations such as push,
    pop, peek, and display while printing intermediate results
    for clarity.
==================================================================*/
int main() {
    StackArray stk;  // create a new empty stack

    cout << "=== Stack Operations Demo (Array Implementation) ===\n\n";

    cout << "Stack capacity: " << stk.capacity() << "\n";
    cout << "Checking if stack is empty: " << (stk.empty() ? "Yes" : "No") << "\n\n";

    cout << "Pushing elements 10, 20, 30, 40, 50 onto the stack:\n";
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);
    cout << "\n";

    stk.display();
    cout << "\nStack size: " << stk.size() << "\n";
    cout << "Is stack full? " << (stk.full() ? "Yes" : "No") << "\n\n";

    cout << "Peek at top element: " << stk.peek() << "\n\n";

    cout << "Popping element: " << stk.pop() << "\n";
    cout << "Popping element: " << stk.pop() << "\n\n";

    stk.display();
    cout << "\nStack size after popping: " << stk.size() << "\n\n";

    cout << "Pushing 60 and 70:\n";
    stk.push(60);
    stk.push(70);
    cout << "\n";

    stk.display();
    cout << "\n";

    cout << "Clearing the entire stack:\n";
    stk.clear();
    cout << "\n";

    cout << "Is stack empty now? " << (stk.empty() ? "Yes" : "No") << "\n\n";

    cout << "Attempting to pop from empty stack:\n";
    stk.pop();
    cout << "\n";

    cout << "Attempting to peek at empty stack:\n";
    stk.peek();
    cout << "\n";

    cout << "Testing stack overflow - pushing elements until full:\n";
    for (int i = 1; i <= 5; ++i) {
        stk.push(i * 10);
    }
    cout << "\nStack size: " << stk.size() << "\n";
    cout << "Program finished successfully.\n";

    return 0;
}
