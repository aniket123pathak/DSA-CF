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
        string s;
        cin>>s;

        vector<ll>hash(n);

        for(i=0;i<n;i++){
            hash[i]=s[i]-'a';
        }

        bool check = true;
        ll idx=0;

        for(i=1;i<n;i++){
            if(hash[i-1]>hash[i]){
                check = false;
                idx=i-1;
                break;
            }
        }

        if(check){
            cout<<"NO\n";
            return;
        }
        else{
            cout<<"YES\n";
            cout<<idx+1<<" "<<idx+2<<" ";
            return;
        }
    }
};

int main() {
    Solution s;
    s.solve();
    return 0;
}