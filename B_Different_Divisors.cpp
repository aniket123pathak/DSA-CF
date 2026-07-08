#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    bool isPrime(ll num) {
        if(num<2)return false;
        for(ll i= 2;i*i<=num;i++){
            if(num%i==0) return false;
        }
        return true;
    }

    void solve()
    {
        ll n,i;
        cin>>n;
        ll p =n+1;
        while(!isPrime(p)) {
            p++;
        }
        
        ll q=p+n;
        while (!isPrime(q)) {
            q++;
        }
        cout<<p*q<<endl;
        
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