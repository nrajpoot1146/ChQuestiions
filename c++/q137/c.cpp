#include <iostream>
using namespace std;

// hash entry class to store key value pair
class HashEntry
{
private:
    int key;
    int value;
public:

    // constructor with two parameter 
    HashEntry(int key, int value)
    {
        this->key = key; // set key 
        this->value = value; // set value
    }

    // setter method for key
    int getKey()
    {
        return key;
    }

    // getter method for value
    int getValue()
    {
        return value;
    }
};

const int TABLE_SIZE = 7;
class HashMap
{
private:
    HashEntry **table;
    int currentSize;
public:
    HashMap()
    {
        currentSize = TABLE_SIZE;
        table = new HashEntry *[this->currentSize];
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = NULL;
    }

    int get(int key)
    {
        int hash = (key % this->currentSize);
        while (table[hash] != NULL && table[hash]->getKey() != key)
            hash = (hash + 1) % this->currentSize;
        if (table[hash] == NULL)
            return -1;
        else
            return table[hash]->getValue();
    }

    // insertion function
    void insert(int value)
    {
        int val = value;
        int hash = (val % currentSize);
        while (table[hash] != NULL)
            hash = (hash + 1) % currentSize;
        if (table[hash] == NULL)
            table[hash] = new HashEntry(hash, value);
    }

    // rehashing function
    void rehash()
    {
        int newSize = this->currentSize * 2; // increase table size by double
        HashEntry **newTable = new HashEntry *[newSize]; // create new table
        for (int i = 0; i < newSize; i++)
            newTable[i] = NULL; // set default value
        
        // copy current table data to new table
        for (int i=0; i<this->currentSize; i++) {
            HashEntry *he = table[i];
            if (he == NULL)
            {
                continue;
            }
            int val = he->getValue();
            
            int hash = (val % newSize);
            while (newTable[hash] != NULL)
                hash = (hash + 1) % newSize;
            if (newTable[hash] == NULL)
                newTable[hash] = new HashEntry(hash, val);
        }

        this->table = newTable; // set current table to new table
        this->currentSize = newSize; // set current size to new size
    }

    int size() {
        return this->currentSize;
    }

    ~HashMap()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
            if (table[i] != NULL)
                delete table[i];
        delete[] table;
    }
};

int main()
{
    HashMap H;
    int arr[] = {121, 81, 16, 100, 25, 0};;
    int s = sizeof(arr) / sizeof(arr[0]);
    for (int i = 0; i < s; i++)
        H.insert(arr[i]);
    H.rehash(); // rehash current map

    int arr2[] = {1, 9, 4, 36, 64, 49};
    // insert new element to hashmap
    int s2 = sizeof(arr2) / sizeof(arr2[0]);
    for (int i = 0; i < s2; i++)
        H.insert(arr2[i]);

    for (int i = 0; i < H.size(); i++)
    {
        cout << i << ": " << H.get(i) << "\n";
    }
}