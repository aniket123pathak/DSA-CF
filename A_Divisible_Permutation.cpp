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

        ll first = 1;
        ll last = n;

        for(i=1;i<=n;i++){
            if(first>last){
                break;
            }
            if(i%2!=0){
                a[i-1]=last;
                last--;
            }
            else{
                a[i-1]=first;
                first++;
            }
        }

        for(i=n-1;i>=0;i--){
            cout<<a[i]<<" ";
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