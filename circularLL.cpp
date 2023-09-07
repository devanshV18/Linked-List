#include<iostream>
using namespace std;



class Node {
    public:
    int data;
    Node* next;

    //constructor
    Node(int d){
        this -> data = d;
        this -> next = NULL;
    }

    ~Node(){
        int value = this -> data;
        if(this -> next == NULL){
            delete next;
            next = NULL;
        }
        cout<< "Memory is free for the node with thwe data "<<value<<endl;
    }
};




//since in a circular linked ist , first and last position cant be defined , hence an element argument is sent in the insert function and the new node is always added just after the node with the node with the data equal to element argument
 
//Full fledged generic code for insertion : -


void insertnode(Node* &tail,int element,int d){
    //Empty list case:
    if(tail == NULL){
    Node* newNode = new Node(d);
    tail = newNode;
    newNode -> next = newNode;
    }

    else{ //Assuming Non empty list and element is present in the linked list.
        Node* curr = tail; //an already wagging tail iykyk lol

        while(curr -> data != element){
            curr = curr -> next;
        }
        //when present element is found and curr points at the element node after that;-
        Node* temp = new Node(d);
        temp -> next = curr -> next;
        curr -> next = temp;
    }
}







void print(Node* tail){
    Node* temp = tail;

    // while(tail -> next != temp){   // this fails in case of single node so we use do while instead
    //     cout << tail -> data << " ";
    //     tail = tail -> next;
    // }
    do{
        cout << tail -> data << " ";
        tail = tail -> next;
    }while(tail != temp);
}






void deleteNode(Node* tail,int value){

    //empty List
    if(tail == NULL) {
        cout<< " list is empty" << endl;
        return;
    }


    else{
        
        //non empty

        Node* prev = tail;
        Node* curr = prev -> next; // prev points one posn behind than curr so that current points to the node to be deleted and prev points to the node just before the node to be deleted.

        while(curr -> data != value){
            prev = curr;
            curr = curr -> next;
        }


        prev -> next = curr -> next;

        // to handle a single node linked list optimally for avoiding a segmentation fault when we delete the only present node and try to use print function

        if(curr == prev){
            tail = NULL;
        }

        //>=2 elemnt CLL

        if(tail == curr){
            tail = prev;    //to tackle segmentation fault
        }
        curr -> next = NULL;
        delete curr;
    }

}





int main(){

Node* tail = NULL;
// empty list case

insertnode(tail,5,3);
//print(tail);

insertnode(tail,3,5);
insertnode(tail,5,7);
insertnode(tail,7,9);

insertnode(tail,5,6);
deleteNode(tail,7);
print(tail);




return 0;


}