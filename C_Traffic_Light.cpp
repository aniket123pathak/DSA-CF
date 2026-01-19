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
        char c;
        cin>>c;
        string s;
        cin>>s;
        if(c=='g'){
            cout<<"0\n";
            return;
        }
        string newStr=s+s;
        ll lg = 0;
        for(i=n-1;i>=0;i--){
            if(s[i]=='g'){
                lg=i;
                break;
            }
        }
        lg=i+n;
        ll mx = 0;
        ll left = 0 ;
        for(i=0;i<n;i++){
            if(s[i]==c){
                mx=max(mx,lg-i);
            }
        }

        cout<<lg<<endl;

        

        

        
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