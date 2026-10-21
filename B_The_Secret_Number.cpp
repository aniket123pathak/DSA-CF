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
        ll x =n;
        ll cur = 1;
        ll div = 10;
        vector<ll>ans;
        ll cnt = 0;
        for(cur=1;cur<=17;cur++){
            if(n%(div+1)==0){
                ans.push_back(n/(div+1));
                cnt++;
            }
            div*=10;
        }
        if(cnt==0){
            cout<<0<<endl;
            return;
        }
        sort(ans.begin(),ans.end());
        cout<<ans.size()<<endl;
        for(i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

        //555
        // 5 500
        
        
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