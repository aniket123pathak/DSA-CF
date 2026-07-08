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
        vector<ll>a(n);
        set<ll>st;
        vector<ll>ans;
        ll sz = 0;
        for(i=0;i<n;i++){
           cin>>a[i];
            st.insert(a[i]);
            if(sz<st.size()){
                sz=st.size();
                ans.push_back(i+1);
            }

        }
        if(st.size()>=k){
            cout<<"YES\n";
            for(auto it : ans){
                if(k>0){
                    cout<<it<<" ";
                    k--;
                }
                else{
                    cout<<endl;
                    return;
                }
            }
        }
        else{
            cout<<"NO\n";
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