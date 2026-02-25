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
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        bool check = true;
        vector<ll>b(n);
        for(i=0;i<n;i++){
           cin>>b[i];
           if(a[i]!=b[i]){
            check = false;
           }
        }
        if(check){
            cout<<"Yes\n";
            return ;
        }
        for(i=0;i<n;i++){
            if(a[i]>b[i]){
                cout<<"No\n";
                return;
            }
        }

        for(i=1;i<n;i++){
            if(a[i]<b[i]&&a[i-1]==a[i]){
                cout<<"No\n";
                return;
            }
        }

        for(i=1;i<n;i++){
            if(a[i]<b[i]&&a[i-1]<=b[i]&&a[i-1]>=a[i]){
                cout<<"No\n";
                return;
            }
        }

        cout<<"Yes\n";
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