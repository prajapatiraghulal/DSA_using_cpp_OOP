#include<iostream>
using namespace std;

class MyCircularQueue{
    private:
    int *arr;
    int fend,rend;
    int max;

    public:
    MyCircularQueue(int m){
        max = m;
        arr= new int[max];
        fend = rend=-1;
        for(int i =0;i<max;i++){
            arr[i]=0;
        }
    }
    bool isEmpty(){
        if(fend==-1 && rend==-1)
            return true;
        return false;
    }
    bool isFull(){
        if((fend+1)%max==rend){
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
            fend=(fend+1)%max;
            arr[fend]=value;
        }
    }
    int dequeue(){
        if(isEmpty()){
            throw(-1);
        }
        int temp = arr[rend];
        rend = (rend+1)%max;
        return temp;
    }
    void display(){
        for(int i=rend;i%max!=fend;i++)
            cout<<arr[i]<<"\t";
        cout<<endl;
    }

};

int main(){
    MyCircularQueue c1(5);
    cout<<c1.isEmpty()<<endl;
    cout<<c1.isFull()<<endl;
    c1.enqueue(10);
    c1.enqueue(20);
    c1.enqueue(30);
    c1.enqueue(40);
    c1.enqueue(50);
    cout<<c1.isEmpty()<<endl;
    cout<<c1.isFull()<<endl;
    cout<<c1.dequeue()<<endl;
    cout<<c1.isEmpty()<<endl;
    cout<<c1.isFull()<<endl;
    c1.display();
    


    return 0;
}