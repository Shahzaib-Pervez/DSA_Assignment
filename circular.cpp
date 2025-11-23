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
    node* head;
    node* tail;
    int sz;
    public:
    list():head(nullptr), tail(nullptr), sz(0){}
    bool empty(){
        return(head==nullptr);
    }
    void display(){
        node* ptr = head;
        do{
            cout<<ptr->retrieve()<<"  ";
            ptr= ptr->next();
        }while(ptr!=head);
    }
    void push_front(int val){
        node* newN = new node(val);
        if(empty()){
            head = tail = newN;
            tail->set_next(head);
            ++sz;
            return;
        }
        else{
            newN->set_next(head);
            head = newN;
            tail->set_next(head);
            ++sz;
            return;
        }
    }
    void push_back(int val){
        node* newN = new node(val);
        if(empty()){
            head = tail = newN;
            tail->set_next(head);
            ++sz;
            return;
        }
        tail->set_next(newN);
        tail=newN;
        tail->set_next(head);
        ++sz;
        return;
    }
    void push_mid(int val){
        node* newN = new node(val);
        if(empty()){
            head = tail = newN;
            tail->set_next(head);
            ++sz;
            return;
        }
        int mid = sz/2;
        if(mid == 0){
            push_front(val);
            return;
        }
        if(mid == sz){
            push_back(val);
            return;
        }
        int index = 0;
        node* temp = head;
        while(temp->next()!=head&&index<mid-1){
            temp = temp->next();
            ++index;
        }
        node* current = temp->next();
        temp->set_next(newN);
        newN->set_next(current);
        ++sz;
    }
    void insert_at(int pos, int val){
        node* newN = new node(val);
        if(empty()){
            head = tail = newN;
            tail->set_next(head);
            ++sz;
            return;
        }
        if(pos<1){
            push_front(val);
            return;
        }
        if(pos>=sz){
            push_back(val);
            return;
        }
        node* temp = head;
        int index = 0;
        while(temp->next()!=head && index<pos-1){
            temp= temp->next();
            ++index;
        }
        node* current = temp->next();
        temp->set_next(newN);
        newN->set_next(current);
        ++sz;
    }
    void pop_front(){
        if(empty()){
            return;
        }
        if(head == tail){
            delete head;
            head = tail = nullptr;
        }
        node* temp = head ;
        head = head->next();
        delete temp;
        tail->set_next(head);
        --sz;
    }
    void pop_end(){
        if(empty()){
            return;
        }
        if(head == tail){
            delete tail;
            head = tail = nullptr;
        }
        node* temp = head ;

        while(temp->next()!=tail){
            temp=temp->next();
        }
        node*  current =temp->next();
        temp->set_next(head);
        tail=temp;
        delete current;
        --sz;
    }
    int pop_mid(){
        if (empty()){
            return 0;
        }
        if(head == tail){
            int val= tail ->retrieve();
            delete head;
            head = tail = nullptr;
            sz=0;
            return val;
        }
        else{
        node* temp=head;
        int mid = (sz/2)-1;
        if(mid==0){
            int val = head->retrieve();
            pop_front();
            return val;
        }
        else if(mid==sz-1){
            int val = tail->retrieve();
            pop_end();
            return val;
        }
        else{
        int index =0;
        while(temp->next()!=head && index<mid-1){
            temp= temp->next();
            ++index;
        }
        int val = temp->next()->retrieve();
        node* current = temp->next();
        temp->set_next(current->next());
        delete current;
        --sz;
        return val;
        }
    }
    }
    int erase(int val){
        int count=0;

        if(empty()){
            return 0;
        }
        while(head!=nullptr && head->retrieve()== val){
            pop_front();
            ++count;
        }
        while(tail->retrieve()==val){
            pop_end();
            ++count;
        }
        node* temp = head;
        while(temp->next()!=head){
            if(temp->next()->retrieve()==val){
                node* toDel = temp->next();
                temp->set_next(toDel->next());
                delete toDel;
                --sz;
                ++count;
            }
            else{
                temp= temp->next();
            }

        }
        return count;
    }
    int pop_at(int pos){
        if(empty()){
            return 0;
        }
        if(pos<=0){
            int val = head->retrieve();
            pop_front();
            return val;
        }
        if(pos>=sz-1){
            int val = tail->retrieve();
            pop_end();
            return val;
        }
        node* temp = head;
        int index =0;
        while(temp->next()!=nullptr && index<pos-1){
            temp= temp->next();
            ++index;
        }
        int val = temp->next()->retrieve();
        node* current = temp->next();
        temp->set_next(current->next());
        delete current;
        --sz;
        return val;
    }
};
int main(){
    list ls;
    ls.push_front(30);
    ls.push_front(32);
    ls.push_back(31);
    ls.push_mid(56);
    ls.push_mid(57);
    ls.push_mid(58);
    ls.insert_at(0,18);
    ls.pop_front();
    ls.pop_end();
    ls.push_mid(45);
    ls.pop_mid();
    ls.erase(31);
    ls.pop_at(1);
    ls.display();
}
