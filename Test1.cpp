#include<iostream>
using namespace std;
struct Node {
      int data;
      Node *prev, *next;
};

int Count();
Node *head=NULL;

void insert(int value, int position){
    if(position < 1 || position > Count()+1){
        cout<<"\n Out of range\n";
        return;
    }
    Node *newNode = new Node(); // in C :  struct Node *newNode = (*Node) malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    if(head == NULL){
        head = newNode;
        return;
    }
    //------------in start-----------//
    if(position == 1){
        newNode->next = head;
        head->prev = newNode;
        head = newNode;// forget to place head to new
        return;
    }
    //-------------in mid and last------------//
    Node *temp = head;
    for(int i = 1; i < position-1 && temp != NULL; i++){
        temp = temp->next;
    }
    newNode->prev = temp;
    if(newNode->next != NULL){
      (newNode->next)->prev = newNode;
    }
    newNode->next = temp->next;
    temp->next = newNode;

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

void Delete(){
    Node *current = head;
    while(head != NULL){
        current = head->next;
        delete head;
        head = current;
    }
}
void Delete(int position){
    if(head == NULL || position < 1 || position > Count()){
      cout<<"\nInvalid position\n";
      return;
    }
    Node *current = head;
    //----------in start----------------//
    if(position == 1){
        head = current->next;
        if(head != NULL){
            head->prev = NULL;
        }
        current->next = NULL;
        delete current;
        return;
    }
    //-------------in mid or end-------------//
    for(int i = 1 ; i < position ; i++){
        current = current->next;
    }
    if(current->next != NULL){
        (current->next)->prev = current->prev;  
    }
    if(current->prev != NULL){
        (current->prev)->next = current->next;
    }
    delete current;
 
}

void Reverse(){
     Node *current = head;

}
void Reverse(int i){
    
}

int Count(){
Node *counter = head;
int numberNodes = 1;
while(counter->next != NULL){
    counter = counter->next;
    numberNodes++;
}
return numberNodes;
}
void Display(){
    Node *current = head;

}
int main(){

Delete();
    return 0;
}