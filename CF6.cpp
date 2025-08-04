#include<iostream>
#include<string>
using namespace std;

class Solution {
    public:
        void Long(string a)
        {
            if(a.length()>=11)
            {
                cout<<a[0]<<a.length()-2<<a[a.length()-1];
            }
            else{
                cout<<a;
            }
            cout<<endl;
        }
};

int main () {
    Solution s;
    int tc;
    cin>>tc;
    string a;
    for(int i = 0 ;i<tc;i++)
    {
        cin>>a;
        s.Long(a);
    }
    return 0;
}