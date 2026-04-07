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
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        ll p;
        cin>>p;
        ll bit = a[p-1];
        bool check = true;
        for(i =0;i<n;i++)
        {
            if(a[i]!=bit){
                check=false;
            }
        }
        if(check){
            cout<<0<<endl;
            return;
        }
        ll invBit = -1;
        if(bit==1){
            invBit=0;
        }
        else{
            invBit = 1;
        }
        ll firInvBit = -1;
        for(i=0;i<n;i++){
            if(a[i]==invBit){
                firInvBit=i;
                break;
            }
        }
        ll lastInvBit=-1;
        for(i=n-1;i>=0;i--){
            if(a[i]==invBit){
                lastInvBit=i;
                break;
            }
        }
        ll count1=0;
        ll count2=0;
        ll cb = -1;
        for(i=firInvBit;i<p;i++){
            if(a[i]!=cb){
                count1++;
                cb=a[i];
            }
        }
        cb = -1;
        for(i=lastInvBit;i>=p-1;i--){
            if(a[i]!=cb){
                count2++;
                cb=a[i];
            }
        }

        cout<<max(count1,count2)<<endl;
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