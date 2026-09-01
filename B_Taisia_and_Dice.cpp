#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,s,r;
        cin>>n>>s>>r;
        ll mxVal = s-r;
        // so now we have to give sequence qith sum = s and sequnce pf n numbers in which max value is mxVal
        n--;
        cout<<mxVal<<" ";
        while(r>0&&n>0){
            if(n==1){
                cout<<r<<endl;
                return;
            }
            for(i=mxVal;i>=1;i--){
                if((r-i)/(n-1)>0){
                    cout<<i<<" ";
                    r-=i;
                    n--;
                    break;
                }
            }
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