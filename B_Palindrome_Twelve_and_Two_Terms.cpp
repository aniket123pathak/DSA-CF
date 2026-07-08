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
        
        if(n%12==0){
            cout<<0<<" "<<n<<endl;
            return;
        }

        // a + b = n
        // b = n - a
        //  b%10 == 0
        // (n-a)%12 == 0
        // if we found n%10 then rem can be 0 to 11 by taking that value n - rem and all a as 0 1 upto 9 then we got answeebecause all are alindrome except 10 fro 10 it will be 22 because 22%12 == 10
        ll rem = n%12;
        ll a = rem;
        if(rem==10){
           a=22;
        }
        if(n>=a){
            cout<<a<<" "<<n-a<<endl;
            return;
        } 
        

        cout<<-1<<endl;
        
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