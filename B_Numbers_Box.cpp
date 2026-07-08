#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,j,m;
        cin>>n>>m;
        vector<vector<ll>>a(n,vector<ll>(m,0));
        ll neg = 0;
        ll sum = 0;
        ll mn = 101; 
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                cin>>a[i][j];
                if(a[i][j]<0){
                    neg++;
                }
                mn = min(mn , abs(a[i][j]));
                sum+=abs(a[i][j]);
            }
        }
        
        if(neg%2!=0){
            cout<<sum-2*mn<<endl;
        }
        else{
            cout<<sum<<endl;
        }
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