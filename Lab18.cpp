#include <iostream>
#include <string>
using namespace std;

struct Node{
    double rating; // movie rating
    string comment; // movie comment
    Node* next; // pointer to next node
};

Node* head;

void addToHead(double rate, string comm){
    Node* newNode = new Node; // memory allocation
    newNode->rating = rate; // set rating
    newNode->comment = comm; // set comment
    newNode->next = head; // point new node to current head
    head = newNode; // update head to new node
}

int main() {}