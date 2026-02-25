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
        bool check = false;
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        ll nm = abs(a[0]);
        for(i=1;i<n;i++){
            if(nm!=abs(a[i])){
                check = true;;
            }
        }
        if(check){
            cout<<"No\n";
            return;
        }
        
        ll chng = 0;
        for(i=0;i<n-1;i++){
            if((a[i]>0&&a[i+1]<0)||(a[i]<0&&a[i+1]>0)){
                chng++;
            }
        }
        if(chng<=1){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
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