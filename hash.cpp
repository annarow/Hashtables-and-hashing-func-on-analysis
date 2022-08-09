//
// Created by arwal on 3/12/2020.
//Anna Rowena Waldron
#include<algorithm>
#include <string>
#include "hash.h"
#include <iostream>

using namespace std;
/*
 * Void function that reads a file using ifstream and creates a string variable to hold each
 * line of the file, using a while loop with parameters of while it can get another line,
 * to then call another function addToTable.
 */
void Hash::buildTable(ifstream &file){
    string line;
    while(getline(file, line)) {
        this->addToTable(line);
    }
}
/*
 * Void function that takes a constant string reference of a line from a file. Creates a new PhoneNumber pointer
 * and creates a phonenumber object to then set the data equal to the line from the file. Incremenets the size of
 * the hash table array by for testing purposes. Creates an integer variable index to hold the return of another
 * function which finds the hash index.
 */
void Hash::addToTable(const string & line) {
    PhoneNumber *contact = new PhoneNumber;
    contact->data = line;
    this->size += 1;
    int index;
    index = this->hashFunction(*contact);
    this->insertToTable(index, *contact);
}
/*
 * Function that returns an integer of the hashed index that has been found. Takes a phonenumber object as a parameter
 * and creates an integer variabe to hold the hashed number and a character variable to hold character from the
 * string to then be transformed into an integer. For loop goes through the length of the data and adds each character
 * as an integer into the cost variable and multiplies by 31 to then modulo by the size of the hash table array, 4177.
 */
int Hash::hashFunction(Hash::PhoneNumber contact) const {
    int cost = 0;
    char letter;

    for(int i = 0; i < contact.data.length(); i++){
        letter = contact.data.at(i);
        cost += (cost + letter) * 31;
        cost %= 4177;
    }
    return cost;
}
/*
 * Void function that takes the hashed index as a parameter and a phonenumber object reference and decides where
 * to inset into the hashed tabled and if there is a collision to enter the else statement and call the insertToChain
 * function with the same parameters. Uses an if statement to check if there is an object already in that hashed index,
 * and if not to set that index to the object. Sets the end pointer of the object to itself and increments the
 * chain length variable by 1, and increases the value of the chain array by 1.
 */
void Hash::insertToTable(int hashIndex, Hash::PhoneNumber &contact) {
    if(table[hashIndex].chainLength == 0){
        table[hashIndex] = contact;
        table[hashIndex].end = &contact;
        table[hashIndex].chainLength ++;
        chain[hashIndex] += 1;

    }else {

        insertToChain(hashIndex, contact);
    }
}

/*
 * Void function which takes an integer variable of the hashed index and a phonenumber object reference
 * to insert into the hashtable by collision using the idea of a linked list. sets the end pointers object next pointer
 * to the object reference and sets end pointer to itself. Increments the chain length variable at the start of
 * the chain by 1 and increments the chain array at the index by 1.
 */
void Hash::insertToChain(int hashIndex, Hash::PhoneNumber &contact) {
    table[hashIndex].end->next = &contact;
    table[hashIndex].end = &contact;
    table[hashIndex].chainLength ++;
    chain[hashIndex] += 1;
}
/*
 * Overload operator function to help with putting the data discovered by the program into an excel spreadsheet
 * to then be shown in chart and table format. Takes a ostream as a parameter and a constant hash object reference
 * to then create a file and use a forloop to output the index in the table followed by the chain length at
 * that index.
 */
ostream& operator<< (ostream& stream, const Hash &hash) {
    ofstream file("excel.csv") ;
    for(int i = 0; i < 4177; i++){
        stream<< i << ", ";
        stream<< hash.table[i].chainLength << '\n';
        file<< i << ", ";
        file<< hash.table[i].chainLength << '\n';
    }
    file.close();
    return stream;

}





