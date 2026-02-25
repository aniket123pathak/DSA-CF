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
        cin>>n;
        vector<char>a(n);
        ll countD = 0;
        for(i=0;i<n;i++){
           cin>>a[i];
           if(a[i]=='.'){
            countD++;
           }
        }
        for(i=0;i<n-2;i++){
            if(a[i]=='.'&&a[i+1]=='.'&&a[i+2]=='.'){
                cout<<2<<endl;
                return;
            }
        }
        cout<<countD<<endl;
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