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
        vector<ll>a(n);
        ll sum = 0;
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        sum=a[0];
        ll check = false;
        for(i=1;i<n;i++){
            if(check){
                sum+=a[i];
                check=false;
            }
            else{
                sum-=a[i];
                check=true;
            }
        }
        cout<<sum<<endl;
        
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