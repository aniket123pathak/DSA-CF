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
        vector<ll> score(n + 1, 0);
        ll cc = k;
        
        while(cc>0){
            for (i =1;i<=n&&cc>0;i++){
                score[i]+=cc;
                cc--;
            }
            for (i =n;i>=1&&cc>0;i--){
                score[i] += cc;
                cc--;
            }
        }
        
        ll mx = *max_element(score.begin(),score.end());
        cout<<mx<<endl;
        
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