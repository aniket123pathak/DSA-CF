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
        string s;
        cin>>s;
        if(n==1){
            cout<<"NO\n";
            return;
        }
        stack<char>st;
        for(i = 0; i < n; i++) {
            if(!st.empty() && st.top() == s[i]) {
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        if(st.empty()){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
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