// main.cpp
// Checksum Calc ISBN13
// Created by ax on 9/28/16.
// Copyright © 2016 COMP130. All rights reserved.

#include<iostream>
#include<string>

using namespace std;

int check_sum(const string& str) {
    
    string working = str;
    int sum_total = 0;
    
    for (int i = 0; i < str.length(); i++)
    {
        
        int char_to_int = str.at(i) - 48;
        
        if (i % 2 == 0)
        {
            sum_total += char_to_int;
        }
        else
        {
            sum_total += char_to_int * 3;
        }
    }
    
    return sum_total;
    
}

int main() {
    
    string s1 = " ";
    
    cout << "Enter a string of numbers: ";
    
    getline(cin, s1);
    
    int return_check_sum = check_sum(s1);
    
    int d13_calc = 10 - (return_check_sum) % 10;
    
    if (d13_calc == 10)
        d13_calc = 0;
    
    char d13 = static_cast<char>(d13_calc + 48);
    
    string ISBN13 = s1 += d13;
    
    cout << "ISBN13 is: " << ISBN13 << " - amirite?" << endl;
    
    return 0;
    
}