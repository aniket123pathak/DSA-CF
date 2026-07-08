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
        ll cnt = 0;
        for(i=0;i<n;i++){
            if(a[i]>b[i]){
                ll idx = -1;
                for(ll j = i+1;j<n;j++){
                    if(a[j]<=b[i]){
                        idx=j;
                        break;
                    }
                }
                if(idx==-1){
                    cout<<-1<<endl;
                    return;
                }
                for(ll j=idx;j>i;j--){
                    swap(a[j],a[j-1]);
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
        
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