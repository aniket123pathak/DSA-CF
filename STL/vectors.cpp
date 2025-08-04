#include<iostream>
#include<vector>
using namespace std;

void vec () 
{
    vector<int> v;
    v.push_back(20);
    v.push_back(30);
    for(int i=0;1;i++)
    {
        cout<<v[i]<<endl;
    }
}

int main () {
    vec();
    return 0;
}