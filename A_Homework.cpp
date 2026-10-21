#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,m;
        cin>>n;
        string a;
        cin>>a;
        cin>>m;
        string b;
        cin>>b;
        string c;
        cin>>c;

        string vlad,diana;
        ll cur = 0;
        for(i=0;i<m;i++){
           
                if(c[i]=='V'){
                    vlad+=b[cur];
                }
                else{
                    diana+=b[cur];
                }
                cur++;
            
        }
        reverse(vlad.begin(),vlad.end());

        vlad+=a;
        vlad+=diana;

        cout<<vlad<<endl;

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