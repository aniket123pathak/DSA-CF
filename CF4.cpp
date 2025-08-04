#include<iostream>
#include<string>
using namespace std;

class Solution {
    public:
        void Door(string a ,string b,string c)
        {
           cout<<a[0]<<b[0]<<c[0]<<endl;
        }
};

int main () {
    Solution s;
    int tc;
    cin>>tc;
    string a,b,c;
    for(int i = 0 ;i<tc;i++)
    {
        cin>>a>>b>>c;
        s.Door(a,b,c);
    }
    return 0;
}