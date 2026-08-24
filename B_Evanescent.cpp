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
        ll f = n;
        ll l = -1;

        char a = s[0];
        for(i=1;i<n;i++){
            if(s[i]!=a){
                f = i;
                break;
            }
        }
        char b = s[n-1];
        for(i=n-2;i>=0;i--){
            if(s[i]!=b){
                l = i;
                break;
            }
        }
        bool check1 = false;
        bool check2 = false;
        for(i=f;i<=l;i++){
            if(s[i]!=s[i-1]&&s[i]!=s[i+1]){
                check1 = true;
                if(s[i-1]==s[i+1]){
                    check2 = true;
                    break;
                }
            }
        }
        ll cnt = 0;
        for(i=0;i<n;i++){
            char cur = s[i];
            cnt++;
            while(i<n&&s[i]==cur){
                i++;
            }
            i--;
        }
        if(check1){
            cnt--;
            if(check2){
                cnt--;
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