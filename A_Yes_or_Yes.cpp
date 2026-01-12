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
        n= s.length();
        ll county=0;
        ll countn=0;

        for(i=0;i<n;i++){
            if(s[i]=='Y'){
                county++;
                if(county>1){
                    cout<<"NO\n";
                    return;
                }
            }
        }

            cout<<"YES\n";
        

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