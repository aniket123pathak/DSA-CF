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
        char c;
        cin>>c;
        string s;
        cin>>s;

        ll left = 0;
        ll right = n-1;
        ll ans = 0;
        while(left<right){
            if(s[left]!=s[right]){
                if(s[left]!=c){
                    ans++;
                }
                if(s[right]!=c){
                    ans++;
                }
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