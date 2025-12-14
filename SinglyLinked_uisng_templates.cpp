#include <iostream>
using namespace std;

template <typename T>
class node {
private:
    node<T>* next_node;
    T elem;

public:
    node() : next_node(nullptr), elem(T()) {}
    node(T val, node<T>* next = nullptr) : next_node(next), elem(val) {}

    T retrieve() {
        return elem;
    }

    node<T>* next() {
        return next_node;
    }

    void set_next(node<T>* next) {
        next_node = next;
    }
};

template <typename T>
class list {
private:
    node<T>* list_head;

public:
    list() : list_head(nullptr) {}

    bool empty() {
        return (list_head == nullptr);
    }

    node<T>* head() {
        return list_head;
    }

    void display() {
        for (node<T>* ptr = head(); ptr != nullptr; ptr = ptr->next()) {
            cout << " " << ptr->retrieve();
        }
        cout << endl;
    }

    void push_front(T val) {
        list_head = new node<T>(val, head());
    }

    void push_end(T val) {
        node<T>* newN = new node<T>(val, nullptr);
        if (empty()) {
            list_head = newN;
            return;
        }
        node<T>* temp = head();
        while (temp->next() != nullptr) {
            temp = temp->next();
        }
        temp->set_next(newN);
    }

    void push_mid(T val) {
        node<T>* newNode = new node<T>(val, nullptr);
        if (empty()) {
            list_head = newNode;
            return;
        }
        node<T>* slow = head();
        node<T>* fast = head();
        while (fast->next() != nullptr && fast->next()->next() != nullptr) {
            slow = slow->next();
            fast = fast->next()->next();
        }
        node<T>* temp = slow->next();
        slow->set_next(newNode);
        newNode->set_next(temp);
    }

    void insert_at(T val, int pos) {
        node<T>* newN = new node<T>(val, nullptr);
        if (empty()) {
            list_head = newN;
            return;
        }
        if (pos <= 0) {
            push_front(val);
            return;
        }

        node<T>* temp = head();
        int index = 0;
        while (temp->next() != nullptr && index < pos - 1) {
            temp = temp->next();
            index++;
        }
        newN->set_next(temp->next());
        temp->set_next(newN);
    }

    void pop_front() {
        if (empty()) return;
        node<T>* temp = head();
        list_head = list_head->next();
        delete temp;
    }

    void pop_end() {
        if (empty()) return;

        if (head()->next() == nullptr) {
            delete list_head;
            list_head = nullptr;
            return;
        }

        node<T>* temp = head()->next();
        node<T>* prev = head();
        while (temp->next() != nullptr) {
            prev = prev->next();
            temp = temp->next();
        }
        delete prev->next();
        prev->set_next(nullptr);
    }

    void pop_mid() {
        if (empty()) return;

        if (list_head->next() == nullptr) {
            delete list_head;
            list_head = nullptr;
            return;
        }

        node<T>* prev = nullptr;
        node<T>* slow = head();
        node<T>* fast = head();

        while (fast->next() != nullptr && fast->next()->next() != nullptr) {
            prev = slow;
            slow = slow->next();
            fast = fast->next()->next();
        }

        prev->set_next(slow->next());
        delete slow;
    }

    int size() {
        int count = 0;
        for (node<T>* ptr = head(); ptr != nullptr; ptr = ptr->next()) {
            ++count;
        }
        return count;
    }

    void pop_at(int pos) {
        if (empty()) return;

        if (pos <= 0) {
            pop_front();
            return;
        }
        if (pos >= size()) {
            pop_end();
            return;
        }

        node<T>* temp = head();
        int index = 0;
        while (temp->next() != nullptr && index < pos - 1) {
            temp = temp->next();
            ++index;
        }

        node<T>* current = temp->next();
        temp->set_next(current->next());
        delete current;
    }

    int erase(T val) {
        int count = 0;
        while (head() != nullptr && head()->retrieve() == val) {
            pop_front();
            ++count;
        }

        if (empty()) return count;

        node<T>* temp = head();
        while (temp->next() != nullptr) {
            if (temp->next()->retrieve() == val) {
                node<T>* current = temp->next();
                temp->set_next(current->next());
                delete current;
                ++count;
            }
            else {
                temp = temp->next();
            }
        }
        return count;
    }
};

int main() {
    list<int> ls;

    ls.push_front(10);
    ls.push_end(20);
    ls.push_mid(15);
    ls.insert_at(25, 3);

    ls.display();

    ls.erase(15);
    ls.pop_front();
    ls.pop_end();

    ls.display();

    return 0;
}
