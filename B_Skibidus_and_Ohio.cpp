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
        string s;
        cin>>s;
        n=s.length();
        bool check = false;
        for(i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                check=true;
            }
        }
        if(check){
            cout<<1<<endl;
        }
        else{
            cout<<n<<endl;
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