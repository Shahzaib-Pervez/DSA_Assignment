#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
};

template <typename T>
class Stack {
    Node<T>* top;
public:
    Stack() : top(nullptr) {}

    void push(T val) {
        Node<T>* n = new Node<T>(val);
        n->next = top;
        top = n;
    }

    void pop() {
        if (!top) return;
        Node<T>* t = top;
        top = top->next;
        delete t;
    }

    T peek() {
        if (!top) throw runtime_error("Stack Empty");
        return top->data;
    }

    void display() {
        Node<T>* temp = top;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    Stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.display();
    cout << "Top: " << s.peek() << endl;
    s.pop();
    s.display();
    return 0;
}
