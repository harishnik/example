
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }

};


class List{
    public:
    Node* head;
    Node* tail;

    List(){
        head = NULL;
        tail = NULL;
    }

    void push_front(int val){
        Node* temp = new Node(val);  //new operator used to create daynamic memoriy
        
        

        if(head == NULL){
            head = tail = temp;
        }
        else{
            temp->next = head;
            head = temp;
        }
    }

    void push_back(int val){
        Node* newnode = new Node(val);

        if(head == NULL){
            head = tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
    }

    void ll_print(){
        Node* temp = head;

        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }

        cout<<"Null"<<endl;

    }
};


bool cycle_LL(Node* head){
    Node* slow = head;
    Node* fast = head;
    
    while(fast != NULL && fast->next->next != NULL){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){
            cout<<"cycle exist";
            return true;
        }
    }
    cout<<"cycle doesn't exist";
    return false;
}

bool detect_cycle(Node*){

}
int main(){

    List ll;
    ll.push_front(40);
    ll.push_front(30);
    ll.push_front(20);
    ll.push_front(10);
    ll.ll_print();

    
    cycle_LL(ll.head);
    return 0;
}