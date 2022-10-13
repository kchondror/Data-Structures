#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
#include <cstring>
#include <iostream>
#define Size 251353
using namespace std;



struct Node
{
    string lexh;
    int emfaniseis;
};



class HashTable
{
public:
    HashTable();
    Node* search(const string&);
    void insert(const string&);

private:
    Node* table; // Creating the HashTable as an array of HashNodes


};

#endif // HASHTABLE_H
