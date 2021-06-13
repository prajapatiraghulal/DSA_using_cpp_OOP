#include<iostream>
using namespace std;
class BST;
class Node;

enum class option: char{
    preorder,
    postorder,
    inorder
}op;

class Node{
    int value;
    Node *left;
    Node *right;
    friend class BST;
    public:
        Node(){
            value=0;
            left = NULL;
            right = NULL;
    
        }
        Node(int v){
            left = NULL;
            right = NULL;
            value=v;    
        }

};


class BST{
    
        Node *root;

    public:
        BST(){
            root=NULL;
        }
        bool is_empty(){
            if(!root){
                return true;
            }
            return false;
        }
        int insert_node(int value){
            Node *n = new Node(value);
            if(is_empty()){
                root = n;
                return 1;
            }
            else{
                Node *temp = root;
                while(temp){
                    if(temp->value== n->value){
                        cout<<" duplicate detected:";
                        return -1;
                    }
                    if(temp->value> n->value){
                        if(temp->left==NULL){
                            temp->left = n;
                            return 1;
                        }
                        temp = temp->left;
                    }
                    else if(temp->value< n->value){
                            if(temp->right == NULL){
                                temp->right = n;
                                return 1;
                            }
                            temp= temp->right;
                        
                        }
                
                }
            }
        }
        void pre_show(Node *root){
            if(root){
                cout<<root->value<<'\t';
                pre_show(root->left);
                pre_show(root->right);
            }
        }
        void post_show(Node *root){
            if(root){
                post_show(root->left);
                post_show(root->right);
                cout<<root->value<<'\t';
            }
        }
        void in_show(Node *root){
            if(root){
                in_show(root->left);
                cout<<root->value<<'\t';
                in_show(root->right);
            }
        }
        
        int search_recursive(int value,Node *root){
            if(root){
                if(root->value==value){
                    return 1;
                }
                if(root->value<value){
                    return search_recursive(value,root->right);
                }
                else if(root->value>value){
                    return search_recursive(value,root->left);
                }
            }
            return -1;
        }
        int search_iterative(int value, Node *root){
            if(root){
                Node *temp = root;
                while(temp){
                    if(temp->value==value){
                        return 1;
                    }
                    if(temp->value>value){
                        temp = temp->left;
                    }
                    else{
                        temp = temp->right;
                    }
                }
                
            }
            return -1;
        }

        int search(int value,const char &c){
            switch(c){
                case 'r':  return search_recursive(value,root);
                case 'i':  return search_iterative(value,root);
                default:    cout<<"wrong option\n"; break;
            };
        }
        
        int height(Node* tree){
            if(tree){
                int rheight= 1+ height(tree->right);
                int lheight = 1+ height(tree->left);

                if(rheight>lheight){
                    return rheight;
                }
                else 
                    return lheight;     
            }
            return -1;
        }
        
        int tree_height(){
            return height(root);
        }
        
        void display(option op){
            
            switch (op)
            {
            case option::preorder:  pre_show(root);
                                    break;
            case option::inorder:   in_show(root);
                                    break;
            case option::postorder: post_show(root); 
                                    break;
            default:    cout<<"wrong option \n";
                        break;
            };  
            cout<<endl;
        }

};



int main(){
    Node n(4);
    BST b;
    cout<<'\n'<<b.insert_node(2);
    cout<<'\t'<<b.insert_node(1);
    cout<<'\t'<<b.insert_node(3);
    cout<<'\t'<<b.insert_node(5);
    cout<<'\t'<<b.insert_node(-1);
    cout<<'\t'<<b.insert_node(22);
    cout<<'\t'<<b.insert_node(4);
    cout<<' '<<b.insert_node(3)<<"\n\n\n";
    b.display(option::inorder);
    b.display(option::postorder);
    b.display(option::preorder);

    cout<<"\n"<<b.search(7,'r')<<'\t'<<b.search(2,'r')<<'\n';
    cout<<"\n"<<b.search(7,'i')<<'\t'<<b.search(2,'i')<<'\n';

    cout<<b.tree_height()<<'\n';
    return 0;
}