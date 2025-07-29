#include<iostream>
using namespace std;
struct Node {
      int data;
      Node *prev, *next;
};

Node *head=NULL;
void insert(int value, int position){
    if(head == NULL){
        if(position != 1){
          cout<<"\nOut of range !\n ";
          return;
        }
        Node *newNode = new Node(); // in C :  struct Node *newNode = (*Node) malloc(sizeof(Node));
        newNode->data = value;
        head = newNode;
        newNode->prev = NULL;
        newNode->next = NULL;
    }
    
}
void insertStart(int value){
    Node *newNode = new Node();
    newNode->data = value;
    if(head == NULL){
        head = newNode;
        newNode->prev = NULL;
        newNode->next = NULL;
        return;
    }
    newNode->prev = NULL;
    newNode->next = head;
    (newNode->next)->prev = newNode; //if(head != NULL) head->prev = newNode;  ((this is very safer if someone modify the code))
    head = newNode;
}
void insertBack(int value){
    Node *newNode = new Node();
    newNode->data = value;
    if(head == NULL){
      head = newNode;
      newNode->next = NULL;
      newNode->prev = NULL;
      return;
    }
    Node *temp = head;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = NULL;
}
void Display(){
    Node *current = head;

}
int main(){


    return 0;
}