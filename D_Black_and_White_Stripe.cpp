#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,k;
        cin>>n>>k;
        string s;
        cin>>s;
        ll wc = 0;
        vector<ll>whtCnt(n);

        for(i=0;i<n;i++){
            if(s[i]=='W'){
                wc++;
            }
            whtCnt[i]=wc;
        }

        ll first = 0;
        ll last = k-1;
        ll mn = whtCnt[last];
        first++;
        last++;

        while(last<n){
            mn=min(mn,whtCnt[last]-whtCnt[first-1]);
            first++;
            last++;
        }
        cout<<mn<<endl;
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