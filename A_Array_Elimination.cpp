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
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        ll check = true;
        for(i=0;i<n-1;i++){
            if(a[i]!=a[i+1]){
                check = false;
                break;
            }
        }

        if(check){
            if(a[0]==0){
                for(i=1 ;i<=n;i++){
                    cout<<i<<" ";
                }
                cout<<endl;
                return;
            }
            else{
                vector<ll>ans;
                for(i=1;i*i<=n;i++){
                    if(n%i==0){
                        ans.push_back(i);
                        if(n/i!=i){
                            ans.push_back(n/i);
                        }
                    }
                }
                sort(ans.begin(),a.end());
                for(i=0;i<ans.size();i++){
                    cout<<ans[i]<<" ";
                }
                cout<<endl;
                return;
            }   
        }
        cout<<1<<" ";
        if(n%2!=0){
            cout<<endl;
            return;
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