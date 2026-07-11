#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,c;
        cin>>n>>c;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        sort(a.begin(),a.end());
        ll cur = 1;
        ll rem = n;
        for(i=0;i<n;i++){
            ll j=0;
            while(j<n&&a[j]*cur<=c){
                j++;
            }
            if(j==0){
                break;
            }
            else {
                a[j-1]=INT64_MAX;
                rem--;
            }
            cur*=2;
            sort(a.begin(),a.end());
        }
        cout<<rem<<endl;
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