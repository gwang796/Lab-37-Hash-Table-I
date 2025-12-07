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
int gen_hash_index(string &word);

int main() {
    string word;
    ifstream inputFile("data.txt");
    if (!inputFile) {
        cout << "Unable to open File" << endl;
    }
    map<int,list<string>> hash_table;
    while (inputFile >> word) {
        int index = gen_hash_index(word);
        hash_table[index].push_back(word);
    }
    inputFile.close();
    
    int count = 0;
    for (auto it = hash_table.begin(); it != hash_table.end() && count < 100; ++it) {
        cout << "Hash Index: " << it->first << endl;
        cout << "Code: ";
        for (const string &s : it->second){
            cout << s << endl;
        }
        count++;
    }
    
    return 0;
}
/*
These targets are present in the dataset and can be used for testing:
536B9DFC93AF
1DA9D64D02A0
666D109AA22E
E1D2665B21EA
*/

int gen_hash_index(string &word){
    int sum = 0;
    for (char c : word) {
        sum += (int)c;
    }
    return sum % 97;
}
