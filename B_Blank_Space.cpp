#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i;
        cin>>n;
            vector<ll>a(n);
            for(i=0;i<n;i++){
            cin>>a[i];
            }
            ll cur = 0;
            for(i=0;i<n;i++){
                ll temp = 0;
                if(a[i]==0){
                    while(i<n&&a[i]==0){
                        temp++;
                        i++;
                    }
                    cur=max(cur,temp);
                }
            }
            cout<<cur<<endl;
        
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