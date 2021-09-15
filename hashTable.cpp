#include "hashTable.hpp"

hashTable::hashTable(std::string filename){
    std::ifstream rfile;
    rfile.open(filename);
    int index;
    while(!rfile.eof()){
        rfile >> username;
        index = hash(username);
        rfile >> passcode;
        insert(username, passcode, index);
    }
}

int hashTable::hash(std::string id){
    std::string alphabet = "ABCDEFGHIJKLMONOPQRSTUVWXYZ";
    int index = alphabet.find(id.at(0));
    return index % TABLESIZE;
}

// insert at front of the list
void hashTable::insert(std::string username, std::string passcode, int index)
{
    Node * tmp = new Node(username, passcode);
    tmp->nextNode = table[index];
    table[index] = tmp;
}

// returns pointer to the item or nullptr
Node * hashTable::lookup(std::string id)
{
  int index = hash(id);
  Node * current = table[index];
  while(current != nullptr && current->username != id)
    current = current->nextNode;
  return current;
}

// use this to ensure you have built the table correctly
void hashTable::showAll()
{

  for(int i = 0; i < TABLESIZE;i++)
   {
    Node * current = table[i];
    while(current != nullptr)
     {
        std::cout << current->username << std::endl;
        current = current->nextNode;
     }
  }
}
