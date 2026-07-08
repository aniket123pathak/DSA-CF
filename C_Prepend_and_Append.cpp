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
        string s;
        cin>>s;
        ll ans = 0;
        if(n%2==0){
            ans=0;
        }
        else{
            ans=1;
        }
        ll left = 0;
        ll right = n-1;
        while(left<=right){
            if(s[left]==s[right]){
                cout<<n-2*(left)<<endl;
                return;
            }
            left++;
            right--;
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