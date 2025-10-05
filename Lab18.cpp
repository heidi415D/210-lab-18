#include <iostream>
#include <string>
using namespace std;

struct Node {
    double rating; // movie rating
    string comment; // movie comment
    Node* next; // pointer to next node
};

Node* head;

// adds new node at head
void addToHead(double rate, string comm){
    Node* newNode = new Node; // memory allocation
    newNode->rating = rate; // set rating
    newNode->comment = comm; // set comment
    newNode->next = head; // point new node to current head
    head = newNode; // update head to new node
}

// adds new node at tail
void addToTail(double rate, string comm) {
    Node* newNode = new Node; // memory allocation
    newNode->rating = rate; // set rating
    newNode->comment = comm; // set comment
    newNode->next = nullptr; // new node points to null

    if (head == nullptr){
        head = newNode;
        return;
    }

    Node* temp = head;
    while( temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void displayReviews() {
    Node* temp = head; // start at head
    int count = 1;
    while (temp!= nullptr) {
        cout << "> Review #" << count << ": "
            << temp->rating << ": " << temp->comment << endl;
        temp = temp->next; // move to next node
        count++; // increment review count
    }
}

int main() {
    cout << "which linked list method should we use?\n";
    cout << "[1] Add new nodes at head\n";
    cout << "[2] Add new nodes at tail\n";
    cout << "Choice: "

    int choice;
    cin >> choice;

    double rating;
    string comment;

    cout << "Enter review rating 0-5: ";
    cin >> rating;

    cout << "Enter review comment: ";
    getline(cin, comment); 

    addToHead(rating, comment);

    cout << "Data added!" << endl;

    return 0;
}