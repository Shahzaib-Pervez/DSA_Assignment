#include <iostream>
using namespace std;

template <typename T>
class Node {
public:
    T data;
    Node* next;
    Node(T val) : data(val), next(nullptr) {}
};

int main() {
    Node<int>* n1 = new Node<int>(10);
    Node<int>* n2 = new Node<int>(20);
    n1->next = n2;

    cout << n1->data << " -> " << n1->next->data << endl;

    delete n1;
    delete n2;
    return 0;
}
