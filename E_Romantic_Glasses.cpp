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
        vector<ll>pfOdd(n,0);
        vector<ll>pfEven(n,0);
        map<ll,ll>mpDiff;
        bool check = false;
        pfOdd[0]=a[0];
        pfEven[0]=0;
        mpDiff[pfOdd[0]-pfEven[0]]++;
        for(i=1;i<n;i++){
            pfEven[i]+=pfEven[i-1];
            pfOdd[i]+=pfOdd[i-1];
            if(i%2==0){
                pfOdd[i]+=a[i];
            }
            else{
                pfEven[i]+=a[i];
            }
            mpDiff[pfOdd[i]-pfEven[i]]++;
            if(mpDiff[pfOdd[i]-pfEven[i]]>1 || pfOdd[i]-pfEven[i]==0){
                cout<<"YES\n";
                return;
            }
        }
        cout<<"NO\n";
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