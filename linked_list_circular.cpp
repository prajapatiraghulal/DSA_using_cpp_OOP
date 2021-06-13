#include<iostream>
using namespace std;

class Node{
    public:
    int key;
    int value;
    Node *next;

    Node(int k, int v){
        key = k;
        value = v;
        next=nullptr;
    }

};

class MyCircularLinkedList{
    public:
    Node* head;
    Node* tail;

    MyCircularLinkedList(Node *n){
        head = n;
        head->next=head;
        tail = n;
    }

    void append(int k, int v){
        Node *temp = new Node(k,v);
        if(head){
            tail->next = temp;
            temp->next=head;
            tail = temp;
        }
        else if(head==NULL){
            head=tail = temp;
            tail->next = head;
        }
    }
    void prepend(int k, int v){
        Node *temp = new Node(k,v);
        if(head){
            tail->next = temp;
            temp->next = head;
            head = temp;
        }
        else if(head==NULL){
            head = temp;
            tail = temp;
            tail->next=head;
        }
    }

    Node* pop_front(){
        Node *temp = head;
        if(head!=nullptr & tail!=head){
            head= head->next;
            tail->next = head;
            
        }
        else if(head==tail){
            head = tail = NULL;

            
        }
        temp->next=NULL;
        return temp;
        
    }
    Node* pop_rear(){
        Node *temp = tail;
        Node* ptr = head;
        if(tail!=NULL && head->next!=head){
            while(ptr->next!=tail){
                ptr= ptr->next;
            }
            tail = ptr;
            tail->next = head;
        
        }
        else if(tail==NULL){
            throw(-1);
            }
        else if(head->next==head){
            head = tail = NULL;
            
            }
        temp->next = nullptr;
        return temp;
    }
    
    void add_after(int sk,int k, int v){
        Node *temp=head;
        Node *ptr = new Node(k,v); 
        if(head){
            while(temp->next!=head && temp->key!=sk)
                temp=temp->next;
            if(temp->key==sk){
                ptr->next= temp->next;
                temp->next = ptr;
                if(temp==tail){
                    tail = ptr;
                }
            }
            else{
                throw(-1);
            }
        }
        else{
            throw(-2);
        }
    }

    void display(){
        Node *temp = head;
        if(head){
            while(temp->next!=head){
                cout<<temp->key<<"\t"<<temp->value<<endl;
                temp = temp->next;
            }
            cout<<temp->key<<"\t"<<temp->value<<endl;
        }
        else{
            cout<<"empty list \n";
        }
    }
};


int main(){
    Node n1(1,10);
    MyCircularLinkedList c1(&n1);
    c1.add_after(1,100,100);
    c1.display();
    cout<<endl;
    c1.append(2,20);
    c1.prepend(3,30);
    c1.append(4,40);
    c1.append(5,50);
    c1.prepend(6,60);
    c1.append(10,100);
    
    cout<<c1.pop_front()->key<<"\n";
    cout<<c1.pop_rear()->key<<"\n";
    c1.display();
    cout<<"\n";
    cout<<c1.pop_front()->key<<"\n";
    c1.add_after(2,200,200);
    c1.display();



    return 0;
}