//  main.cpp
//  Calories
//  Created by Julian Carachure on 1/15/15.
//  Copyright (c) 2015 Julian Carachure. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

int main() {
    int met,weight,time;
    double calories, Y,kg;
    string activity;
    cout << "Enter Activity" << endl;
    cin >> activity;
    if ((activity =="Sleeping")||(activity =="sleeping")){ // User inputs Walking
        met=1;
    }
    else
        if ((activity =="Basketball")||(activity =="basketball")){ // User inputs Sleeping
            met=8;
    }
    else
        if ((activity =="Walking")||(activity =="walking")){ // User inputs Basketball
            met=2;
        }
    else {
        cout << "Invalid" << endl; // If inputs another activity that isnt listed, you should recieve an error and taken to
                                  // the main menu
        main();
        return 0;
        }
    cout << "Enter weight in lb :" << endl;
    cin >> weight;
    kg = weight/2.2;            // the weight is converted to kg
    cout << "Enter time in minutes: " << endl;
    cin >> time;
    calories = 0.0175*met*kg;
    Y= calories*time;
    cout << "Total calories burned:" << endl;
    cout << setprecision(5) << Y << endl;
    return 0;
}

