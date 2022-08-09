//
// Created by arwal on 3/12/2020.
//Anna Rowena Waldron

#ifndef ASSIGN_4_HASH_H
#define ASSIGN_4_HASH_H
#include <iostream>
#include <fstream>
using namespace std;

/*
 * Hash class that contains an array of integers for chain length and an array of PhoneNumber objects,
 * which is a struct with the Hash class. PhoneNumber is a struct that contains a string for the line of the file,
 * and integer for the chain length of that index, and two pointers for the linked list of collisions.
 * Pointer end points to the last node of the chain.
 */
class Hash{
private:
    struct PhoneNumber{
        string data;
        int chainLength;
        PhoneNumber* end;
        PhoneNumber* next;


        PhoneNumber(){
            data ="";
            chainLength = 0;
            next = nullptr;
            end = nullptr;

        }
        ~PhoneNumber(){
            delete next;
        }
    };
    PhoneNumber table[4177];
    int chain[4177];
    int size;

public:
    Hash(){
        size = 0;
    }

    void buildTable(ifstream &file);
    void addToTable(const string & line);
    int hashFunction(PhoneNumber contact) const;
    void insertToTable(int hashIndex, PhoneNumber &contact) ;
    void insertToChain(int hashIndex, PhoneNumber &contact);
    friend ostream& operator<< (ostream& stream, const Hash &hash);
};

#endif //ASSIGN_4_HASH_H