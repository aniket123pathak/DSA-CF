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

        vector<bool>ans(n+1,false);
        ll cur = 1;
        ans[1]=true;
        for(i=0;i<n;i++){
            if(s[i]=='R'){
                if(ans[cur+1]){
                    ans[cur+1]=false;
                }
                else{
                    ans[cur+1]=true;
                }
                cur+=1;
            }
            else{
                if(ans[cur-1]){
                    ans[cur-1]=false;
                }
                else{
                    ans[cur-1]=true;
                }
                cur-=1;
            }
        }
        ll ansF = 0;
        for(i=1;i<=n;i++){
            if(ans[i]){
                ansF++;
            }
        }
        cout<<ansF<<endl;
        
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