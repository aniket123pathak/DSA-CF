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

        // au-av>bu-bv. is same as au-bu>av-bv lol..
        vector<ll>diff(n);
        for(i=0;i<n;i++){
            diff[i]=a[i]-b[i];
        }

        ll mx = *max_element(diff.begin(),diff.end());
        ll cnt = 0;
        vector<ll>ans;
        for(i=0;i<n;i++){
            if(mx==diff[i]){
                cnt++;
                ans.push_back(i+1);
            }
        }
        cout<<cnt<<endl;
        for(i=0;i<cnt;i++){
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