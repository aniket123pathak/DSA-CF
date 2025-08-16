#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            int n,m,p,q;
            cin>>n>>m>>p>>q;

            if(n%p==0){
                if((n/p)*q == m){
                    cout<<"Yes\n";
                    return;
                }
                else{
                    cout<<"No\n";
                    return;
                }
            }
            else{
                cout<<"Yes\n";
                return;
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

/*5
3 2 2 1
1 1 1 1
5 4 2 3
10 7 5 2
4 4 1 3*/