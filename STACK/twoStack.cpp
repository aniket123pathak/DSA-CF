#include<iostream>
using namespace std;

class twoStack{
    private : 
        int top1;
        int top2;
        int size;
        int* arr;

    public:
        twoStack(int size){
            top1=-1;
            top2=size;
            this->size=size;
            arr = new int[size];
        } 

        void push1(int element){
            if(top2-top1>1){
                top1++;
                arr[top1]=element;
            }
        }
        void push2(int element){
            if(top2-top1>1){
                top2--;
                arr[top2]=element;
            }
        }
        int pop1(){
            if(top1!=-1){
                int d = arr[top1];
                top1--;
                return d;
            }
        }
        int pop2(){
            if(top2!=size){
                int d = arr[top2];
                top2++;
                return d;
            }
        }
        int isEmpty(){
            return top2==size && top1==-1;
        }
};

