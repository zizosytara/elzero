#include<iostream>
#include<stack>
#include<queue>
#include<array>
#include<vector>
#include<list>
#include<deque>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
class Heap{
    protected:
       struct Node{
             int data;
             Node* link;
       };
       Node* head;

public:
       Heap():head(nullptr){}
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
       ~Heap(){
              while(head != nullptr){
                   Pop();
              }
       }
};
class Stack{
     private:
            struct Node{
                int data;
                int next;
            };
            static const int MAX_SIZE = 100;
            Node nodes[MAX_SIZE];
            int head ;
            int freeIndex ;
    public:
           Stack() : head(-1), freeIndex(0) {}
           void Push(int val){
                if(freeIndex >= MAX_SIZE){
                    cout<<"Stack overflow.\n";
                    return;
                }
                nodes[freeIndex].data = val;
                nodes[freeIndex].next = head ;
                head = freeIndex;
                freeIndex++;
           }
           void Pop(){
               if(head == -1){
                 cout<<"Stack is empty\n";
                 return;
               }
               head = nodes[head].next;
           }
           void Print(){
             int current = head;
             while(current != -1){
                cout<<"["<<nodes[current].data<<"] -> ";
                current = nodes[current].next;
             }
             cout<<"NULL\n";
           }
};
class Reverse_String_Stack {
    protected:
        static const int MAX_SIZE = 101;
        char A[MAX_SIZE];
        int top = -1;
    public:
        void Push(int x){
            if(top == MAX_SIZE-1){
                cout<<"Stack overflow.\n";
                return;
            } 
            A[++top] = x;    
        }
        void Pop(){
            if(top == -1){
                cout<<"Stack is empty.\n";
                return;
            }
            top--;
        }
        int Top(){
            return A[top];
        }
        bool IsEmpty(){
            if(Top() == 0){
            return true;
        }
    }
    void Reverse(char c[],int n){
        Reverse_String_Stack s;
        for(int i=0; i<n; i++){
            s.Push(c[i]);
        }
        for(int i=0 ;i<n ;i++){
            c[i] = s.Top();
            s.Pop();
        }
    }
    void Print(){
        for(int i = 0; i <= top; i++){
            printf("[%d] -> ",A[i]);
        }
        printf("NULL\n");
    }
};
int main(){
   cout<<"\033[34m";
   Stack s;
   Heap h;
   Reverse_String_Stack rss;
   h.Push(10);
   h.Push(30);
   h.Push(40);
   h.Print();
   h.Pop();
   h.Pop();
   h.Print();
   cout<<"---------"<<endl;
   s.Push(10);
   s.Push(30);
   s.Push(40);
   s.Print();
   s.Pop();
   s.Pop();
   s.Print();
   cout<<"---------"<<endl;
   rss.Push(10);
   rss.Push(30);
   rss.Push(40);
   rss.Print();
   rss.Pop();
   rss.Pop();
   rss.Print();
   cout<<"\033[0m";

    return 0;
}