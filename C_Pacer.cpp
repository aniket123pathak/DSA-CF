#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,m;
        cin>>n>>m;
        ll ans = 0;
        ll curSide = 0;
        ll prevMnut =0;
        for(i=0;i<n;i++){
            ll mnut = 0;
            ll side = 0;
            cin>>mnut>>side;
            ll diff = mnut - prevMnut;

            if(side!=curSide){
                ans++;
                curSide=side;
                diff--;
            }
            if(diff%2==0){
                ans+=diff;
            }
            else{
                ans+=(diff-1);
            }
            prevMnut=mnut;
        }
        ans+=(m-prevMnut);
        cout<<ans<<endl;
        
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