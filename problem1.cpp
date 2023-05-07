#include <iostream>
#include <vector>
using namespace std;

int hashFunction(int key, int tableSize) {
    return key % tableSize;
}

vector<vector<int>> createHashTable(vector<int> keys, int tableSize) {
    // creating a hash table by doing a vector of vectors
    vector<vector<int>> hashTable(tableSize);

    //adding keys using chaining
    for (int key : keys) {
        int index = hashFunction(key, tableSize);
        hashTable[index].push_back(key);
    }

    return hashTable;
}

//printing the table
void printHashTable(vector<vector<int>> hashTable) {
    for (int i = 0; i < hashTable.size(); i++) {
        cout << "Bucket " << i << ": ";
        for (int key : hashTable[i]) {
            cout << key << " ";
        }
        cout << endl;
    }
}

int main() {
    vector<int> keys = {1, 4, 7, 1, 5, 2, 4, 1, 3, 5};
    int tableSize = 5;

    vector<vector<int>> hashTable = createHashTable(keys, tableSize);

    printHashTable(hashTable);

    return 0;
}
