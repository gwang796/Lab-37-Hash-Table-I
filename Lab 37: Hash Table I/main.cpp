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

//function print prints the first 100 entries
//arguments: map
//return: none
void print(map<int,list<string>> &hash_table);

//function search_for_key searches for mapped value
//arguments: map
//return: none
void search_for_key(map<int,list<string>> &hash_table);

//function add_key adds entry to map
//arguments: map
//return: none
void add_key(map<int,list<string>> &hash_table);

//function remove_key removes mapped value
//arguments: map
//return: none
void remove_key(map<int,list<string>> &hash_table);

//function modify_key modiefies mapped value
//arguments: map
//return: none
void modify_key(map<int,list<string>> &hash_table);

int main() {
    bool again = true;
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
    
    
    int choice;
    while (again) {
        cout << "----Hash Table Menu----" << endl;
        cout << "1. print first 100 entries" << endl;
        cout << "2. search for key" << endl;
        cout << "3. add a key" << endl;
        cout << "4. remove a key" << endl;
        cout << "5. modify a key" << endl;
        cout << "6. exit" << endl;
        cout << "Choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                print(hash_table);
                break;
            case 2:
                
                break;
            case 3:
                
                break;
            case 4:
                
                break;
            case 5:
                
                break;
            case 6:
                cout << "Exiting" << endl;
                again = false;
            default:
                break;
        }
        
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

void print(map<int,list<string>> &hash_table){
    int count = 0;
    for (auto it = hash_table.begin(); it != hash_table.end() && count < 100; ++it) {
        cout << "Hash Index: " << it->first << endl;
        cout << "Code: " << endl;
        for (const string &s : it->second){
            cout << s << endl;
        }
        count++;
    }
}

void search_for_key(map<int,list<string>> &hash_table){
    string search;
    cout << "Enter code to search: ";
    cin >> search;
    
    int index = gen_hash_index(search);
    
    for (const string &s : hash_table[index]){
        if (s == search) {
            cout << "Code was found in bucket " << index << endl;
            return;
        }
    }
    cout << "Code was not found" << endl;
}

void add_key(map<int,list<string>> &hash_table){
    string key;
    cout << "Enter code to add: ";
    cin >> key;
    
    int index = gen_hash_index(key);
    hash_table[index].push_back(key);
    
    cout << "Added to bucket " << index << endl;
}

void remove_key(map<int,list<string>> &hash_table){
    
}

void modify_key(map<int,list<string>> &hash_table);
