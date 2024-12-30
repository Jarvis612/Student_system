#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class tep{
    string roll_no ,name , Papaname , address, search;
    fstream fel;

public:
    void stuadd();
    void dispstu();
    void searchstu();
} obj;
    
int main(){
    char Choice;
    cout<<"---------------------"<<endl;
    cout<<"1- add student in record"<<endl;
    cout<<"2- display student from record"<<endl;
    cout<<"3- Search student from record"<<endl;
    cout<<"4- exit"<<endl;
    cout<<"----------------------"<<endl;
    cin>>Choice;
    
    return 0;
}