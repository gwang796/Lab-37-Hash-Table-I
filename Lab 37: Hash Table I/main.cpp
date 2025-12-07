//
//  main.cpp
//  CS-210 | Lab 37: Hash Table I | Guo An Wang
//  IDE:Xcode
//  Created by Guo An Wang on 12/6/25.
//

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <list>
using namespace std;

//function sum_ascii returns sum of a strings ascii values
//arguments: string
//return: int
int sum_ascii(string &word);

int main() {
    string word;
    int sum = 0;
    ifstream inputFile("data.txt");
    if (!inputFile) {
        cout << "Unable to open File" << endl;
    }
    while (inputFile >> word) {
        sum += sum_ascii(word);
    }
    inputFile.close();
    
    cout << sum << endl;
    return 0;
}
/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/

int sum_ascii(string &word){
    int sum = 0;
    for (char c : word) {
        sum += (int)c;
    }
    return sum;
}
