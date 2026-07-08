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
        if(n==1||n==2){
            cout<<-1<<endl;
            return;
        }
        sort(a.begin(),a.end());
        
        for(i=0;i<n-2;i++){
            if(a[i]==a[i+1]&&a[i+1]==a[i+2]){
                cout<<a[i]<<endl;
                return;
            }
        }
        cout<<-1<<endl;
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