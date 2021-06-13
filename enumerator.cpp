#include<iostream>
using namespace std;

enum class color{       //we can write enum class color: int {...}   this will allow int size memory for color type 
    red,blue,green
};

enum e: char {
    e1,
    e2,
    e3
};

int main(){
    e ex =e1;
    cout<<ex;
    cout<<'\n'<<sizeof(ex);

    color c= color::red;
    cout<<'\n'<<sizeof(c)<<endl;
    

    cout<<(ex==e1);
    

    return 0;
}
