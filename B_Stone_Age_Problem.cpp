#include <iostream>
#include <vector>
#include <algorithm>
#include<map>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,q;
        cin>>n>>q;
        vector<ll>a(n);
        ll sum = 0;
        for(i=0;i<n;i++){
           cin>>a[i];
           sum+=a[i];
        }
        ll prev = 0;
        bool check = false;
        map<ll,ll>mp;
        for(i=0;i<q;i++){
            ll t;
            cin>>t;
            if(t==1){
                ll rpl=0;
                ll x =0;
                cin>>rpl>>x;
                if(mp.find(rpl-1)!=mp.end()){
                    sum-=a[rpl-1];
                    a[rpl-1]=x;
                    sum+=x;
                }
                else{
                    if(!check){
                        sum-=a[rpl-1];
                    }
                    else{
                        sum-=prev;
                    }
                    sum+=x;
                    a[rpl-1]=x;
                    mp[rpl-1]++;
                }
                cout<<sum<<endl;
            }
            else{
                check = true;
                ll x;
                cin>>x;
                prev=x;
                cout<<n*x<<endl;
                sum=n*x;
                mp.clear();
            }
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
        s.solve();
    return 0;
}