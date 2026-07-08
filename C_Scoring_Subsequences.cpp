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
        
        // lol i knew it will give tle......lets try the binary search

        for(i=0;i<n;i++){
            ll left = 0;
            ll right = i;
            ll curK = i+1;
            ll cst = 0;
            while(left<=right){
                ll mid = left+(right-left)/2;
                ll curD = curK-mid;
                if(a[mid]>=curD){
                    right = mid-1;
                    cst = curD;
                }
                else{
                    left = mid+1;
                }
            }
            cout<<cst<<" ";
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