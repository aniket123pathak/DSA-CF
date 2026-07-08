#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout<<'NO'<<endl
#define yes cout<<'YES'<<endl
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        string s;
        cin>>s;
        ll cnta=0;
        ll cntb=0;
        for(ll i=0;i<5;i++){
            if(s[i]=='A'){
                cnta++;
            }
            else{
                cntb++;
            }
        }
        if(cnta>cntb){
            cout<<"A"<<endl;
        }
        else{
            cout<<"B"<<endl;
        }
        
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