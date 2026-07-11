#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,j;
        cin>>n;
        ll prs = 0;
        j=1;
        for (i=1;i<=n;i++) {
            while(j<i) {
                cout<<"? "<<j<<" "<<i<<endl;
                cout.flush();
            
                string ans;
                cin>>ans;
            
                if(ans=="No") {
                    j++;
                } 
                else{
                    break;
                }
            }
            prs+=(i-j);
        }
        cout<<"! "<<prs<<endl;
        cout.flush();
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