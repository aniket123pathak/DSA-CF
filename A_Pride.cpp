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
        ll cnt1 = 0;
        for(i=0;i<n;i++){
           cin>>a[i];
           if(a[i]==1){
            cnt1++;
           }
        }
        
        vector<bool>check(n,false);
        ll pr = 0;
        for(i=0;i<n-1;i++){
            if(a[i]==1 || check[i]){
                continue;
            }
            for(j=i+1;j<n;j++){
                if(a[j]==1 || check[j]){
                    continue;
                }
                ll gd = __gcd(a[i],a[j]);
                if(gd==1){
                    pr++;
                    check[i]=true;
                    check[j]=true;
                    break;
                }
            }
        }
        if(pr==0 && cnt1==0){
            cout<<-1<<endl;
            return;
        }

        ll rem = n - cnt1 - pr;

        cout<<rem<<endl;
        
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    s.solve();
    return 0;
}