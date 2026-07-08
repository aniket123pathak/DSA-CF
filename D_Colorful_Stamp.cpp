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
        vector<char>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        if(n==2){
            ll wcnt = 0;
            if(a[0]=='W'){
                wcnt++;
            }
            if(a[1]=='W'){
                wcnt++;
            }
            if(wcnt==1){
                cout<<"NO\n";
                return;
            }
            if(a[0]=='B'){
                if(a[1]=='B'){
                    cout<<"NO\n";
                    return;
                }
            }
            else{
                if(a[1]=='R'){
                    cout<<"NO\n";
                    return;
                }
            }
        }

        for(i=0;i<n-2;i++){
            if((a[i]=='W'&&a[i+1]=='R'&&a[i+2]=='W')||((a[i]=='W'&&a[i+1]=='B'&&a[i+2]=='W'))){
                cout<<"NO\n";
                return;
            }
        }
        for(i=0;i<n-3;i++){
            if((a[i]=='W'&&a[i+1]=='B'&&a[i+2]=='B'&&a[i+3]=='W')||(a[i]=='W'&&a[i+1]=='R'&&a[i+2]=='R'&&a[i+3]=='W')){
                cout<<"NO\n";
                return;
            }
        }
        bool red = false;
        bool blue = false;

        for(i=0;i<n;i++){
            if(a[i]=='W'){
                if((red&&!blue)||(!red&&blue)){
                    cout<<"NO\n";
                    return;
                }
                red=false;
                blue=false;
            }
            else{
                if(a[i]=='R'){
                    red=true;
                }
                else{
                    blue=true;
                }
            }
        }
        if(a[n-1]!='W'){
            if((red&&!blue)||(!red&&blue)){
                    cout<<"NO\n";
                    return;
                }
        }
        if((a[0]=='R'||a[0]=='B')&&a[1]=='W'){
            cout<<"NO\n";
            return;
        }
        if((a[n-1]=='R'||a[n-1]=='B')&&a[n-2]=='W'){
            cout<<"NO\n";
            return;
        }
        cout<<"YES\n";
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