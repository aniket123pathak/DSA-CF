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
        map<ll,ll>mp;
        for(i=0;i<n;i++){
           cin>>a[i];
           sum+=a[i];
           mp[a[i]]++;
        }
        vector<ll>ans;
        for(i=0;i<n;i++){
            mp[a[i]]--;
            sum-=a[i];
            if(sum%2==0 && mp[sum/2]!=0){
                ans.push_back(i+1);
            }
            mp[a[i]]++;
            sum+=a[i];
        }
        if(ans.size()==0){
            cout<<0<<endl;
        }
        else{
            cout<<ans.size()<<endl;
            for(i=0;i<ans.size();i++){
                cout<<ans[i]<<" ";
            }
            cout<<endl;
        }

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