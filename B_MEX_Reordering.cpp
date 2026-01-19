#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]
/*
2 6 2 0 0 5

0 1 2 
*/

class Solution {
public:
    void solve()
    {
        ll n,i;
        cin>>n;
        vector<ll>a(n);
        vector<ll>hash(101,0);
        ll count0 = 0;
        for(i=0;i<n;i++){
           cin>>a[i];
           hash[a[i]]++;
           if(a[i]==0){
            count0++;
           }
        }
        if(count0==0){
            cout<<"NO\n";
            return;
        }
        if(count0==1){
            cout<<"YES\n";
            return;
        }

        if(hash[1]>0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
        

        
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