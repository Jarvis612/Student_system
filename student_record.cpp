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

    switch (Choice){
    case '1':
        cin.ignore();
        obj.stuadd();
        break;
    
    case '2':
        cin.ignore();
        obj.dispstu();
        break;
    
    case '3':
        cin.ignore();
        obj.searchstu();
        break;

    case '4':
        return 0;

    default:
        cout<<"invalid choice";
        break;
    }
    
    return 0;
}

void tep::stuadd(){
    cout<<"Enter student roll no: ";
    getline(cin,roll_no);
    cout<<"Name of student: ";
    getline(cin,name);
    cout<<"Enter father name: ";
    getline(cin,Papaname);
    cout<<"Adsress";
    getline(cin,address);

    // Open the file in output mode, appending to existing content
    fel.open("janamkundli.txt" , ios::out | ios::app);
    fel<<roll_no<<" * "<<name<<" * "<<Papaname<<" * "<<address<<" * "<<endl;
    fel.close();

    cout<<"record added successfully!!!!!!!!";
}

void tep::dispstu(){
    // Open the file in input mode
    fel.open("janamkundli.txt", ios::in);
    if(!fel){ // Check if the file exists or was successfully opened
        cout<<"NO record found ____";
        return;
    }

    while(getline(fel , roll_no ,'*') 
    && getline(fel, name ,'*') 
    && getline(fel, Papaname ,'*')
    && getline(fel, address ,'*')){

        cout<<"Student roll no: "<<roll_no<<endl;
        cout<<"student name: "<<name<<endl;
        cout<<"fathers name: "<<Papaname<<endl;
        cout<<"adddress: "<<address<<endl;
    }

    fel.close();
}

void tep::searchstu(){
    cout<<"Enter student Roll no: ";
    getline(cin,search);

    fel.open("janamkundli.txt" , ios::in);
    if(!fel){
        cout<<"No record found______";
        return;
    }

    bool found = false;
    while(getline(fel , roll_no ,'*') 
    && getline(fel, name ,'*') 
    && getline(fel, Papaname ,'*')
    && getline(fel, address ,'*')){
        if(roll_no==search){
            cout<<"Student roll no: "<<roll_no<<endl;
            cout<<"student name: "<<name<<endl;
            cout<<"fathers name: "<<Papaname<<endl;
            cout<<"adddress: "<<address<<endl;
            
            found = true;
        }

        
    }

    if(!found){
        cout<<"NO record found_-";
        return;
    }
    fel.close();
}