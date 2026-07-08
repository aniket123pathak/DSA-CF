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
        // rem = 0 , 1 , 2 = 9 7 8  => 3 3 3 1 3 3 2 3 3 => 12 10 11 => 4 4 4 
        
        ll hao = 0;
        while(n>2){
            ll rem = n%3;
            if(rem==0){
                hao+=(n/3);
                n/=3;
            }
            else{
                ll temp = (n-rem)/3;
                hao+=temp;
                n=(temp+rem);
            }
        }
        cout<<hao<<endl;
        
        return;
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