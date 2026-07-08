#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,k;
        cin>>n>>k;
        string s;
        cin>>s;

        ll tempK = 0;
        ll sleep = 0;
        for(i=0;i<n;i++){
            if(s[i]=='0' && tempK<=0){
                sleep++;
            }
            else if(s[i]=='0'){
                tempK--;
            }
            else{
                tempK=k;
            }
        }
        cout<<sleep<<endl;
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