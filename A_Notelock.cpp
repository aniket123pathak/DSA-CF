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
        string s;
        cin>>s;
        ll cnt = 0;
        ll sm = 0;
        for(i=0;i<k;i++){
            if(s[i]=='1'){
                sm++;
            }
        }
        for(i=0;i<k;i++){
            if(s[i]=='1'){
                cnt++;
                break;
            }
        }
        for(i=k;i<n;i++){
            if(s[i-k]=='1'){
                sm--;
            }
            if(s[i]=='1'){
                if(sm==0){
                    cnt++;
                }
                sm++;
            }
        }
        cout<<cnt<<endl;

        
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