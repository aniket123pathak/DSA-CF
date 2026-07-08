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
        ll chng = 0;
        ll mnS = 0;
        vector<ll>ans;
        for(i=n-1;i>=0;i--){
            if(chng%2==0){
                ll val = a[i];
                if(val>0){
                    chng++;
                    ans.push_back(i+1);
                }
            }
            else{
                ll val = -a[i];
                if(val>0){
                    chng++;
                    ans.push_back(i+1);
                }
            }
        }
        cout<<chng<<endl;
        for(i=0;i<ans.size();i++){
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