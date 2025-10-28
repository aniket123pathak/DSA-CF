#include<iostream>
using namespace std;

class Stack {
    private :
        int top;
        int *arr;
        int size;

    public:
        Stack(int size){
            this->size = size;
            arr = new int[size];
            top = -1;
        }

        void push(int element){
            if(size-top>1){
                top++;
                arr[top]=element;
            }
            else{
                cout<<"\nStack is Full..";
            }
        }

        int pop() {
            if(top!=-1){
                int d = arr[top];
                top--;
                return d;
            }
            else{
                cout<<"\nStack is Empty..";
            }
        }

        bool isEmpty(){
            if(top==-1){
                return true;
            }
            else{
                return false;
            }
        }

        int peek(){
            if(!isEmpty()){
                return arr[top];
            }
            else{
                cout<<"\nStack is Empty..";
            }
        }
};

int main () {
    Stack s(5);
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