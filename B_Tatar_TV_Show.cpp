#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,k;
        cin>>n>>k;
        string s;
        cin>>s;
        bool check1 =0;
        for(i=0;i<n;i++){
            if(s[i]=='1'){
                check1=true;
            }
        }
        if(!check1){
            cout<<"YES\n";
            return;
        }
        if(k==n){
            cout<<"NO\n";
            return;
        }
        for(i=0;i<min(k,n-k);i++){
            ll j = 0;
            ll cnt1 = 0;
            ll cnt = 0;
            while(i+(j*k)<n){
                if(s[i+j*k]=='1'){
                    cnt1++;
                }
                j++;
                cnt++;
            }
            if(cnt1%2!=0){
                cout<<"NO\n";
                return;
            }
        }
        ll untouchable = 0 ;
        
        for(i=n-k;i<k;i++){
            if(s[i]=='1'){
                cout<<"NO\n";
                return;
            }
        }
        cout<<"YES\n";
        
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