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
        vector<ll>freq(1001);
        ll sum =0;
        for(i=0;i<n;i++){
           cin>>a[i];
           freq[a[i]]++;
           sum+=a[i];
        }
        ll mx = *max_element(freq.begin(),freq.end());

        if(mx-2<=n-mx){
            cout<<sum<<endl;
            return;
        }
        ll val = 0;
        for(i=1;i<=1001;i++){
            if(freq[i]==mx){
                val =i;
                break;
            }
        }
        ll rem = mx-2 - (n-mx);

        sum -= rem * val;
        
        cout<<sum<<endl;
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