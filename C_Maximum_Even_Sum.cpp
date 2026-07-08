#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll a,b,i;
        cin>>a>>b;
        swap(a,b);
        ll ans = -1;
        if((a+b)%2==0){
            ans = a+b;
        }
        if(a%2==1&&b%2==1){
            ans = max(ans,a*b+1);
        }
        else{
            if(a%2==0&&(a%4==0||b%2==0)){
                ans=max(ans,(ll)2+(a*b)/(ll)2);
            }
        }
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