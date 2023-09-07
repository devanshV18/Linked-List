#include<iostream>
using namespace std;

void insertAtposn(Node* &head,int position,int d){
    if(position ==1){
        insertAtHead(head,d);
        return;
    }
    

    Node* temp = head;
    int cnt =1; //on first node
   
    while(cnt<position -1){
        temp =temp->next;
        cnt++;
    }

    if(temp->next =NULL){
        insertAtTail(tail,d);
        return;
    }
    
    Node* nodetoinsert = new Node(d);
    nodetoinsert->next = temp -> next;
    temp -> next = nodetoinsert;

}


//Deletion of nodes either by value or position

//position starts from 1 to n-1 if we want to delete third node go to second node and play the pointer game

void deleteNode(int position, Node* &head){
   
   //deleting first or start node -> move head by a position and free the start node
    if(position==1){
        Node* temp = head;
        head = head -> next;
        delete temp; //freeing memory using destructor as temp is a heap content
    }

    else{


    }
}

















int main()[



]