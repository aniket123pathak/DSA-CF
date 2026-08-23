#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,j,k;
        cin>>n>>k;
       vector<vector<ll>>a(n,vector<ll>(n,0));
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                cin>>a[i][j];
            }
        }
        ll cnt = 0;
        for(i=0;i<n/2;i++){
            for(j=0;j<n;j++){
                if(a[i][j]!=a[n-i-1][n-j-1]){
                    cnt++;
                }
            }
        }   
        ll mid = n/2;
        if(n%2!=0){
            for(j=0;j<n/2;j++){
                if(a[mid][j]!=a[mid][n-j-1]){
                    cnt++;
                }
            }
        }
       
        if(cnt>k){
            cout<<"NO\n";
            return;
        }

        ll req = k - cnt;

        if(n%2==0){
            if(req%2!=0){
                cout<<"NO\n";
                return;
            }
        }
        
        
        cout<<"YES\n";
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