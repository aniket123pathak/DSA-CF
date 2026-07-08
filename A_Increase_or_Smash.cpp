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
        vector<bool>hash(101,false);
        for(i=0;i<n;i++){
           cin>>a[i];
        }

        ll mn = *min_element(a.begin(),a.end());
        ll cnt = 0;
        for(i=0;i<n;i++){
            if(a[i]!=mn && !hash[a[i]]){
                cnt++;
                hash[a[i]]=true;
            }
        }
        cout<<cnt*2+1<<endl;
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