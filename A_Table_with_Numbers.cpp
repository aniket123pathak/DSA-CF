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
        ll n,i,l,h;
        cin>>n>>h>>l;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        ll mx = max(l,h);
        ll mn = min(l,h);
        
        ll kam=0,jyada=0;
        for(i=0;i<n;i++){
            if(a[i]<=mn){
                kam++;
                continue;
            }
            if(a[i]>mn&&a[i]<=mx){
                jyada++;
            }
        }
        ll ans3 = 0;
        if(kam>jyada){
            ans3 = jyada+(kam-jyada)/2;
        }
        else{
            ans3=kam;
        }
        ll ans1 = kam/2;//1 3
                        // 4 4 5 6
        cout<<max(ans1,ans3)<<endl;

        


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