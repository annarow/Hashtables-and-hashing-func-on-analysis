//
// Created by arwal on 3/12/2020.
//Anna Rowena Waldron
#include <iostream>
#include <fstream>
#include "hash.h"
/*
 * Main function which opens a file and sees if it's valid to then create a hash object and building the
 * hash table using the file. Prints out the results.
 */
int main(){
    ifstream myFile("phonebook.txt");
    if (!myFile) {
        cout << "File could not be opened." << endl;
        return 1;
    }
    Hash test;
    test.buildTable(myFile);
    cout << test;

}
