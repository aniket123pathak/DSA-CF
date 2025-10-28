#include<iostream>
using namespace std;

class Node{ 
    public :
        int data;
        Node* next;
        Node(int data){
            this->data = data;
            next = NULL;
        }
};

class Stack {
    private : 
        Node* top;
    
    public:
        Stack(){
            top=NULL;
        }

    void push(int element){
        Node *newNode = new Node(element);
        newNode->next=top;
        top = newNode;
    }
    int pop(){
        if(!isEmpty()){
            int d = top->data;
            top=top->next;
            return d;
        }
    }
    bool isEmpty(){
        return top==NULL;
    }
    int peek(){
        if(!isEmpty()){
            return top->data;
        }
    }
};

int main(){
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    s.push(5);
    s.push(6);
    cout<<"\nPopped Element : "<<s.pop();
    cout<<"\nTop Element : "<<s.peek();
    return 0;
}