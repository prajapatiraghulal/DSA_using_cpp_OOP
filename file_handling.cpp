#include<iostream>
#include<fstream>
using namespace std;

int main(){
    char ch[100];
    ofstream file("text.txt");
    cout<<"enter name full\n";
    cin.getline(ch,100);
    //cout<<ch;
    file<<ch;
    file.close();
    return 0;


}