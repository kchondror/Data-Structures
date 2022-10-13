#include <iostream>
#include "HashTable.h"
#include <math.h>

int hashfunc(string s) // Hashing Function
{
    int ar = 0;
    int length = s.length();
    for (int i = 0; i < length; i++)
        ar += s[i];
    return abs(ar);

}

HashTable::HashTable() // Initializing the HashTable
{
    table = new Node[Size];
    for (int i = 0; i < Size; i++)
        table[i].emfaniseis = 0;


}

void HashTable::insert(const string& value)
{
    int key = hashfunc(value);
    int location = key % Size;
    int step = 101;


    for (int i = 0; i < Size; i++)
    {

        if (table[location].emfaniseis == 0) // Inserting the word in the hashtable if it doesnt already exist
        {
            table[location].lexh = value;
            table[location].emfaniseis++;
            return;
        }

        if (table[location].emfaniseis > 0 && table[location].lexh != value)//If a collision occurs, the word will be inserted in the next available slot
        {
            location = (location + step) % Size;
        }

        if (table[location].emfaniseis > 0 && table[location].lexh == value) // Increasing the appearance counter if the word already exists
        {
            table[location].emfaniseis++;

            return;
        }

    }

}

Node* HashTable::search(const string& value)
{

    int key = hashfunc(value);
    int location = key % Size;
    int step = 101;

    for (int i = 0; i < Size; i++)
    {

        if (table[location].lexh == value && table[location].emfaniseis == 1)
        {
            cout << "The word '" << value << "' has appeared " << table[location].emfaniseis << " time " << endl;
            return &table[location];
        }
        else if (table[location].lexh == value && table[location].emfaniseis > 1)
        {
            cout << "The word '" << value << "' has appeared " << table[location].emfaniseis << " times " << endl;
            return &table[location];
        }
        else
        {
            location = (location + step) % Size;
        }

        // delete[] e;
    }
    cout << "The word '" << value << "' was not found " << endl;
    return nullptr;
}



