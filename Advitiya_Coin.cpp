#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,k,i;
        cin>>n>>k;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        ll curMn = -1;
        ll curMx = -1;
        ll trade = 0;
        for(i=0;i<n;i++){
            if(curMn==-1&&curMx==-1){
                curMn=curMx=a[i];
            }
            if(curMx-a[i]-k>0 || a[i]-curMn-k>0){
                trade++;
                curMx=curMn=-1;
                continue;
            }
            else{
                curMx=max(curMx,a[i]);
                curMn=min(curMn,a[i]);
            }
        }
        cout<<trade<<endl;
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