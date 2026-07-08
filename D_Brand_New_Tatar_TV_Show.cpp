#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,k;
        cin>>n>>k;
        vector<ll>a(n);
        map<ll,ll>mp;
        for(i=0;i<n;i++){
           cin>>a[i];
           mp[a[i]]++;
        }
        sort(a.begin(),a.end());
        // 0 <= y-x <= k.  =>   x <= y <= x+k
        if(mp[a[n-1]]%2==0){
            cout<<"YES\n";
            return;
        }

        ll j = n-1;
        while(j>=0){
            if(mp[a[j]]%2==1){
                ll temp = a[j]-k;
                ll lb = lower_bound(a.begin(),a.end(),temp)-a.begin();
                if(a[lb]!=a[j]){
                    cout<<"YES\n";
                    return;
                }
                else{
                    j--;
                }
            }
            else{
                cout<<"YES\n";
                return;
            }
        }
        cout<<"NO\n";


        
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