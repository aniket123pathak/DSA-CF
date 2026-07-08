#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,k,b,s;
        cin>>n>>k>>b>>s;
        vector<ll>ans(n);
        ll mn =k*b;
        ll mx = mn +(k-1)*(n);

        if(s<mn||s>mx){
            cout<<-1<<endl;
            return;
        }

        ans[n-1]=k*b;
        s-=k*b;

        ll temp = 0;
        for(i=0;i<n;i++){
            if(s>0){
                if(s>=k-1){
                    ans[i]+=k-1;
                }
                else{
                    ans[i]+=s;
                }
                s-=min(k-1,s);
            }
            else{
                break;
            }
        }

        for(i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<endl;

        
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