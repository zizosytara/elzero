#include<iostream>
using namespace std;
class Stack{
    private:
       struct Node{
             int data;
             Node* link;
       };
       Node* head;
public:
       Stack():head(nullptr){}
       void Push(int val){
           Node* newNode = new Node();
           newNode->data = val;
           newNode->link = head;
           head = newNode;
       }
       void Pop(){
           if(head == nullptr){
               cout<<"Stack is empty.\n";
               return;
           }
           Node* temp = head;
           head = head->link;
           delete temp;
       }
       void Print(){
           Node* current = head;
           while(current != nullptr){
                cout<<"["<<current->data<<"] -> ";
                current = current->link;
           }
           cout<<"NULL\n";
       }
       ~Stack(){
              while(head != nullptr){
                   Pop();
              }
       }
};
int main(){
   Stack list;
   Stack arr;
   cout<<"\033[34m";
   list.Push(10);
   list.Push(30);
   list.Push(99);
   list.Print();
   arr.Push(100);
   arr.Push(200);
   arr.Push(300);
   arr.Print(); 
   cout<<"\033[0m";

    return 0;
}