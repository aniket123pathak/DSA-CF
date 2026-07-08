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
        string s;
        cin>>s;
        ll mn = 0;
        for(i=0;i<n;i++){
            if(s[i]=='1'){
                mn++;
            }
        }
        if(n<=2){
            if(mn==0){
                cout<<1<<endl;
                return;
            }
            else{
                cout<<mn<<endl;
                return;
            }
        }
        if(s[0]=='0'&&s[1]=='0'){
            if(s[2]=='0'){
                s[1]='1';
            }
            else{
                s[0]='1';
            }
            mn++;
        }

        if(s[n-1]=='0'&&s[n-2]=='0'){
            if(s[n-3]=='0'){
                s[n-2]='1';
            }
            else{
                s[n-1]='1';
            }
            mn++;
        }
        for(i=1;i<n-1;i++){
            if(s[i-1]=='0'&&s[i]=='0'&&s[i+1]=='0'){
                if(i+2<n&&s[i+2]=='0'){
                    s[i+1]='1';
                } 
                else{
                    s[i]='1';
                }
                mn++;
            }
        }
        cout<<mn<<endl;


        
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