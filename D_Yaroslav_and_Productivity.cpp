#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,m,j;
        cin>>n>>m;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        vector<ll>b(m);
        for(i=0;i<m;i++){
           cin>>b[i];
        }
        sort(b.begin(),b.end());
        ll fixedSum = 0;
        for(i=b[m-1];i<n;i++){
            fixedSum+=a[i];
        }
        
        vector<ll>seg(m);
        ll temp = 0;
        for(i=0;i<m;i++){
            ll blckM = 0;
            while(temp<b[i]){
                blckM+=a[temp];
                temp++;
            } 
            seg[i]=abs(blckM);
        }
        ll sm = 0;
        for(i=0;i<m;i++){
            sm+=seg[i];
        }

        cout<<fixedSum+sm<<endl;


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