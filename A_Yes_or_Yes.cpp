#include <iostream>
#include <vector>
#include <algorithm>
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
        if(s[0]=='y'||s[0]=='Y'){
            if(s[1]=='e'||s[1]=='E'){
                if(s[2]=='s'||s[2]=='S'){
                    cout<<"YES\n";
                    return;
                }
            }
        }
        cout<<"NO\n";

          
        

    }
};

int main() {
    Solution s;
    int tc;
    cin >> tc;
    while (tc-- > 0)
    {
        s.solve();
    }
    return 0;
}