#include<iostream>
#include <bits/stdc++.h>
using namespace std;


   class Node{
       public:
       int data;
       Node* next;
       
       Node(int data){
           this -> data = data;
           this -> next = NULL;
       }
   };

   void insertAtHead(Node* &head, int d) {

    // new node create
    Node* temp = new Node(d);
    temp -> next = head;
    head = temp;
}

void insertAtTail(Node* &tail, int d) {
     // new node create
    Node* temp = new Node(d);
    tail -> next = temp;
    tail  = temp;
}

void insertAtPosition(Node* &tail, Node* & head, int position, int d) {


    //insert at Start
    if(position == 1) {
        insertAtHead(head, d);
        return;
    }

    Node* temp  = head;
    int cnt = 1;

    while(cnt < position-1) {
        temp = temp->next;
        cnt++;
    }

    //inserting at Last Position
    if(temp -> next == NULL) {
        insertAtTail(tail,d);
        return ;
    }

    //creating a node for d
    Node* nodeToInsert = new Node(d);

    nodeToInsert -> next = temp -> next;

    temp -> next = nodeToInsert;
}

Node* reverseLinkedList(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
}

void print(Node* &head) {

    if(head == NULL) {
        cout << "List is empty "<< endl;
        return ;
    }
    Node* temp = head;

    while(temp != NULL ) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

int main(){

Node* node1 = new Node(10);
Node* head = node1;
Node* tail = node1;

insertAtPosition(tail,head,2,20);
insertAtPosition(tail,head,3,30);
insertAtPosition(tail,head,4,40);
insertAtPosition(tail,head,5,50);
insertAtPosition(tail,head,6,60);

print(head);

//head and tail are thoroughly updated through out.

Node* result = reverseLinkedList(head);
print(result);

    return 0;
}