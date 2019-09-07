//
//  main.cpp
//  Red-Yellow-Green-Game
//
//  Created by Julian Carachure on 1/29/15.
//  Copyright (c) 2015 Julian Carachure. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string>
#include <iomanip>
using namespace std;

class game {
public:
    int guess;
    int win;
    int check();
    string prediction;
    string winner;
    string start(string& prediction);
    string random(string& winner);
    void congrats();
};

void cinClear();

int main(){
    game letsgo;
    int n=0;
    char end;
    string maintitle = " RED-YEllOW-GREEN GAME  ";
    string underline(maintitle.size(),'_');
    cout <<maintitle<<endl;
    cout << underline<<endl;
    
    do{
        letsgo.random(letsgo.winner);
        do{
        cout<<setw(15)<< "Round " << ++n <<endl;
        letsgo.start(letsgo.prediction);
        letsgo.win = letsgo.check();
        }while(letsgo.win!=1);
        letsgo.congrats();
        cout<<"Do you want to play again (Y/N): ";
        cin>>end;
        cout<<endl;
    }while((end !='n')&&(end !='N'));
    cout<< "Total Rounds " << n << endl;
    cout<<endl;
    return(0);
}

string game::random (string& winner){
    srand(time(0));
    long int lucky = rand()%901+100;
    winner = to_string(lucky);
    string title = " Winning number is "+winner+ " "; // (*) BOX FOR THE WINNING NUMBER
    string asterisk(title.size(),'*');                //                |
    string spaces(title.size(),' ');                  //                |
    string second = "*" + spaces + "*";               //                |
    string first = "*" + asterisk + "*";              //                |
     //cout << endl << first << endl;                 //                |
     //cout <<second << endl;                         //                |
     //cout << "*" << title << "*" << endl;           //              \   /
     //cout << second << endl;                        //               \ /
     //cout << first <<endl;                          //                V
    return(winner);
}

string game::start(string& prediction){
    cout << "Please enter your guess: ";
    cin >> guess;
    cout << endl;
    prediction = to_string(guess);
    return(prediction);
    
}


int game:: check(){
    int red=3,green=0,yellow=0;
    for (int i=0;i<3;i++){
    if (prediction[i] == winner[i]){
    green++;
    prediction[i]=-1;
        }
    }
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
        if (prediction[i]==winner[j]){
        yellow++;
            }
        }
    }
        red = red - green - yellow;
    cout<< setw(18)<<"Total Green: "<<green<<endl;
    cout<< setw(16)<<" Total Red: "<<setw(3)<<red<<endl;
    cout<< setw(18)<<"Total Yellow:"<<yellow<<endl;
    if (green==3) return 1;
    else{
        cout<<"\nSORRY TRY AGAIN ..."<< endl;
        cout<<endl;
        return 0;
        }
    }

void game:: congrats (){
    cout<<"──────────────╔╗───────╔╗╔╗────╔═╗"<<endl;
    cout<<"╔═╦═╦═╦╦═╦╦╦═╗║╚╦╦╦╗╔═╗║╚╬╬═╦═╦╣═╣"<<endl;
    cout<<"║═╣╬║║║║╬║╔╣╬╚╣╔╣║║╚╣╬╚╣╔╣║╬║║║╠═║"<<endl;
    cout<<"╚═╩═╩╩═╬╗╠╝╚══╩═╩═╩═╩══╩═╩╩═╩╩═╩═╝"<<endl;
    cout<<"───────╚═╝"<<endl;

    
}
