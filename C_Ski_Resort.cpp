#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:

    void solve()
    {
        ll n,i,k,q;
        cin>>n>>k>>q;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        vector<ll>days;
        ll temp = 0;
        for(i=0;i<n;i++){
            if(a[i]<=q){
                while(i<n&&a[i]<=q){
                    temp++;
                    i++;
                }
                if(temp>=k){
                    days.push_back(temp);
                    temp=0;
                }
            }
        temp=0;
        }
        ll ans = 0;
        for(i=0;i<days.size();i++){
            ans+=((days[i]-k+1)*(days[i]-k+2))/2;
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