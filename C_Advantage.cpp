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
        vector<ll>temp = a;
        sort(a.begin(),a.end());
        bool check = false;
        if(a[n-1]==a[n-2]){
            check=true;
        }
        ll mx = a[n-1];
        ll mx2 = -1;
        if(!check){
            mx2=a[n-2];
        }
        if(!check){
            for(i=0;i<n;i++){
                if(temp[i]==mx){
                    cout<<temp[i]-mx2<<" ";
                }
                else{
                    cout<<temp[i]-mx<<" ";
                }
            }
        }
        else{
            for(i=0;i<n;i++){
                cout<<temp[i]-mx<<" ";
            }
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