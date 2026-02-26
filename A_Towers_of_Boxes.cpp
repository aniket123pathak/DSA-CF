#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,m,d,i;
        cin>>n>>m>>d;

        if(d<m){
            cout<<n<<endl;
            return;
        }

        ll height = (d/m)+1;
        if(n%height==0){
            cout<<n/height<<endl;
        }
        else{
            cout<<(n/height)+1<<endl;
        }
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