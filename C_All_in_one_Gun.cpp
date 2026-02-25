#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,h,k;
        cin>>n>>h>>k;
        vector<ll>a(n);
        vector<ll>sm(n);
        unordered_map<ll,ll>mp;
        ll sum = 0;
        for(i=0;i<n;i++){
           cin>>a[i];
           sum+=a[i];
            mp[a[i]]++;
        }
        ll div = h/sum;
        ll time = div*n;

        if(div>0){
            time+=(div-1)*k;
        }
        h=h%sum;

        if(h==0){
            cout<<time<<endl;
            return;
        }

        sm[0]=a[0];
        for(i=1;i<n;i++){
            sm[i]=sm[i-1]+a[i];
        }

        vector<ll>mxx(n);
        mxx[n-1]=a[n-1];
        for(i=n-2;i>=0;i--){
            mxx[i]=max(mxx[i],mxx[i+1]);
        }
        vector<ll>mnn(n);
        mxx[0]=a[0];
        for(i=1;i<n;i++){
            mnn[i]=min(mnn[i],mnn[i-1]);
        }

        for(i=0;i<n;i++){
            
        }
 
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