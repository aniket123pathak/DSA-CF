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
        for(i=0;i<n;i++){
           cin>>a[i];
           sum+=a[i];
        }
        ll l =0;
        ll sm1 = -1;
        for(i=0;i<n;i++){
            sm1+=a[i];
            if(sm1%3==0){
                l = i;
                break;
            }
        }
        ll r=0;
        ll sm2 =-1;
        for(i=l+1;i<n;i++){
            sm2+=a[i];
            if(sm2%3==0){
                r = i;
                break;
            }
        }
        ll sm3 = sum - (sm1+sm2);

        if(sm3%3==0){
            if(l!=0&&r!=0){
                cout<<l+1<<" "<<r+1<<endl;
                return;
            }
        }
        cout<<0<<" "<<0<<endl;
        
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