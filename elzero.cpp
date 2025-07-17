//recursion can get back history like git log
#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* next;
};
Node* head=NULL;

Node* Insert(Node* head,int num){
Node* newNode= new Node();
newNode->data=num;
if(head==NULL){
    head=newNode;
}
Node*temp=head;
while(temp->next!=NULL){
    temp=temp->next;
}
temp->next=newNode;
newNode->next=NULL;
return head;
}

void Reverse(Node*current){
 if(current->next == NULL){
    head=current;
    return;
}
Reverse(current->next);//recursive call
Node* temp=current->next;
temp->next=current;
current->next=NULL;
}


void revDisplay(Node* current){
 if(current == NULL){
    return;
 }
 revDisplay(current->next);//recursive call
 cout<<current->data<<'\t';//print value
}

void Display(Node* current){
 if(current == NULL)return;
 cout<<current->data<<'\t';//print value
 Display(current->next);//recursive call
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
    
    head=Insert(head,1);
    head=Insert(head,2);
    head=Insert(head,3);
    Display(head);

    cout<<'\n';

    revDisplay(head);

    Reverse(head);
    cout<<'\n';
    Display(head);
    cout<<'\n';
    revDisplay(head);

    Delete();
    return 0;
}