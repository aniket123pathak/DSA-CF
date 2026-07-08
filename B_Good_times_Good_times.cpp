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
        bool check = false;
        ll pw = 10;

        while(!check){
            set<ll>st;
            ll val = pw+1;
            ll temp = n*val;
            while(temp>0){
                st.insert(temp%10);
                temp/=10;
            }
            if(st.size()<=2){
                cout<<val<<endl;
                return;
            }   
            pw*=10;
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