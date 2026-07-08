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
        sort(a.rbegin(), a.rend());
        bool check = true;
        for(i=0;i<n-2;i++){
            if(a[i]%a[i+1]!=a[i+2]) {
                check=false;
                break;
            }
        }
        if(check){
            cout<<a[0]<<" "<<a[1];
            cout<<endl;
        } 
        else{
            cout<<-1;
            cout<<endl;
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