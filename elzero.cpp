#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* head=NULL;
void Insert(int num){
Node* newNode= new Node();
newNode->data=num;
if(head==NULL){
    head=newNode;
    newNode->next=NULL;
    return;
}
Node*temp=head;
while(temp->next!=NULL){
    temp=temp->next;
}
temp->next=newNode;
newNode->next=NULL;
}

void insertRec(int num){
Node* newNode= new Node();
newNode->data=num;

}

void Display(){
    Node*current=head;
    while(current!=NULL){
        cout<<current->data<<'\t';
        current=current->next;
    }
}
void Delete(){
    Node*current=head;
    Node*temp;
    while(current!=NULL){
        temp=current->next;
        delete current;
        current=temp;
    }
    head=NULL;
}




int main (){

    Display();
    Delete();
    return 0;
}