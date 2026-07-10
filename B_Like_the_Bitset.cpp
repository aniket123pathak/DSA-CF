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

        ll maxConse = 0;
        for(i=0;i<n;i++){
            if(s[i]=='1'){
                ll temp = 0;
                while(i<n&&s[i]=='1'){
                    temp++;
                    i++;
                }
                maxConse = max(maxConse,temp);
            }
        }
        if(maxConse>=k){
            cout<<"NO\n";
            return;
        }

        cout<<"YES\n";
        ll first = 1;
        ll last = n;

        for(i=0;i<n;i++){
            if(s[i]=='0'){
                cout<<last<<" ";
                last--;
            }
            else{
                cout<<first<<" ";
                first++;
            }
        }
        cout<<endl;
        
        
        
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