#include<fstream>
#include<iostream>
#include<string>
#include "Student.h"
using namespace std;

void Student::login(string u,string p){
	ifstream file("student.txt", ios_base::in);
	string name,phone,uname,password,cl,cppl,htmll;
	if(!file){
		cout<<"Error opening file!"<<endl;
	}
	while(file.good()){		
		getline(file,name,',');
		getline(file,uname,',');
		getline(file,password,',');
		getline(file,phone,',');
		getline(file,cl,',');
		getline(file,cppl,',');
		getline(file,htmll,',');
		if(uname==u && password==p){
			cout<<"Welcome "<<u<<endl;
			file.close();
			return ;
		}
	}
	if(!file.good()){
		cout<<"Can't find "<<u<<" ,please check your credentials"<<endl;
		exit(0);
	}
	file.close();
}

string Student::sign_up() {
    ofstream file("student.txt",ios_base::app);
    if(!file){
		cout<<"Error opening file!"<<endl;
		exit(0) ;
	}
    cout<<"Enter Name: ";
    getline(cin, name);
	cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter Password: ";
    cin>>password;
    cout<<"Enter Phone Number: ";
    cin>>phoneNumber;    
    while(phoneNumber.length()!=10){
    	cout<<"The Number is invalid!"<<endl;
    	cout<<"Enter a valid Phone Number: ";
    	cin>>phoneNumber;
	}
	file<<name<<","<<username<<","<<password<<","<<phoneNumber<<","<<"0"<<","<<"0"<<","<<"0"<<endl;
    cout<<"Signup Successful!\n";
    
    return username;
}
