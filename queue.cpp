#include<iostream>
using namespace std;


class MyQueue{
    private:
        int *arr;
        int fend,rend;   //fend is for input side and rend for output side index
        int max;

    public:
        MyQueue(int m=10){
            arr = new int[max];
            fend=rend=-1;
            max = m;
            for(int i=0;i<max;i++){
                arr[i]=0;
            }

        }

        bool isEmpty(){
            if(fend==-1 && rend==-1){
                return true;
            }
            return false;
        }
        bool isFull(){
            if(fend==(max-1)){
                return true;
            }
            return false;
        }
        void enqueue(int value){
            if(isFull()){
                throw(-1);
            }
            if(isEmpty()){
                fend=rend=0;
                arr[fend]=value;
            }
            else{
                fend++;
                arr[fend]= value;
            }
            
        }
        int dequeue(){
            if(isEmpty()){
                throw(-1);
            }
            int item;
            if(rend==fend){
                item = arr[rend];
                rend=fend=-1;
                return item;
            }
            else{
                return arr[rend++];
            }
            
        }
        void display(){
            if(isEmpty()){
                cout<<"empty queue\n";
            }
            else 
            for(int i=rend; i<=fend;i++){
                cout<<arr[i]<<"\t";
            }
            cout<<endl;
        }
        int count(){
            if(isEmpty())
                return 0;
            return fend-rend+1;
        }

};


int main(){
    MyQueue q1(5);
    MyQueue q2 = MyQueue(5);
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    cout<<q1.dequeue()<<endl;
    q1.enqueue(40);
    q1.display();
    cout<<q1.count()<<endl;
    

    return 0;
}