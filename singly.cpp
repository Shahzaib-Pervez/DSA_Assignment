#include <iostream>
using namespace std;
class node{
    private:
    node* next_node;
    int elem;
    public:
    node():next_node(nullptr), elem(0){}
    node(int val , node* next=nullptr): next_node(next), elem(val){}
    int retrieve(){
        return elem;
    }
    node* next(){
        return next_node;
    }
    void set_next(node* next){
        next_node = next;
    }
    };
    class list{
        private:
        node* list_head;
        public:
        bool empty(){
            return (list_head == nullptr);
        }
        node* head(){
            return list_head;
        }
        void display(){
            for(node* ptr = head();ptr!= nullptr; ptr=ptr->next()){
                cout<<"  "<< ptr->retrieve();
            }
        }
        void push_front(int val){
            list_head = new node(val, head());
        }
        void push_end(int val){
            node* newN = new node(val,nullptr);
            if(empty()){
                list_head= newN;
                return;
            }
            node* temp = head();
            while(temp->next()!=nullptr){
                temp = temp->next();
            }
            temp->set_next(newN);
        }
        void push_mid(int val){
            node* newNode = new node(val,nullptr);
            if(empty()){
                list_head=newNode;
                return;
            }
            node* slow = head();
            node* fast = head();
            while(fast->next()!=nullptr && fast->next()->next()!=nullptr){
                slow = slow->next();
                fast = fast->next()->next();
            }
            node* temp = slow->next();
            slow->set_next(newNode);
            newNode->set_next(temp);

        }
        void insert_at(int val, int pos){
            node* newN=new node(val, nullptr);
            if(empty()){
                list_head=newN;
                return;
            }
            if(pos<0){
                pos=0;
            }
            node* temp = head();
            int index = 0;
            while((temp->next()!=nullptr)&& index<pos-1){
                temp = temp -> next();
                index++;
            }

            newN->set_next(temp->next());
            temp->set_next(newN);
        }
        
        void pop_front(){
            if(empty()){
                return;
            }
            node* temp = head();
            list_head=list_head->next();
            delete temp;
        }
        void pop_end(){
            if(empty()){
                return;
            }
            if(head()->next()==nullptr){
                delete list_head;
                list_head =nullptr;
                return;
            }
            node* temp = head()->next();
            node* prev = head();
            while(temp->next()!=nullptr){
                prev= prev->next();
                temp = temp->next();
            }
            delete prev->next();
            prev->set_next(nullptr);
        }
        void pop_mid(){
            if(empty()){
                return;
            }
            if(list_head->next()==nullptr){
                delete head();
                list_head=nullptr;
            }
            node* prev = nullptr;
            node* fast = head();
            node * slow = head();
            while((fast->next()!= nullptr) && (fast->next()->next()!= nullptr)){
                prev = slow;
                slow= slow->next();
                fast= fast->next()->next();
            }
            node* temp = slow;
            prev->set_next(temp->next());
            delete temp;
        }

        void pop_at(int pos){
            if(empty()){
                return;
            }
            if(pos<=0){
                pos=0;
                pop_front();
                return;
            }
            if(pos>=size()){
                pop_end();
                return;
            }
            node* temp = head();
            int index = 0;
            while((temp->next()!=nullptr)&&(index<pos-1)){
                temp = temp->next();
                ++index;
            }
            node* current = temp->next();
            temp->set_next(current->next());
            delete current;

        }
        int size(){
            int count = 0;
            for(node* ptr = head (); ptr!=nullptr; ptr= ptr->next()){
                ++count;
            }
            return count;
        }
        int erase(int val){
            int count=0;
            if(empty()){
                return 0;
            }
            while((head()!=nullptr)&&(head()->retrieve()==val)){
                pop_front();
                ++count;
            }
            node* temp = head();
            while(temp->next()!=nullptr){
                if(temp->next()->retrieve()==val){
                    node* current = temp->next();
                    temp->set_next(current->next());
                    delete current;
                    ++count;
                }
                else{
                    temp=temp->next();
                }
            }
            return  count;
        }
    };

    int main(){
        list ls;
        // ls.push_front(65);
        // ls.push_end(66);
        // ls.push_mid(68);
        // ls.push_end(69);
        // ls.insert_at(67,3);
        // // ls.pop_front();
        // // ls.pop_at(2);
        // // ls.erase(68);
        // // ls.erase(634);
        // ls.erase(68);
        ls.push(5);

        // ls.reverse();
        ls.display();
    }
