#ifndef HASHTABLE_HPP
#define HASHTABLE_HPP
#include <iostream>
#include <string.h>
#include <fstream>

struct Node{
    std::string username, passcode;
    Node(std::string username, std::string passcode){
        this->username = username;
        this->passcode = passcode;
        this->nextNode = nullptr;
    }
    Node* nextNode = nullptr;
};

class hashTable{
    private:
        std::string username, passcode;
        static const int TABLESIZE = 7;
        static const int KEY = 5;
        Node* table[TABLESIZE];
    public:
        int hash(std::string id);
        hashTable(std::string filename);
        void insert(std::string user, std::string passcode, int index);
        Node * lookup(std::string id);
        void showAll();
};






#endif