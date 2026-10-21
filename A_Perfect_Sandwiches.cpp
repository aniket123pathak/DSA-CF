#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll a,b;
        cin>>a>>b;
        // 2 1 2 1. 2 2
        // 8 7
        // 2 1 2 1 2 1 2 4
        // 2 1 2 1 4 5
        // 2 1 6 6
        // 8 7

        // 8 6
        // 2 1 2 1 2 1 2 3
        // 2 1 2 1 4 4
        // 2 1 
        if(a<=b){
            cout<<-1<<endl;
            return;
        }

        ll diff=a-b;
        
        if(b>a/2){
            cout<<diff<<endl;
        }
        else{
            cout<<b<<endl;
        }

        
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    int tc;
    cin >> tc;
    while (tc-- > 0)
    {
        s.solve();
    }
    return 0;
}