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
        for(i=0;i<n;i++){
           cin>>a[i];
        }

        vector<ll> b;
        for(i = 0; i < n; i++) {
            if(i == 0 || a[i] != a[i-1]) {
                b.push_back(a[i]);
            }
        }
        
        ll cnt = 0;
        ll m = b.size();
        //soic caould cos ths r ssme i csmmot di the dsae wjhile i 
        
        for(i=0;i<m;i++){
            bool check1=false;
            if(i==0||b[i-1]>b[i]){
                check1=true;
            }
            
            bool check2=false;
            if(i==m-1||b[i+1]>b[i]){
                check2=true;
            }
            
            if(check1&&check2){
                cnt++;
            }
        }
        
        if(cnt==1){
            cout<<"YES\n";
        } 
        else{
            cout<<"NO\n";
        }
        
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