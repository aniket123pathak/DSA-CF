#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout<<'NO'<<endl
#define yes cout<<'YES'<<endl
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
        ll cnt1 = 0;
        for(i=0;i<n;i++){
            if(s[i]=='1'){
                cnt1++;
            }
        }
        ll mx = cnt1;
        ll mn = 0;
        for(i=1;i<n-1;i++){
            if(s[i]=='0'){
                if(s[i-1]=='1'&&s[i+1]=='1'){
                    s[i]='1';
                    mx++;
                }
            }
        }
        for(i=1;i<n-1;i++){
            if(s[i]=='1'){
                if(s[i-1]=='1'&&s[i+1]=='1'){
                    s[i]='0';
                }
            }
        }
        for(i=0;i<n;i++){
            if(s[i]=='1'){
                mn++;
            }
        }

        cout<<mn<<" "<<mx<<endl;

        
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