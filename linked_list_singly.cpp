#include<iostream>
using namespace std;

class Node{
    public:
    int key;
    int value;
    Node *next;

    Node(int k, int v){
        key=k;
        value=v;
        next= NULL;
    }

};

class MyLinkedList{
    public:
    Node *head=NULL;

    MyLinkedList(Node * node){
        head = node;
    }
    void append(int k, int v){
        Node *keyNode = keycheck(k);
        if(keyNode){
            keyNode->value=v;
        }
        else{
            Node *temp = new Node(k,v);
            if(head->next==NULL){
                head->next = temp;
            }
            else{
                Node *ptr= head;
                while(ptr->next!=NULL){
                    ptr=ptr->next;
                }
                ptr->next= temp;
            }
        }
    }


    void prepend(int k, int v){
        Node *keyNode = keycheck(k);
        if(keyNode){
            keyNode->value=v;
        }
        else{
            Node *temp = new Node(k,v);
            temp->next=head;
            head=temp;
        }
    }

    Node* keycheck(int k){
        Node *ptr = nullptr;
        ptr=head;
        while(ptr!=NULL){
            if(ptr->key==k){
                return ptr;
            }
            ptr=ptr->next;
        }
        return NULL;
    }

    void display(){
        Node *ptr = head;
        while(ptr!=NULL){
            cout<<ptr->key<<"\t"<<ptr->value<<endl;
            ptr=ptr->next;
        }
    }

    Node* pop_from_start(){
        Node *temp =NULL;
        temp = head;
        head=head->next;
        return temp;

    }

    Node* pop_from_rear(){
        Node *ptr= head;
        while(ptr->next->next!=NULL){
            ptr=ptr->next;
        }
        Node *temp = ptr->next;
        ptr->next=NULL;
        return temp;
    }

    Node* remove_element(int k){
        Node *ptr = head;
        if(head->key==k){
            head=head->next;
        }
        else{
            while(ptr->next!=NULL){
                if(ptr->next->key == k){
                    break;
                }  
            }
            if(ptr->next==NULL){
                return NULL;
            }
            Node *temp =ptr->next;
            ptr->next = ptr->next->next;
            return temp;
        }
    }
};

int main(){
    Node n1(1,10);
    

    MyLinkedList l1(&n1);
    l1.append(2,20);
    l1.append(3,30);
    l1.append(2,100);
    l1.prepend(4,40);
    l1.display();
    cout<<l1.pop_from_start()->value<<"\n";
    cout<<l1.pop_from_rear()->value<<"\n";
    cout<<l1.remove_element(2)->key<<"\n";
    l1.display();
    return 0;
}
