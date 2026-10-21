#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        string s;
        cin>>s;

        ll n = s.length();
        ll checkFloat = false;
        ll checkInt = false;
        ll checkPoint = 0;
        string in = "";
        for(ll i=0;i<n;i++){
            if(s[i]=='.'){
                checkPoint = i;
                break;
            }
            in+=s[i];
        }
        string f = "0.";
        for(ll i=checkPoint+1;i<n;i++){
            f+=s[i];
            if(s[i]-'0'>0){
                checkFloat = true;
            }
        }

        if(checkFloat){
            cout<<"float ";
            cout<<in<<" "<<f<<endl;
        }
        else{
            cout<<"int ";
            cout<<in<<endl;
        }
        
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    s.solve();
    return 0;
}