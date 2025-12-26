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
        ll n,k,i,count=0;
        cin>>n>>k;
        vector<ll>a(n);
        bool check = false;
        for(i=0;i<n;i++){
            cin>>a[i];
            if(a[i]%k==0){
                check = true;
            }
            if(a[i]%2==0){
                count++;
            }
        }
        if(check){
            cout<<"0\n";
            return;
        }
        ll minKI = INT64_MAX;
        if(k==4){
            if(count>1){
                minKI=0;
            }
            else if(count==1){
                minKI=1;
            }
            else{
                minKI=2;
            }
        }
        
        for(i=0;i<n;i++){
            minKI=min(minKI,(k-(a[i]%k)));
        }


        cout<<minKI<<endl;
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