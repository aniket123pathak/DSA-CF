#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
           long long n;
           cin>>n;
           if(n%3!=0){
            cout<<"First\n";
           }
           else{
            cout<<"Second\n";
           }
        }
};

int main () {
    Solution s;
    int tc;
    cin>>tc;
    while(tc-->0)
    {
        s.solve();
    }
    return 0;
}