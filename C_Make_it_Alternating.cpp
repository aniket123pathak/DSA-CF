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
        string s;
        cin>>s;
        n=s.length();
        ll cnt1 = 0;
        ll cnt0 = 0;
        char prev = '2';
        for(i=0;i<n;i++){
            if(s[i]=='1'){
                if(prev!=s[i]){
                    cnt1++;
                    prev='1';
                }
            }
            else{
                if(prev!=s[i]){
                    cnt0++;
                    prev='0';
                }
            }
        }
        ll mnOp = n-(cnt1+cnt0);
        cout<<mnOp<<" "; 

        vector<ll>seg1;
        ll temp = 0;
        for(i=0;i<n;i++){
            if(s[i]=='1'){
                temp++;
            }
            else{
                if(temp>1){
                    seg1.push_back(temp);
                }
                temp=0;
            }
        }
        if(temp>1){
            seg1.push_back(temp);
        }

        vector<ll>seg0;
        ll temp1 = 0;
        for(i=0;i<n;i++){
            if(s[i]=='0'){
                temp1++;
            }
            else{
                if(temp1>1){
                    seg0.push_back(temp1);
                }
                temp1=0;
            }
        }
        if(temp1>1){
            seg0.push_back(temp1);
        }
        ll ans =1;
        for(i=0;i<seg1.size();i++){
            ans =(ans*seg1[i])%998244353;
        }
        for(i=0;i<seg0.size();i++){
            ans =(ans*seg0[i])%998244353;
        }
        
        for(i=1;i<=mnOp;i++){
            ans =(ans*i)%998244353;
        }
        cout<<max((ll)1,ans)<<endl;
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