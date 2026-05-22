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
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        ll maxSum = a[0];
        ll currSum = a[0];

        for(i=1;i<n;i++) {
            if(abs(a[i-1])%2!=abs(a[i])%2){
                currSum=max(a[i],currSum+a[i]);
            }
            else{
                currSum=a[i];
            }
            maxSum=max(maxSum,currSum);
            
        }
        cout<<maxSum<<endl;
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