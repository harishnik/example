#include <bits/stdc++.h>
using namespace std;
//adding sonething for local matchine
class node{
    public:
    int data;
    node* next;

    node(int val){    //constructor
        data = val;
        next = NULL;
    }

    ~node(){
        // cout<<"node->";
        if(next != NULL){
            delete next;
            next = NULL;
        }
    }
};

//using list creating linked list
class List{
    node* head;
    node* tail;

    public:
    List(){
        head = NULL;
        tail = NULL;
    }

    ~List(){
        // cout<<"list->";
        if(head != NULL){
            delete head;
            head = NULL;
        }
    }


    //push front function
    void push_front(int val){
        node* newnode = new node(val);

        if(head == NULL){
            head = tail = newnode;
        }
        else{
            newnode -> next = head;
            head = newnode;
        }
    }


    //create push back funtion
    void push_back(int val){
        node* newnode = new node(val);

        if(head == NULL){
            head = tail = newnode;
        }
        else{
            tail->next = newnode;
            tail = newnode;
        }
    }

    // create print function
    void printLL(){
        node* temp = head;

        while(temp != NULL){
            cout<<temp->data<<"->";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    void insert_position(int val, int pos){
        node* newnode = new node(val);

        node* temp = head;
        for(int i=0; i<pos-1; i++){
            temp = temp->next;
        }

        newnode->next = temp->next;
        temp->next = newnode;
    }

    void pop_front(){
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

   int searchItr(int key){
    node* temp = head;
    int idx=0;

    while(temp != NULL){
        if(temp->data == key){
            return idx;
        }

        temp = temp->next;
        idx++;
    }
    return -1;
   }

    int searchRch(int key){
        return helper(head, key);
    }
   int helper(node* head, int key){
        if(head == NULL){
            return -1;
        }

        if(head->data == key){
            return 0;
        }

        int idx = helper(head->next, key);
        if(idx == -1){
            return -1;
        }

        return idx+1;
    }

    void reverseLL(){
        node* curr = head;
        node* perv = NULL;
        node* next;
        tail = head; //optional

        while(curr != NULL){
            next = curr->next;
            curr->next=perv;

            perv = curr;
            curr = next;
        }
        head = perv;
    }

    int getsize(){
        node* temp = head;
        int sz=0;

        while(temp != NULL){
            temp = temp->next;
            sz++;
        }
        return sz;
    }

    void removeNth(int n){
        int size = getsize();
        node* temp = head;

        for(int i=1; i<(size-n); i++){
            temp = temp->next;
        }

        temp->next = temp->next->next;
    }

};

int main()
{
    List ll;  
    ll.push_front(10);
    ll.push_front(20);
    ll.push_front(30);
    ll.push_front(40);
    ll.push_front(50);
    ll.printLL();

    ll.removeNth(2);
    ll.printLL();
    return 0;
}
