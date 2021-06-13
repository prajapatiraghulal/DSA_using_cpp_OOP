#include<iostream>
using namespace std;

union u{
    double x;
    char c;
}u1;


class temp{
    public:
    int z;
    union {
        double y;
        char x;
    };
    union {
        double q;
        char p;
    };

    public:
    temp(){
        q=10;
        x=20;
        y=99;

    }
};

int main(){
    u u2;
    u2.x = 78;
    //cout<<u2.x<<endl;
    u2.c=1;
    //cout<<u2.x<<endl;
    //cout<<sizeof(u2)<<' '<<sizeof(u2.c)<<endl;



    temp t;
    t.y=9;
    cout<<t.y;
    return 0;
}