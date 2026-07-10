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
        vector<ll>hash(101,0);
        for(i=0;i<n;i++){
           cin>>a[i];
           hash[a[i]]++;
        }
        vector<ll>ans;
        for(i=1;i<=100;i++){
            if(hash[i]>0){
                ans.push_back(hash[i]);
            }
        }

        sort(ans.begin(),ans.end());

        ll final = 0;
        ll sz = ans.size();
        for(i=0;i<sz;i++){
            final = max(final,ans[i]*(sz-i));
        }
        cout<<final<<endl;

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