#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
    public:
        void solve()
        {
            long long n,m,i,j;
            cin>>n>>m>>i>>j;
            if(m>n){
                cout<<"1"<<" "<<m<<" "<<n<<" "<<"1"<<endl;
            }
            else{
                cout<<"1"<<" "<<"1"<<" "<<n<<" "<<m<<endl;
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