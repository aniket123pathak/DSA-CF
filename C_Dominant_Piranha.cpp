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
        bool check = true;

        for(i=0;i<n-1;i++){
            if(a[i]!=a[i+1]){
                check = false;
                break;
            }
        }
        if(check){
            cout<<-1<<endl;
            return;
        }
        ll mx = *max_element(a.begin(),a.end());

        if(a[0]==mx){
            if(a[1]<mx){
                cout<<1<<endl;
                return;
            }
        }
        if(a[n-1]==mx){
            if(a[n-2]<mx){
                cout<<n<<endl;
                return;
            }
        }

        for(i=1;i<n-1;i++){
            if(a[i]==mx){
                if(a[i-1]<mx||a[i+1]<mx){
                    cout<<i+1<<endl;
                    return;
                    
                }
            }
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