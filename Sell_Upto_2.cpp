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
        if(n==1){
            cout<<a[0]<<endl;
        }

        vector<pair<ll,ll>>pr(n);
        for(i=0;i<n;i++){
            pr[i].first=a[i];
            pr[i].second=a[i]*2;
        }
        ll cost = 0;
        ll cost2=0;
        vector<ll>days;

        for(i=0;i<n-1;i++){
            if(a[i+1]>a[i]){
                days.push_back(a[i]);
            }
            else{
                days.push_back(a[i]);
            }
        }
        if(!days.empty()){
            if()
        }

        cout<<cost<<endl;



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