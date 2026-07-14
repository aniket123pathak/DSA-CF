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
        if(n==1){
            cout<<1<<endl;
            return;
        }
        if(n==2){
            cout<<-1<<endl;
            return;
        }

        // 1 + 2 + 3 + 6 + 12 + 24
        // 24 + 24 = 42
        //lol. 1 2 3 6 12 24 48...

        cout<<1<<" "<<2<<" "<<3<<" ";
        ll cur = 6;
        ll mul = 1;

        for(i=4;i<=n;i++){
            cout<<cur*mul<<" ";
            cur*=2;
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