#include <iostream>
using namespace std;
class node{
    private:
    node* next_node;
    node* prev_node;
    int elem;
    public:
    node(): elem(0),prev_node(nullptr), next_node(nullptr){}
    node(int val, node* prev=nullptr, node* next=nullptr):next_node(next), elem(val), prev_node(prev){}
    int retrieve(){
        return elem;
    }
    node* prev(){
        return prev_node;
    }
    node* next(){
        return next_node;
    }
    void set_next(node* next){
        next_node=next;
    }
    void set_prev(node* prev){
        prev_node=prev;
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
    void push_front(int val){
        node* newN= new node(val);
        if(empty()){
            head = tail = newN;
            ++sz;
        }
        else{
            node* temp = head;
            newN->set_next(temp);
            temp->set_prev(newN);
            head = newN;
            head->set_prev(nullptr);
            ++sz;
        }
    }
    void push_back(int val){
        node* newN = new node(val);
        if(empty()){
            head = tail = newN;
            ++sz;
        }
        else{
            node* temp= tail;
            tail->set_next(newN);
            newN->set_prev(tail);
            tail=newN;
            tail->set_next(nullptr);
            ++sz;
        }
    }
    void push_mid(int val){
        node* newN = new node(val);
        if (empty()){
            head = tail = newN;
            ++sz;
        }
        else{
            
            int mid= (sz/2);
            if(mid==0){
                push_front(val);
            }
            else if(mid ==sz){
                push_back(val);
            }
            int index = 0;
            node* temp = head;

            while((temp->next()!=nullptr) && index < mid-1){
                temp = temp -> next();
                ++index;
            }
            node* current = temp->next();
            current->set_prev(newN);
            temp->set_next(newN);
            newN->set_next(current);
            newN->set_prev(temp);
            ++sz;
        }
    }
    void insert_at(int pos, int val){
        node* newN = new node(val);
        if(empty()){
            pos=0;
            head=tail=newN;
            ++sz;
        }
        else{
            if((pos<=0)&& (!empty())){
                pos=0;
                push_front(val);
                return;
            }
            if(pos>=sz){
                newN->set_prev(tail);
                tail->set_next(newN);
                tail = newN;
                tail->set_next(nullptr);
                ++sz;
                return;
            }
            int index=0;
            node* temp = head;
            while((temp->next()!=nullptr)&&index<pos-1){
                temp = temp->next();
                ++index;
            }
            node* current = temp->next();
            current->set_prev(newN);
            temp->set_next(newN);
            newN->set_next(current);
            newN->set_prev(temp);
            ++sz;
        }
    }
    int pop_front(){
        if(empty()){
            return 0;
        }
        if(head ==tail){
            head = tail = nullptr;
            sz=0;
            return 0;
        }
        int val= head ->retrieve();
        node* temp = head;
        head = head ->next();
        head->set_prev(nullptr);
        delete temp;
        --sz;
        return val;
    }
    int pop_end(){
        if(empty()){
            return 0;
        }
        if(head == tail){
            int val= tail ->retrieve();
            head = tail = nullptr;
            sz=0;
            return val;
        }
        else{
            int val= tail ->retrieve();
            node* temp = tail;
            tail = tail ->prev();
            tail->set_next(nullptr);
            delete temp;
            --sz;
            return val;

        }
    }
    int pop_mid(){
        if (empty()){
            return 0;
        }
        if(head == tail){
            int val= tail ->retrieve();
            head = tail = nullptr;
            sz=0;
            return val;
        }
        else{
        node* temp=head;
        int mid = sz/2;
        if(mid==0){
            pop_front();
        }
        else if(mid==sz-1){
            pop_end();
        }
        else{
        int index =0;
        while(temp->next()!=nullptr && index<mid-1){
            temp= temp->next();
            ++index;
        }
        int val = temp->next()->retrieve();
        node* current = temp->next();
        current->next()->set_prev(temp);
        temp->set_next(current->next());
        delete current;
        --sz;
        return val;
        }
    }
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
        current->next()->set_prev(temp);
        temp->set_next(current->next());
        delete current;
        --sz;
        return val;
    }
    int erase(int val){
        if(empty()){
            return 0;
        }
        int count =0;
        while((head!=nullptr)&& head->retrieve()==val){
            pop_front();
            ++count;
        }
         if (head == nullptr) {
        tail = nullptr;
        return count;
    }
        while( tail!= nullptr && tail->retrieve()==val){
            pop_end();
            ++count;
        }
        node* temp = head;
        while(temp->next()!=nullptr){
            if(temp->next()->retrieve()==val){
                node* current = temp->next();
                if (current->next() != nullptr){
                current->next()->set_prev(temp);}
                temp->set_next(current->next());
                delete current;
                --sz;
                ++count;
            }
            else{
                temp= temp->next();
            }
        }
        if (head == nullptr) {
        tail = nullptr;
        return count;
        }
        else{
            node* t = head;
            while(t->next()!=nullptr){
                t=t->next();
            }
            tail = t;
            return count;
        }
    }
        void display(){
            
           for(node* ptr = head;ptr!=nullptr;ptr=ptr->next()){
                cout<<ptr->retrieve()<<"  ";
           }
        }
       
 };

    int main(){
        list ls;
        ls.push_front(13);
        ls.push_front(13);
        ls.push_back(13);
        ls.push_back(13);
        ls.push_mid(13);
        ls.push_mid(13);
        ls.push_mid(13);
        ls.insert_at(7, 12);
        // int result = ls.pop_front();
        // int r = ls.pop_end();
        // int e = ls.pop_mid();
        
        // int o=ls.pop_at(2);
        // int p=ls.pop_at(9);
        // int q=ls.pop_at(-23132);
        
        int c= ls.erase(13);
        cout<<" "<<c<<endl;
        // ls.insert_at(9,33);
        ls.display();
       
    }


        return;
    }
    cout<<arr[i];
    print(arr, n, i+1);
}
