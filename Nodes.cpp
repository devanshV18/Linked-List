#include<iostream>
using namespace std;

class Node{

public:

int data;
Node *next;

//assigning a data and NULL address to the node using constructor

Node(int dataInp){
    this -> data = dataInp;
    this -> next = NULL;
}
   
};

int main(){

// creating a node in heap

Node* node1 = new Node(5);  // new keyword along with Node creates a node class in heap that can contain an address and a address to next node and returns the class address which we are storing in a pointer of Node type named as node1

cout<<node1->data<<endl;
cout<<node1->next<<endl;


}



