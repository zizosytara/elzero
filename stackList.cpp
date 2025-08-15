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
class Reverse_String_Stack{
private:
    char str[101];
public:
    void _strcpy(char* dest,char* src){
         int i =0;
         while(src[i] != '\0'){
             dest[i] = src[i];
             i++;
         }
         dest[i] = '\0';
     }
    int _strlen(const char* s){
        int len = 0;
        while(s[len] != '\0'){
            len++;
        }
        return len;
     }
    void _swap(char& a, char& b){
        char temp = a;
        a = b;
        b = temp;
    }
    void setStr(char* s){
        _strcpy(str, s);
    }
    void Reverse(){
        int n = _strlen(str);
        for(int i = 0 ; i < n/2 ; i++){
            _swap(str[i], str[n - i - 1]);
        }
    }
    void Print(){
        cout<< str << endl; 
    }
};


int main(){
   cout<<"\033[34m";
   Stack s;
   Heap h;
   Reverse_String_Stack rss;
//-------------------------------//
   char input[101];
   cout<<"Enter the String to reverse : "<<endl;
   cin>>input;
   rss.setStr(input);
   rss.Reverse();
   rss.Print();
   
   cout<<"\033[0m";

    return 0;
}