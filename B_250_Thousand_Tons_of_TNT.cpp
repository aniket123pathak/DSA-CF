#include <iostream>
#include <vector>
#include <algorithm>
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
        vector<long long>pf(n);
        pf[0]=a[0];
        for(i=1;i<n;i++){
            pf[i]=pf[i-1]+a[i];
        }
        vector<ll>div;
        ll mxDiff = *max_element(a.begin(),a.end())-*min_element(a.begin(),a.end());
        for(i=2;i<=n/2;i++){
            if(n%i==0){
                div.push_back(i);
            }
        }

        for(i=0;i<div.size();i++){
            vector<long long>temp(n/div[i]+1,-1);
            temp[1]=pf[div[i]-1];
            for(long long j = 2;j<=n/div[i];j++){
                temp[j]=pf[j*div[i]-1]-pf[(j-1)*div[i]-1];
            }
            sort(temp.begin(),temp.end());
            mxDiff=max(mxDiff,temp[n/div[i]]-temp[1]);
        }
        cout<<mxDiff<<endl;
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