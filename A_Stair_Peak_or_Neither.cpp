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
        ll a,b,c;
        cin>>a>>b>>c;

        if(a<b && b<c){
            cout<<"STAIR\n";
        }
        else if(a<b&&b>c){
            cout<<"PEAK\n";
        }
        else{
            cout<<"NONE\n";
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