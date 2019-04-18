//
//  main.cpp
//  project3.1
//
//  Created by Julian Carachure on 1/29/15.
//  Copyright (c) 2015 Julian Carachure. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
void evaluate (long double d);
void option (int i,long double d,char letter);
void Loop (long int i, long double d,char letter4);

int main(){
    long double d;
    cout << "Enter any number: ";
    cin >> d;
    evaluate(d);
    cout<<endl;
}
void evaluate(long double d){
    int i,temp2;
    double temp1;
    char letter2;
    
    if (d == static_cast<int>(d)){
        i=static_cast<int>(d);
        temp2=1.0;
        letter2='a';
        option(i, temp2,letter2);
    }
    else if (d==static_cast<long double>(d)){
        d=static_cast<long double>(d);
        temp1=1;
        letter2='b';
        option(temp1,d,letter2);
    }
}

void option (int i,long double d,char letter3){
    int T;
    char input;
    cout << "Do you want the default (Y/N): ";
    cin>>input;
    if (input=='Y'|| input=='y'){
        T=i*i;
        cout << "Your answer is: " << T;
    }
    else if (input=='N'|| input=='n'){
        Loop(i,d,letter3);
    }
}

void Loop (long int i,long double d, char letter4){
    long int T=1;
    long double T2=1.0;
    int count =1;
    int p;
    cout << "Enter Power: ";
    cin>> p;
    if (letter4=='a'){
        while (count <=p){
        T=T*i;
        count++;
        
        }
    cout << "Your answer is: "<< setprecision(2)<< T;
    }
    else if (letter4=='b'){
        while (count <=p){
            T2=T2*d;
            count++;
    
    }
    cout << "Your answer is: "<< fixed<< setprecision(2)<< T2;
    }
}
