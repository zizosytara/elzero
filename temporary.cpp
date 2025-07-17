#include <iostream>
using namespace std;
struct Node{
      int data;
      Node* next;
};
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
    int value,order;
        if(head==NULL){
            cout<<"Empty List\n";
            
        }
        else{ current=head;
            while(current!=NULL){
             cout<<current->data<<'\t';
             current=current->next;
             
            }
        }
    cout<<"\nThe number of Nodes = "<<Count()<<endl;
}

void Reverse(){
Node*current=head;
Node*prev=current->next;
Node*after=prev->next;

current->next=NULL;
while(current !=NULL){
    prev->next=current;
    current=prev;
    prev=after;
    after=after->next;
}
head=current;
cout<<"\nAfter reverse\n";
}
int main (){
Insert(1,1);
Insert(2,2);
Insert(3,3);
Insert(4,3);
Display();
cout<<endl;
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