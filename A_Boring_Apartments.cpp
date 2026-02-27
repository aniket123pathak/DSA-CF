#include <bits/stdc++.h>
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
        ll noOfDig = 0;
        ll rem = -1;
        ll x = n;
        while(x>0){
            rem=x%10;
            noOfDig++;
            x/=10;
        }
        ll cur = 0;
        if(noOfDig==1){
            cur=1;
        }
        else if(noOfDig==2){
            cur+=3;
        }
        else if(noOfDig==3){
            cur+=6;
        }
        else{
            cur+=10;
        }
        cout<<cur+((rem-1)*10)<<endl;
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