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
        vector<string>a(n);
        for(i=0;i<n;i++){
            cin>>a[i];
        }
        ll r = 0;
        ll c = 0;
        ll check = false;
        for(i=0;i<n;i++){
            for(ll j=0;j<n;j++){
                if(a[i][j]=='1'){
                    r=i;
                    c=j;
                    check = true;
                    break;
                }
            }
            if(check){
                break;
            }
        }
        ll cntR = 0;
        for(i=r;i<n;i++){
            if(a[i][c]=='1'){
                cntR++;
            }
        }
        ll cntC = 0;
        for(i=c;i<n;i++){
            if(a[r][i]=='1'){
                cntC++;
            }
        }
        if(cntR==cntC){
            cout<<"SQUARE\n";
        }
        else{
            cout<<"TRIANGLE\n";
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