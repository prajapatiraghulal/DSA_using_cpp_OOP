#include<iostream>
#include<math.h>
using namespace std;


class Array{
    private:
    int *arr;
    int max;

    public:
    void swap(int &a,int &b){
        int temp = a;
        a=b;
        b=temp;
        
    }
    int binary_search(int value, int min , int maxx){
        if(min>maxx)
            return -1;
        int mid = (min+maxx)/2;
        if(arr[mid]==value){
            return mid;
        }else if(arr[mid]>value){
            return binary_search(value,min, (mid-1));
        }else{
            return binary_search(value,(mid+1),maxx);
        }

    }
    int linear_search(int value, int min, int maxx){
        while(min<=maxx){
            if(arr[min]==value){
                return min;
            }
            min++;
        }
        return -1;
    }
    void merge(int arr[], int low, int mid, int high){
        int *temp = new int[(high-low)+1];
        int k=0;
        int i=low, j=mid+1;
        
        while(i<=mid && j<=high){
            if(arr[i]<arr[j]){
                temp[k++]= arr[i++];
            }
            else{
                temp[k++] = arr[j++];
            }
        }
        if(i>mid && j<=high){
            while(j<=high){
                temp[k++]=arr[j++];
            }
        }else if(i<=mid && j>high){
            while(i<=mid){
                temp[k++] = arr[i++];
            }
        }
        for(i=0,j=low;j<=high;){
            arr[j++]= temp[i++];
        }

    }
    int partition(int low, int high){
        int pivot = arr[high];
        int i=low, j=high;

        while(i<j){

            while(arr[i]<pivot){
                i++;
            }
            while(j>=i && arr[j]>=pivot){
                j--;
            }
            if(i<j){
                swap(arr[i],arr[j]);
            }
        }
        swap(arr[i],arr[high]);
        return i;
    }

    public:
    Array(int m){
        max = m;
        arr = new int[max];
        for(int i=0;i<max;i++){
            arr[i]=0;
        }
    }
    Array(int *a,int m){
        max = m;
        arr = new int[max];
        for(int i=0;i<max;i++){
            arr[i]=a[i];
        }
    }
    int& operator[](const unsigned &i){
        if(i>=max)
            throw(-1);
        return arr[i]; 
    }
    
    void selection_sort(){
        int min,i,j;
        for(i=0;i<max-1; i++){
            min = i;
            for(j=i+1;j<max;j++){
                if(arr[i]>arr[j]){
                    min=j;
                }
            }
            if(i!=min)
                swap(arr[i],arr[min]);
        }    
    }
    void insertion_sort(){
        int i,j,temp;
        for(i=1;i<max;++i){
            temp = arr[i];

            for(j=i-1;j>=0 && arr[j]>temp;--j){
                arr[j+1] = arr[j];
            }
            arr[j+1] = temp;
        }
    }
    void bubble_sort(){
        int i,j;
        for(i= 0;i<max;i++){
            for(j=0;j<((max-1)-i);j++){
                if(arr[j]>arr[j+1]){
                    swap(arr[j],arr[j+1]);
                }
            }
        }
    }
    void merge_sort(int arr[] ,int low,int high){
        if(low<high){
            merge_sort(arr,low, (low+high)/2);
            merge_sort(arr,((low+high)/2+1),high);
            merge(arr, low, (low+high)/2, high);
        }

    }
    void quick_sort(int low, int high){
        if(low<high){
            int p = partition(low, high);
            quick_sort(low,p-1);
            quick_sort(p+1,high);
        }

    }
    void count_sort(){
        int high=max;
        int maxx= arr[0];
        int minn=arr[0];
        for(int i=1;i<high;++i){
            if(arr[i]>maxx){
                maxx=arr[i];

            }
            if(arr[i]<minn){
                minn = arr[i];
            }
        }
        
        
        //cout<<'\n'<<minn<<" "<<maxx<<endl;

        int *temp= new int[maxx-minn+1];
        for(int i=0;i<=maxx-minn;++i)
            temp[i]=0;
        for(int i=0;i<max;++i){
            temp[arr[i]-minn]++;
        }
        for(int i=1;i<=maxx-minn;++i){
            temp[i]+=temp[i-1];
            
        }
        /*
        for(int i=0;i<maxx-minn+1;i++){
            cout<<temp[i]<<'\t';
        }*/

        for(int i=maxx-minn;i>0;--i){
            while(temp[i]>temp[i-1]){
                //if(arr[temp[i]])
                arr[temp[i]-1]= i+minn;
                --temp[i];
            }
        }
        while(--temp[0]>=0){
            arr[temp[0]]= minn;
        }

    }
    void c_sort(int div){
        int temp[10]={0};
        int *out = new int[max];
        for(int i=0;i<max;i++){
            ++temp[(arr[i]/div)%10];
        }
        for(int i=1;i<10;i++){
            temp[i]+=temp[i-1];
        }
        for(int i=max-1;i>=0;--i){
            out[--temp[(arr[i]/div)%10]]= arr[i];
        }
        for(int i=0;i<max;i++){
            arr[i]=out[i]; 
        }
    }

    int max_index(){
        int max_in = 0;
        for(int i=0;i<max;i++){
            if(arr[max_in]<arr[i]){
                max_in=i;
            }
        }
        return max_in;
    }
    void radix_sort(){
        int max_in = arr[max_index()];
        for(int div=1;max_in/div>0;div*=10){
            c_sort(div);
        }
    }
    void sort(char c='s'){
        switch (c)
        {
        case 's':   selection_sort();
                    break;
        case 'i':   insertion_sort();
                    break;
        case 'b':   bubble_sort();
                    break;
        case 'm':   merge_sort(arr,0,max-1);
                    break;
        case 'q':   quick_sort(0,max-1);
                    break;
        case 'c':   count_sort();
                    break;
        case 'r':   radix_sort();
                    break;
        default:
            break;
        };
    }
    void display(){
        for(int i=0;i<max;i++){
            cout<<arr[i]<<"\t";
        }
        cout<<'\n';
    }

    int search(int value, char c='u'){
        if(c=='u' || c=='U'){
            return linear_search(value,0,(max-1));
        }
        else if(c=='s' || c=='S'){
            return binary_search(value,0, (max-1));
            }
    }

};

int main(){
    int ar[]={1,30,1,13,999,1000};
    Array a1(ar, sizeof(ar)/sizeof(int));
    Array a2(10);
    //cout<<a1[0]<<"\t"<<a2[0];
    //a1.display();
    //a1[0]=14;
    //a1.display();
    //a2.display();
    //cout<<a1.search(112,'u')<<'\t'<<a1[a1.search(112,'u')]<<endl;

    for(int i=0;i<10;i++){
        a2[i]= sqrt(i*100);
    }
    //a2.display();
    //cout<<a2.search(sqrt(3*100),'s');
    a1.display();
    //a1.sort('c');
    
    //cout<<'\n';
    //a1.display();
    cout<<'\n';
    //a1.sort('r');
    //a1.display();
    a1.sort('q');
    cout<<'\n';
    a1.display();
    return 0;

}