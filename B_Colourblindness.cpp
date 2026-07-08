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
        ll n,i;
        cin>>n;
        
        string s1, s2;
        cin>>s1>>s2;
    
        for(i=0;i<n;i++) {
        if(s1[i]=='B') s1[i]='G';
        if(s2[i]=='B') s2[i]='G';
    }
    

    if(s1==s2){
        cout<<"YES\n";
    } 
    else{
        cout<<"NO\n";
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