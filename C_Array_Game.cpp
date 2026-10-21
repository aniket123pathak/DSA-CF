#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,k,j;
        cin>>n>>k;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        if(k>=3){
            cout<<0<<endl;
            return;
        }
        sort(a.begin(),a.end());
        if(k==1){
            ll mn = a[0];
            ll mn2 = INT64_MAX;
            for(i=0;i<n-1;i++){
                mn2 = min(mn2 , abs(a[i]-a[i+1]));
            }
            cout<<min(mn2,mn)<<endl;
            return;
        }
        ll mn = a[0];
        for(i=0;i<n-1;i++){
            mn=min(mn,abs(a[i+1]-a[i]));
        }

        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                ll diff= abs(a[j]-a[i]);
                ll lb=lower_bound(a.begin(),a.end(),diff)-a.begin();
                if(lb!=n){
                    mn=min(mn,abs(a[lb]-diff));
                }                
                if(lb!=0){
                    mn=min(mn,abs(diff-a[lb-1]));
                }
            }
        }
        cout<<mn<<endl;

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