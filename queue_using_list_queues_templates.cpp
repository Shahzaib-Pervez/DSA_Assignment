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
class Queue {
    Node<T>* front;
    Node<T>* rear;
public:
    Queue() : front(nullptr), rear(nullptr) {}

    void enqueue(T val) {
        Node<T>* n = new Node<T>(val);
        if (!rear) {
            front = rear = n;
            return;
        }
        rear->next = n;
        rear = n;
    }

    void dequeue() {
        if (!front) return;
        Node<T>* t = front;
        front = front->next;
        if (!front) rear = nullptr;
        delete t;
    }

    T peek() {
        if (!front) throw runtime_error("Queue Empty");
        return front->data;
    }

    void display() {
        Node<T>* temp = front;
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};

int main() {
    Queue<string> q;
    q.enqueue("Apple");
    q.enqueue("Banana");
    q.enqueue("Mango");
    q.display();
    cout << "Front: " << q.peek() << endl;
    q.dequeue();
    q.display();
    return 0;
}
