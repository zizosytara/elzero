#include <iostream>
using namespace std;
struct Node{
      int data;
      Node* next;
};
int Count();
void Delete(int order);
Node* head=NULL;
void Insert(int value,int order){
Node* newNode=new Node();
newNode->data=value;
newNode->next=NULL;

if(order==1){
    newNode->next=head;
    head=newNode;
    return;
}
Node*temp=head;
for(int i=1;i<order-1;i++){
    temp=temp->next;
}
newNode->next=temp->next;
temp->next=newNode;
}
int Count(){
   Node* current=head;
   int counter=0;
   while(current != NULL){
    counter++;
    current=current->next;
   } 
   return counter;
}
void Display(){
    Node* current=head;
            while(current!=NULL){
             cout<<current->data<<'\t';
             current=current->next;
             
            }
        
    cout<<"\nThe number of Nodes = "<<Count()<<'\n';
  
}

Node* Reverse(){
Node *current,*nextNode,*prev;
current=head;
prev=nextNode=NULL;

while(current!=NULL){
    nextNode=current->next;
    current->next=prev;
    prev=current;
    current=nextNode;
}
head=prev;
return head;
}
int main (){
Insert(1,1);
Insert(2,2);
Insert(3,3);
Insert(4,3);
Display();
Reverse();
Display();
Delete(2);
Delete(1);
Delete(3);
Delete(4);

    return 0;
}





void Delete(int order){
    Node* current = head;
    Node* temp = head;
if(order==1){
    head=current->next;
    current->next=NULL;
    delete current;
    return;
}
for(int i=1;i<order-1;i++){
    current= current->next;
}
temp= current->next;
(temp->next!=NULL)? current->next=temp->next : current->next=NULL;
temp->next=NULL;
delete temp;
    
}    