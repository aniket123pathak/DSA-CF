#include <iostream>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,ro,x,d;
        cin>>ro>>x>>d>>n;
        string s;
        cin>>s;

        ll contest = 0;
        for(i=0;i<n;i++){
            if(s[i]=='1'){
                contest++;
                ro = max((ll)0,ro-d);
            }
            else{
                if(ro<x){
                    contest++;
                    ro = max((ll)0,ro-d);
                }
            }
        }
        cout<<contest<<endl;
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