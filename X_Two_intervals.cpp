#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll l1,r1,l2,r2;
        cin>>l1>>r1>>l2>>r2;

        if(l1<l2&&r1<l2){
            cout<<-1<<endl;
            return;
        }
        if(l2<l1&&r2<l1){
            cout<<-1<<endl;
            return;
        }
        ll l = 0;
        if(l1>l2){
            l = l1;
        }
        else{
            l = l2;
        }
        ll r = 0;
        if(r2>r1){
            r = r1;
        }
        else{
            r = r2;
        }

        cout<<l<<" "<<r<<endl;
        
        
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    s.solve();
    return 0;
}