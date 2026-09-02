#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,k,m;
        cin>>n>>k>>m;
        if(k>m){
            cout<<"NO\n";
            return;
        }
        // 1 1 1 1 1 m-(k-1) len = k divisible by m
        cout<<"YES\n";
        for(i=0;i<n;i++){
            if((i+1)%k==0){
                cout<<m-(k-1)<<" ";
            } 
            else{
                cout<<1<<" ";
            }
        }
        cout<<endl;

        
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