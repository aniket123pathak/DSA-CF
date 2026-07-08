#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll a,b,x;
        cin>>a>>b>>x;
        
        vector<ll>aDiv;
        vector<ll>bDiv;

        ll temp1 = a;
        while(temp1>=0){
            aDiv.push_back(temp1);
            if(temp1==0){
                break;
            }
            temp1/=x;
        }

        ll temp2 = b;
        while(temp2>=0){
            bDiv.push_back(temp2);
            if(temp2==0){
                break;
            }
            temp2/=x;
        }
        ll n = aDiv.size();
        ll m = bDiv.size();
        ll finalAns = INT64_MAX;
        for(ll i=0;i<n;i++){
            for(ll j=0;j<m;j++){
                finalAns=min(finalAns,abs(aDiv[i]-bDiv[j])+i+j);
            }
        }

        cout<<finalAns<<endl;
        
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