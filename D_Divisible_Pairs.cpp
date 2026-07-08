#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,x,y;
        cin>>n>>x>>y;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        ll ans = 0;
        // so the first derivation...
        // (ai-aj)%y == ai%y-aj%y=0 == ai%y=aj%y
        map<ll,vector<ll>>mp;
        for(i=0;i<n;i++){
            mp[a[i]%y].push_back(a[i]);
        }
        //for first condition
        // ai%x+aj%x = x
        for(auto tr : mp){
            vector<ll> temp = tr.second;
            map<ll,ll>mpX;
            for(i=0;i<temp.size();i++){
                mpX[temp[i]%x]++;
            }

            for(auto trX : mpX){
                ll rem = trX.first;
                if(rem==0||(rem==x/2&&x%2==0)){
                    ll nums = trX.second;
                    ans+=(nums*(nums-1))/2;
                    trX.second=0;
                }
                else{
                    ll nums = trX.second;
                    ll others = mpX[x-rem];
                    ans+=nums*others;
                    mpX[x-rem]=0;
                }
            }
        }
        cout<<ans<<endl;
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