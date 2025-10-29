#include<iostream>
#include<stack>
using namespace std;

int main (){
    string a;
    cin>>a;
    int length = a.length();
    stack<char>c;
    for(int i = 0 ;i<length;i++){
        c.push(a[i]);
    }

    string reversedString = "";

    for(int i = 0 ;i<length;i++){
        reversedString = reversedString + c.top();
        c.pop();
    }

    cout<<"Original String : "<<a<<endl;
    cout<<"Reversed String : "<<reversedString<<endl;

    return 0;
}
