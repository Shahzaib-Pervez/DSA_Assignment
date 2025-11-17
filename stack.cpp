#include <iostream>
using namespace std;

/* ===============================================================
   CLASS: Node
   ----------------------------------------------------------------
   Each Node object represents a single element (node) in the
   linked list. Every node contains two important pieces of data:
     1. An integer 'value' that stores the actual data of the node.
     2. A pointer 'next_node' which points to the next node in the
        linked list (or nullptr if it is the last node).
==================================================================*/
class Node {
private:
    int value;          // The data stored in the node
    Node* next_node;    // Pointer to the next node in the list

public:
    /* ------------------------------------------------------------
       CONSTRUCTOR: Node(int val = 0, Node* next = nullptr)
       ------------------------------------------------------------
       This constructor allows creating a node with a specified
       value and a pointer to the next node. Both parameters have
       default values, so calling "Node()" will create a node with
       value = 0 and next_node = nullptr.
    -------------------------------------------------------------*/
    Node(int val = 0, Node* next = nullptr)
        : value(val), next_node(next) {}

    /* ------------------------------------------------------------
       ACCESSOR: int retrieve() const
       ------------------------------------------------------------
       Returns the data value stored in the current node.
       Marked as 'const' since it doesn't modify the node.
    -------------------------------------------------------------*/
    int retrieve() const { return value; }

    /* ------------------------------------------------------------
       ACCESSOR: Node* next() const
       ------------------------------------------------------------
       Returns the address of the next node (the next pointer).
       Also marked as 'const' since it does not modify the object.
    -------------------------------------------------------------*/
    Node* next() const { return next_node; }

    /* ------------------------------------------------------------
       MUTATOR: void set_next(Node* next)
       ------------------------------------------------------------
       This function changes the link of the current node by
       setting its 'next_node' pointer to another node address.
       This allows updating connections between nodes dynamically.
    -------------------------------------------------------------*/
    void set_next(Node* next) { next_node = next; }

    // Friend class declaration:
    // Gives the 'List' class permission to access Node's private
    // data members (value and next_node) directly.
    friend class List;
    friend class Stack;
};

/* ===============================================================
   CLASS: List
   ----------------------------------------------------------------
   The List class represents a singly linked list. It manages
   a collection of Node objects using a single pointer 'list_head'
   that always points to the first node (head) of the list.
==================================================================*/
class List {
private:
    Node* list_head;  // Points to the first node in the list (nullptr if empty)

public:
    /* ------------------------------------------------------------
       CONSTRUCTOR: List()
       ------------------------------------------------------------
       Initializes the linked list to an empty state.
       'list_head' is set to nullptr to indicate there are no nodes.
    -------------------------------------------------------------*/
    List() : list_head(nullptr) {}

    /* ------------------------------------------------------------
       DESTRUCTOR: ~List()
       ------------------------------------------------------------
       The destructor ensures that all dynamically allocated memory
       used by nodes is properly freed before the list object is
       destroyed. It repeatedly calls pop_front() until the list is
       empty, deleting all nodes one by one.
    -------------------------------------------------------------*/
    ~List() {
        while (!empty())
            pop_front();  // delete first node repeatedly
    }

    /* ------------------------------------------------------------
       FUNCTION: bool empty() const
       ------------------------------------------------------------
       Checks whether the linked list has any nodes.
       Returns true if list_head is nullptr (no nodes), otherwise false.
    -------------------------------------------------------------*/
    bool empty() const {
        return (list_head == nullptr);
    }

    /* ------------------------------------------------------------
       FUNCTION: int size() const
       ------------------------------------------------------------
       Traverses the entire linked list and counts how many nodes exist.
       Uses a loop starting from the head node and follows the chain
       of next pointers until reaching nullptr.
    -------------------------------------------------------------*/
    int size() const {
        int count = 0;
        for (Node* ptr = list_head; ptr != nullptr; ptr = ptr->next())
            ++count;
        return count;
    }

    /* ------------------------------------------------------------
       FUNCTION: int front() const
       ------------------------------------------------------------
       Returns the data value of the first node (head) in the list.
       If the list is empty, prints an error message and returns -1.
    -------------------------------------------------------------*/
    int front() const {
        if (empty()) {
            cerr << "List is empty! Cannot access front element.\n";
            return -1;
        }
        return list_head->retrieve();
    }

    /* ------------------------------------------------------------
       FUNCTION: void push_front(int n)
       ------------------------------------------------------------
       Inserts a new node containing 'n' at the beginning of the list.
       1. Create a new node whose next pointer points to the current head.
       2. Update 'list_head' to point to the new node.
    -------------------------------------------------------------*/
    void push_front(int n) {
        Node* new_node = new Node(n, list_head);
        list_head = new_node;
    }

    /* ------------------------------------------------------------
       FUNCTION: int pop_front()
       ------------------------------------------------------------
       Removes the first node from the list and returns its value.
       1. Check if the list is empty.
       2. Store the value of the first node.
       3. Move the head pointer to the second node.
       4. Delete the first node to free memory.
    -------------------------------------------------------------*/
    int pop_front() {
        if (empty()) {
            cerr << "List is empty! Cannot pop front.\n";
            return -1;
        }

        int value = list_head->retrieve();
        Node* temp = list_head;
        list_head = list_head->next();
        delete temp;
        return value;
    }

    /* ------------------------------------------------------------
       FUNCTION: void display() const
       ------------------------------------------------------------
       Prints all elements of the linked list in sequence.
       Displays each node's data followed by "->", ending with "nullptr".
    -------------------------------------------------------------*/
    void display() const {
        if (empty()) {
            cout << "List is empty.\n";
            return;
        }

        for (Node* ptr = list_head; ptr != nullptr; ptr = ptr->next())
            cout << ptr->retrieve() << " -> ";
        cout << "nullptr\n";
    }

    // Friend class declaration
    friend class Stack;
};

/* ===============================================================
    CLASS: Stack
    ----------------------------------------------------------------
    The Stack class represents a stack data structure implemented
    using the existing List class (singly linked list). It follows
    the LIFO (Last In First Out) principle by utilizing the list's
    push_front() and pop_front() operations.
     - push() adds elements to the top (uses l.push_front)
     - pop() removes elements from the top (uses l.pop_front)
     - peek() views the top element (uses l.front)
    
    This demonstrates code reusability by leveraging the already
    implemented linked list functionality instead of rewriting it.
==================================================================*/
class Stack {
private:
    List l;  // Internal linked list to store stack elements

public:
    /* ------------------------------------------------------------
        CONSTRUCTOR: Stack()
        ------------------------------------------------------------
        Initializes the stack to an empty state by using the
        List class's default constructor.
    -------------------------------------------------------------*/
    Stack() {}

    /* ------------------------------------------------------------
        FUNCTION: bool empty() const
        ------------------------------------------------------------
        Checks whether the stack has any elements by delegating
        to the List class's empty() function.
    -------------------------------------------------------------*/
    bool empty() const {
        return l.empty();
    }

    /* ------------------------------------------------------------
        FUNCTION: int size() const
        ------------------------------------------------------------
        Returns the number of elements in the stack by delegating
        to the List class's size() function.
    -------------------------------------------------------------*/
    int size() const {
        return l.size();
    }

    /* ------------------------------------------------------------
        FUNCTION: int peek() const
        ------------------------------------------------------------
        Returns the data value of the top element in the stack
        without removing it. Uses l.front() since the top of
        the stack is the front of the list.
    -------------------------------------------------------------*/
    int peek() const {
        if (empty()) {
            cerr << "Stack is empty! Cannot peek.\n";
            return -1;
        }
        return l.front();
    }

    /* ------------------------------------------------------------
        FUNCTION: void push(int n)
        ------------------------------------------------------------
        Adds a new element 'n' to the top of the stack.
        Uses l.push_front() since adding to the front of the
        list is equivalent to pushing onto a stack.
        This operation is O(1) - constant time.
    -------------------------------------------------------------*/
    void push(int n) {
        l.push_front(n);
        cout << "Pushed " << n << " onto the stack.\n";
    }

    /* ------------------------------------------------------------
        FUNCTION: int pop()
        ------------------------------------------------------------
        Removes the top element from the stack and returns its value.
        Uses l.pop_front() since removing from the front of the
        list is equivalent to popping from a stack.
        This operation is O(1) - constant time.
    -------------------------------------------------------------*/
    int pop() {
        if (empty()) {
            cerr << "Stack is empty! Cannot pop.\n";
            return -1;
        }
        return l.pop_front();
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
        
        // Access the list's internal structure to display vertically
        Node* ptr = l.list_head;
        while (ptr != nullptr) {
            cout << " " << ptr->retrieve() << "\n";
            if (ptr->next() != nullptr)
                cout << " |\n";
            ptr = ptr->next();
        }
        cout << "BOTTOM\n";
    }

    /* ------------------------------------------------------------
        FUNCTION: void clear()
        ------------------------------------------------------------
        Removes all elements from the stack, making it empty.
        Repeatedly calls pop() until no elements remain.
    -------------------------------------------------------------*/
    void clear() {
        while (!empty())
            pop();
        cout << "Stack cleared.\n";
    }
};

/* ===============================================================
    MAIN FUNCTION
    ----------------------------------------------------------------
    Demonstrates how all the stack functions work using a linked
    list implementation. It performs various operations such as
    push, pop, peek, and display while printing intermediate
    results for clarity.
==================================================================*/
int main() {
    Stack stk;  // create a new empty stack

    cout << "=== Stack Operations Demo (Linked List Implementation) ===\n\n";

    cout << "Checking if stack is empty: " << (stk.empty() ? "Yes" : "No") << "\n\n";

    cout << "Pushing elements 10, 20, 30, 40, 50 onto the stack:\n";
    stk.push(10);
    stk.push(20);
    stk.push(30);
    stk.push(40);
    stk.push(50);
    cout << "\n";

    stk.display();
    cout << "\nStack size: " << stk.size() << "\n\n";

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

    cout << "Program finished successfully.\n";

    return 0;
}
