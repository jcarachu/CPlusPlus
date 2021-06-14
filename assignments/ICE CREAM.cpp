//
//  main.cpp
//  ICECREAM
//
//  Created by Julian Carachure on 1/25/15.
//  Copyright (c) 2015 Julian Carachure. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;
const int maxcone=10;
const int maxscoops=5;
const double scoop1=2.00;
const double scoop2=3.00;
const double adscoop=0.75;
double TotalPrice=0;
double pricecalc (int numscoops);
double numbercones(int number,int& count,double&TotalPrice);
void graph (int scoop);
double scoopcalc (double& TotalPrice,int& scoop,int numcone,int& count);
void cone (int numcone,int count, double& TotalPrice);
void icecream (int numcone);

    int main () {
    int numcone,count=1;
    double TotalPrice=0;
    icecream(numcone);
    cone(numcone,count,TotalPrice);
    }

    // *************** NUMBERCONES ***************

    double numbercones(int numcone,int& count,double& TotalPrice){
    int scoop;
    while (count<=numcone){
        cout << "How many scoops for cone " << count << " (5 MAX): ";
        cin >>scoop;
        ++count;
        scoopcalc(TotalPrice,scoop,numcone,count);
        }
    return (TotalPrice);
    }
    // *************** CONE ********************
    void cone (int numcone,int count, double& TotalPrice){
    cout << "Please input the number of cones you wish to purchase (10 MAX): ";
    cin  >> numcone;
    if (numcone<= maxcone){
    
        numbercones(numcone,count,TotalPrice);
    
    }
    else if (numcone >= maxcone){
    cout << "Exceeds Limit\nTry again"<<endl;
    cone (numcone,count,TotalPrice);
    
    }
    cout << "Total Charge: $" << fixed << setprecision(2)<< TotalPrice << endl;
    }

    // *************** SCOOPCALC ********************

    double scoopcalc (double& TotalPrice,int& scoop,int numcone,int& count){
    double Price;
    if (scoop <= maxscoops){
        graph(scoop);
        Price= pricecalc(scoop);
        TotalPrice = TotalPrice + Price;
    }
    else if (scoop>= maxscoops){
        cout << "Exceeds Limit\n";
        count=count-1;
        numbercones(numcone,count,TotalPrice);
    }
    
    return (TotalPrice);
    }

    // *************** PRICECALC ***************

    double pricecalc(int numscoops){
    double sum = 0.0;
    switch (numscoops){
        case (1): sum = scoop1;
            break;
        case (2): sum = scoop2;
            break;
        default: sum= (scoop2 +(adscoop*(numscoops-2)));
            break;
    }
    return (sum);
    }

    // *************** GRAPH ********************

    void graph (int scoop){
    string first,second,stacks,TotalStacks;
    char fl;
                for (int count=1; count<=scoop; count++){
                    cout << "Specify the flavor for scoop " << count << ": ";
                    cin >> fl;
                    first = "(   ";
                    second = "   )\n";
                    stacks= first +fl + second;
                    TotalStacks=stacks+TotalStacks;
                    if (count==scoop){
                        cout<<endl;
                        cout << "Here is your cone! Enjoy!!!" << endl;
                        cout << endl;
                        cout << TotalStacks;
                        cout << "   \\ /" << "\n" << "    |" << "\n" << endl;
            }
        }
      }
    // *************** TITLE ********************
    void icecream (int numcone){
    string title = "           Ice Cream           ";
    string asterisk(title.size(),'*');
    string spaces(title.size(),' ');
    string second = "*" + spaces + "*";
    string first = "*" + asterisk + "*";
    cout << first << endl;
    cout << "*" << title << "*" << endl;
    cout << "*" << setw(18) << "Menu:" << setw(14) << "*" << endl;
    cout << "* 1 Scoop -->" << setw(21) << "$2.00 *\n";
    cout << "* 2 Scoop -->" << setw(21) << "$3.00 *\n";
    cout << "* Each Scoop After -->" << setw(12) << "$0.75 *\n";
    cout << "* Flavors :" << setw(5) << "C" << setw(5) << setw(5)<< "V" << setw(5) << "S"<< setw(7)<< "*" << endl;
    cout << first << endl;
}