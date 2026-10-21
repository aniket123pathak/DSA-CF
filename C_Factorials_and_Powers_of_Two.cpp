#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    ll shatShut(ll i,vector<ll>& a,ll cnt,ll target){
        if(i<0){
            ll remBit =__builtin_popcountll(target);
            return cnt+remBit;
        }

        ll notTake = shatShut(i-1,a,cnt,target);
        ll take = INT64_MAX;
        if(a[i]<=target){
            take = shatShut(i-1,a,cnt+1,target-a[i]);
        }

        return min(take,notTake);
    }

    void solve()
    {
        ll n,i;
        cin>>n;
        vector<ll>ans;
        ll fact = 2;
        for(i=3;i<15;i++){
            fact *= i;
            ans.push_back(fact);
        }
        
        ll sz = ans.size();
        ll final = shatShut(sz-1,ans,0,n);
        if(final==INT64_MAX){
            cout<<-1<<endl;
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
