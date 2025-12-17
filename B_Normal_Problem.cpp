#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            string a;
            cin>>a;

            for(int i = a.length()-1;i>=0;i--){
                if(a[i]=='q'){
                    cout<<"p";
                }
                else if(a[i]=='p'){
                    cout<<"q";
                }
                else{
                    cout<<'w';
                }
            }
            cout<<endl;
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