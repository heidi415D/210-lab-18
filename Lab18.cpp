#include <iostream>
#include <string>
#include <iomanip> // for setprecision
using namespace std;

struct Node {
    double rating; // movie rating
    string comment; // movie comment
    Node* next; // pointer to next node
};

Node* head;

// adds new node at head
void addToHead(double rate, const string& comm){
    Node* newNode = new Node; // allocate new node
    newNode->rating = rate; // set rating
    newNode->comment = comm; // set comment
    newNode->next = head; // point new node to current head
    head = newNode; // update head to new node
}

// adds new node at tail
void addToTail(double rate, const string& comm) {
    Node* newNode = new Node; // allocate node
    newNode->rating = rate; // set rating
    newNode->comment = comm; // set comment
    newNode->next = nullptr; // tails next is always nullptr

    if (head == nullptr){ // if list empt, new node is head
        head = newNode; // set head and return
        return;
    }

    Node* temp = head; // start at head
    while( temp->next != nullptr) {
        temp = temp->next; // advance to last node
    }
    temp->next = newNode; // link last node to new node
}

void displayReviewsAndAverage() {
    Node* temp = head; // start at head
    int count = 0; // start at 0, increment for each review
    double sum = 0.0;

    if (!temp){ 
        cout << "No reviews to display.\n";
        return;
    }

    while (temp!= nullptr) { // traverse all nodes
       cout << "     > Review #" << (count + 1) << ": "
            << fixed << setprecision(1) 
            << temp->rating << ": " << temp->comment << endl;
         sum += temp->rating; // accumulate ratings
         temp = temp->next; // advance to next node
         count++; // increment review count        
    }

    double average = sum / count; // compute average
    cout << "    > Average: " << fixed << setprecision(5) 
         << average << endl;
}

int main() {
    cout << "Which linked list method should we use?\n";
    cout << "[1] Add new nodes at head\n";
    cout << "[2] Add new nodes at tail\n";
    cout << "Choice: ";

    int choice; 
    cin >> choice; // read mode 1 or 2
    cin.ignore(); // clear newline from input buffer

    double rating;
    string comment;
    char more;

   do {
    cout << "Enter review rating 0-5: ";
    cin >> rating; // read rating
    cin.ignore(); // clear newline so getline works

    cout << "Enter review comment: ";
    getline(cin, comment); // read full line comment

    if (choice == 1) // select add mode based on choice
        addToHead(rating, comment); 
    else
        addToTail(rating, comment);

    cout << "Enter another review? Y/N: ";
    cin >> more; // read Y/N answer
    cin.ignore(); // clear newline for next loop
} while (more == 'y' || more == 'Y');

cout << "Outputting all reviews:\n";
displayReviewsAndAverage(); // prints all reviews

    return 0;
}
