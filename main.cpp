#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <chrono>
#include <time.h>


#include "avl.h"
#include "BinaryTree.h"
#include "Hashtable.h"

string Erase(string word)
{
    word.erase(remove_if(word.begin(), word.end(), [](char c) {return (c == '=' || c == '"' || c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&' || c == '*' || c == '(' || c == ')' || c == '-' || c == '_' || c == '{' || c == '}' || c == '[' || c == ']' || c == '|' || c == ';' || c == ':' || c == '<' || c == '>' || c == '?' || c == '/' || c == ',' || c == '.' || c == '\'' || c == '~'); }), word.end());
    return word;
}

using namespace std;

int main()
{
    fstream file;
    string word, filename;
    filename = "file.txt";
    string Q[5000];

    srand(time(0));

    // Initializing BinaryTree, Avl , HashTable
    BinaryTree a;
    a.init();
    AVL b;
    AVL* node = nullptr;
    HashTable hash;

    string* temp;
    temp = new string[251352]; // All the words will be temporarily stored in this array in order to then choose 1000 random words out of it.
    int i = 0;

    file.open(filename.c_str());
    while (file >> word)   // All the inserts happen, also filling the temp array so we can then create the Q array
    {
        word = Erase(word);

        a.insert_node(word);
        node = b.insert_nodeAVL(node, word);
        hash.insert(word);
        temp[i] = word;
        i++;
    }

    int num;

    for (i = 0; i < 5000; i++) //Selection of the 1000 random words , inserting them in the Q array
    {
        num = (rand() % 251352) + 1;
        Q[i] = temp[num];
    }

    /*cout << "----------Binary Tree Functions----------" << endl;

    cout << "-----------preorder-----------" << endl;
    a.preorder(a.root);
    cout << endl << "-----------inorder-----------" << endl;
    a.inorder(a.root);
    cout << endl << "-----------postorder-----------" << endl;
    a.postorder(a.root);


    cout << endl << "----search----" << endl;
    if (!a.Search(word))
        cout << "Word not found" << endl;
    cout << endl << "----delete----" << endl;
    if (a.Delete(word))
        cout << "Word deleted" << endl;
    else
        cout << "No  word like '" << word << "' in the tree" << endl;




    cout << "----------AVL Tree Functions----------" << endl;

    cout << "-----------preorder-----------" << endl;
    b.preOrder(node);
    cout << endl << "-----------inorder-----------" << endl;
    b.inOrder(node);
    cout << endl << "-----------postorder-----------" << endl;
    b.postOrder(node);


    cout << endl << "----search----" << endl;
    if (!b.Search(node, word))
        cout << "Word not found" << endl;

    cout << endl << "----delete----" << endl;
    b.deleteAVL(node, word);*/





    auto start_time = chrono::high_resolution_clock::now();
    for (int j = 0; j < 5000; j++)
    {
        if (!a.Search(Q[j]))
        {
            cout << "Word not found" << endl;
        }

    }
    auto end_time = chrono::high_resolution_clock::now();
    auto time = end_time - start_time;



    auto start_timeAVL = chrono::high_resolution_clock::now();
    for (int j = 0; j < 5000; j++)
    {
        if (!b.Search(node, Q[j]))
        {
            cout << "Word not found" << endl;
        }

    }
    auto end_timeAVL = chrono::high_resolution_clock::now();
    auto timeAVL = end_timeAVL - start_timeAVL;



    auto start_timeHash = chrono::high_resolution_clock::now();
    for (i = 0; i < 5000; i++)
    {
        hash.search(Q[i]);
    }
    auto end_timeHash = chrono::high_resolution_clock::now();
    auto timeHash = end_timeHash - start_timeHash;


    cout << endl << "Binary tree Search took: " << time / chrono::nanoseconds(1) << " nanoseconds to run." << endl;

    cout << endl << "AVL tree Search took:    " << timeAVL / chrono::nanoseconds(1) << " nanoseconds to run." << endl;

    cout << endl << "HashTable Search took:   " << timeHash / chrono::nanoseconds(1) << " nanoseconds to run." << endl;

    return 0;
}

