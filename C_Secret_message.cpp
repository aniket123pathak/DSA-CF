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
        vector<string>a(k);
        for(i=0;i<k;i++){
           cin>>a[i];
        }

        vector<ll>hash(26);
        
        vector<ll>div;
        for(i=1;i*i<=n;i++){
            if(n%i==0){
                div.push_back(i);
            }
        }
        div.push_back(n);


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