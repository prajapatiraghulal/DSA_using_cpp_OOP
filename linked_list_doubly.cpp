#include<iostream>
using namespace std;

class Node{
    public:
        int key;
        int value;
        Node* prev;
        Node* next;
        
        Node(int k, int v){
            key= k;
            value= v;
            prev=NULL;
            next=NULL;
        }
};

class MyDoublyLinkedList{
    public:
    Node *head;

    MyDoublyLinkedList(Node *n){
        head = n;
    }

    void insert_at_start(int k, int v){
        Node *keyNode= key_search(k);
        if(keyNode){
            keyNode->value=v;
        }
        else{
            Node *temp = new Node(k,v);
            temp->next= head;
            head->prev = temp;
            head= temp;
        }
    }
    Node* key_search(int k){
        Node *ptr = head;
        while(ptr!=NULL){
            if(ptr->key==k){
                return ptr;
            }
            ptr=ptr->next;
        }
        return NULL;
    }

    void insert_at_rear(int k, int v){
        Node *keyNode = key_search(k);
        if(keyNode){
            keyNode->value=v;
        }
        else{
            Node *ptr = head;
            Node *temp = new Node(k,v);
            while(ptr->next!=NULL){
                ptr = ptr->next;
            }
            ptr->next = temp;
            temp->prev = ptr;

        }

    }

    Node* delete_from_start(){
        Node *temp = head;
        head = head->next;
        head->prev=NULL;
        return temp;

    }
    
    Node* delete_from_rear(){
        Node *ptr =head;
        while(ptr->next!=NULL){
            ptr= ptr->next;
        }
        ptr->prev->next = NULL;
        ptr->prev = NULL;
        return ptr;

    }

    void remove_element(int k){
        cout<<key_search(k)->key<<'\n';
    }
    void add_element_at(int k){

    }
    void display(){
        Node *ptr = head;
        while(ptr!=NULL){
            cout<<ptr->key<<"\t"<<ptr->value<<'\n';
            ptr = ptr->next;
        }
        cout<<"\n";
    }

};

int main(){
    Node n1(1,10);
    MyDoublyLinkedList d1(&n1);
    d1.insert_at_start(2,20);
    d1.insert_at_rear(3,30);
    d1.display();
    d1.delete_from_start();
    d1.display();
    d1.remove_element(1);

    return 0;
}