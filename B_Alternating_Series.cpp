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
        if(n%2==0){
            for(i=0;i<n;i++){
                if(i%2==0){
                    cout<<-1<<" ";
                }
                else{
                    if(i==n-1){
                        cout<<2<<" ";
                        break;
                    }
                    cout<<3<<" ";
                }
            }
        }
        else{
            for(i=0;i<n;i++){
                if(i%2==0){
                    cout<<-1<<" ";
                }
                else{
                    cout<<3<<" ";
                }
            }
        }
        cout<<endl;
        
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