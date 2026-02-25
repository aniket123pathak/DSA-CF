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

        bool check = false;
        for(i=0;i<n-1;i++){
            if(a[i]!=a[i+1]){
                check = true;
                break;
            }
        }
        if(!check){
               cout<<"NO\n";
            return;
        }
        sort(a.rbegin(),a.rend());
        if(a[0]==a[1]){
            cout<<"YES\n";
            cout<<a[0]<<" ";
            cout<<a[n-1]<<" ";
            for(i=1;i<n-1;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
            return;
        }
        else{
            cout<<"YES\n";
            for(i=0;i<n;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
            return;
        }
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