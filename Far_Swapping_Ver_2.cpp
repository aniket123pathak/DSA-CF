#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,j;
        cin>>n;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        vector<ll>a2 = a;
        ll cnt1 = 0;
        for(i=0;i<n;i++){
            for(j=0;j<n-1;j++){
                if(a[j]>a[j+1]&&abs(a[j]-a[j+1])>1){
                    swap(a[j],a[j+1]);
                    cnt1++;
                }
            }
        }
        ll cnt2 = 0;
        for(i=0;i<n;i++){
            for(j=0;j<n-1;j++){
                if(a2[j]<a2[j+1]&&abs(a2[j]-a2[j+1])>1){
                    swap(a2[j],a2[j+1]);
                    cnt2++;
                }
            }
        }
        cout<<cnt1+cnt2<<endl;
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