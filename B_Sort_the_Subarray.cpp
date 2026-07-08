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
        vector<ll>b(n);
        for(i=0;i<n;i++){
           cin>>b[i];
        }
        vector<ll>pr;
        for(i=0;i<n;i++){
            if(i==0){
                pr.push_back(i+1);
                continue;
            }
            if(b[i]>=b[i-1]){
                continue;
            }
            else{
                pr.push_back(i);
                if(i!=n-1){
                    pr.push_back(i);
                }
                
            }
        }
        if(b[n-1]>=b[n-2]){
            pr.push_back(n);
        }
        ll mx = 0;
        for(i=0;i<pr.size();i++){
            mx = max(mx , pr[i+1]-pr[i]);
            i++;
        }
        for(i=0;i<pr.size();i++){
            if(mx==pr[i+1]-pr[i]){
                cout<<pr[i]<<" "<<pr[i+1]<<endl;
                return;
            }
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