#include<iostream>
using namespace std;

class MyStack{
    private:
        int max;
        int *arr;
        int top;

    public:
        MyStack(int m=10){
            arr = new int[m];
            max = m; 
            top=-1;
            for(int i=0;i<sizeof(arr);i++)
                arr[i]=0;       
        }
        bool isFull(){
            if(top==(max-1)){
                return true;
            }
            else
                return false;
        }
        void push(int value){
            if(!isFull()){
                top++;
                arr[top] = value;
            }
            else{
                throw(-1);   
            }
        }
        bool isEmpty(){
            if(top==-1){
                return true;
            }
            else
                return false;
        }

        int pop(){
            if(isEmpty()){
                
                throw(-1);
            }
            else{
                
                return(arr[top--]);
            }
        }
        
        int peek(int index){
            if(isEmpty()){
                throw(-1);
            }
            if(top<index){
                throw(-1);
            }
            else{
                return(arr[index]);
            }
        }
        void change(int index,int value){
            if(isEmpty()){
                throw(-1);
            }
            else if (index>top)
               throw(-1);
            else
                arr[index]= value;
        }
        void display(){
            if(isEmpty()){
                cout<<"Empty stack printed:\n";
            }
            for(int i=top; i>-1;i--)
                cout<<arr[i]<<"\t";
            cout<<endl;
        }


};


int main(){
    MyStack s1 = MyStack(5);
    //cout<<s1.pop()<<endl;     this will throw int -1 error
    s1.push(10);
    s1.push(15);
    cout<<s1.pop()<<endl;
    s1.push(100);
    s1.push(32);
    s1.display();
    s1.change(2,300);
    s1.display();

    MyStack s2(10);
    s2.display();

return 0;
}