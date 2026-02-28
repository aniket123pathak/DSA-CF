#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,a,b;
        cin>>n>>a>>b;
        if(n==1){
            cout<<"Yes\n";
            return;
        }
        if(n==a&&n==b){
            cout<<"Yes\n";
            return;
        }
        if(n-(a+b)>1){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
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