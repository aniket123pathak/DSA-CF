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
        /*
        j-aj = i-ai
        j-i = aj-ai

        1 2 3 4 5 6
        1 1 5 3
        6 5 4 3 2 1
        */
       sort(a.rbegin(),a.rend());
       for(i=0;i<n;i++){
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