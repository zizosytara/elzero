#include <iostream>
using namespace std;
#define MAX_SIZE 101
class Stack{
private:
    int A[MAX_SIZE];
    int top = -1;

public:
    void Push(int x)
    {
        if (top == MAX_SIZE - 1)
        {
            printf("Error : stack overflow\n");
            return;
        }
        A[++top] = x;
    }
    void Pop()
    {
        if (top == -1)
        {
            printf("Error : No element to pop\n");
            return;
        }
        top--;
    }
    void Print()
    {
        for (int i = 0; i <= top; i++)
        {
            printf("%d ", A[i]);
        }
        printf("\n");
    }
    int Top()
    {
        return A[top];
    }
    bool Empty()
    {
        if (top == -1)
            return true;
        else
            return false;
    }
};
