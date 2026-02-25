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
        ll count2 =0;
        for(i=0;i<n;i++){
           cin>>a[i];
           if(a[i]==2){
            count2++;
           }
        }
        if(count2==0){
            cout<<1<<endl;
            return;
        }
        if(count2%2!=0){
            cout<<-1<<endl;
            return;
        }
        ll cnt=0;
        for(i=0;i<n;i++){
            if(a[i]==2){
                cnt++;
            }
            if(cnt==count2/2){
                cout<<i+1<<endl;
                return;
            }
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