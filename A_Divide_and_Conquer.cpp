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
        ll sum = 0;
        ll op1 = INT64_MAX;
        ll op2 = INT64_MAX;
        for(i=0;i<n;i++){
           cin>>a[i];
           sum+=a[i];
           if(a[i]%2!=0){
                ll x=a[i];
                ll cur = 0;
                while(x%2!=0){
                    x/=2;
                    cur++;
                } 
                op1 = min(op1,cur);
           }
           else{
                ll x=a[i];
                ll cur = 0;
                while(x%2==0){
                    x/=2;
                    cur++;
                } 
                op2 = min(op2,cur);
           }
        }
        if(sum%2==0){
            cout<<0<<endl;
            return;
        }
        cout<<min(op1,op2)<<endl;
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