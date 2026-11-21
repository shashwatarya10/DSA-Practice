//--------------------creation of a linkedlist------------------

#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

int main(){

    //create first node
    Node* head = new Node (10);
    Node* tail = head;

    //connect second node
    tail->next = new Node(20); 
    tail = tail->next;

    //connect third node 
    tail->next = new Node(30);
    tail = tail->next;

    //Traverse and print
    Node* temp = head;

    int count = 0;
    while(temp != nullptr){
        cout<< temp-> data <<" "<<endl;
        temp = temp -> next;
        count++;
    }
    cout<<count;
    return 0;
}


//-----------------------insertion in linkedlist------------------------

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

//Function to insert a node at the beginning
void insertAtBeginning(Node* &head, int val) {

    // Step 1: Create a new node
    Node* newNode = new Node(val);

    // Step 2: Connect new node to old head
    newNode->next = head;

    // Step 3: Update head
    head = newNode;
}

// Function to print the linked list
void printList(Node* head) {

    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {

   Create original linked list: 10 -> 20 -> 30
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout << "Original list: ";
    printList(head);

   Insert 5 at beginning
    insertAtBeginning(head, 5);

    cout << "After insertion: ";
    printList(head);

    return 0;
}

//---------------------insert 5 then 1 in the same LL--------------------------------

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Function to insert a node at the beginning
void insertAtBeginning(Node* &head, int val) {

    // Step 1: Create a new node
    Node* newNode = new Node(val);

    // Step 2: Connect new node to old head
    newNode->next = head;

    // Step 3: Update head
    head = newNode;
}

//Function to print the linked list
void printList(Node* head) {

    Node* temp = head;

    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {

  Create original linked list: 10 -> 20 -> 30
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout << "Original list: ";
    printList(head);

    // Insert 5 at beginning
    insertAtBeginning(head, 5);
    insertAtBeginning(head,1);

    cout << "After insertion: ";
    printList(head);

    return 0;
}


//insertion at ending
void insertAtEnd(Node* &head, int val){
    Node* newNode = new Node(val);
    if(head == nullptr){
       head = newNode;
       return;
    }
    Node* temp = head;
    while(temp -> next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;
}

//insert at any given position

void insertAtPosition(Node* &head, int val, int pos){
    Node* newNode = new Node(val);

    if(pos == 1){
        newNode-> next = head;
        head = newNode;
        return;
    }

    Node* temp = head;

    for(int i = 1; i < pos - 1; i++){
        temp = temp -> next;
    }
    newNode-> next = temp -> next;
    temp-> next = newNode;
}

//deletion from beginning
void deleteFromBeginning(Node* &head){
    if(head == nullptr){
        cout<<"list is empty";
        return;
    }
    Node* temp = head;
    head = head -> next;
    delete temp;
}

//deletion from end
void deleteFromEnd(Node* &head){
    if(head == nullptr){
        cout<<"list is empty";
        return;
    }
    if(head-> next == nullptr){
        delete head;
        head = nullptr;
        return;
    }
    Node* temp = head;
    while(temp->next->next!= nullptr){
        temp = temp->next;
    }
    delete temp -> next;
    temp -> next = nullptr;
}

//deletion at any given position

void deleteAtPosition(Node* &head, int pos){
    if(head == nullptr){
        cout<<"list is empty";
        return;
    }
    if(pos<1){
        cout<<"invalid position";
        return;
    }
    if(pos==1){
        Node* temp = head;
        head = head -> next;
        delete temp;
        return;
    }
    Node* temp = head;
    
    for(int i = 1; i < pos - 1 && temp != nullptr; i++){
        temp = temp -> next;
    }
    if(temp == nullptr || temp -> next == nullptr){
        cout<<"invalid position";
        return;
    }
    Node* delnode = temp -> next;
    temp->next = delnode -> next;
    delete delnode;
}


//searching in a linked list

void search(Node* head, int key) {

Node* temp = head;

while(temp != nullptr){
    if(temp->data == key){
        cout<<"element found";
        return;
    }

    temp = temp -> next;

}
cout<<"element not found";
}


