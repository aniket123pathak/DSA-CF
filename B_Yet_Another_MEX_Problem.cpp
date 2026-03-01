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
        vector<ll>hash(n+1);
        for(i=0;i<n;i++){
           cin>>a[i];
           hash[a[i]]++;
        }
        // 0 1 2 4 0 3 1  k = 5  =>   0 1 2 4 3 1
        // 0 1 0 1 2 0 k = 2 => 
        vector<vector<ll>>idxs(n+1);
        for(i=0;i<n;i++){
            idxs[a[i]].push_back(i);
        }
        for(i=0;i<=n;i++){
            if(idxs[i].empty()) continue;
            for(ll j = idxs[i].size()-1;j>0;j--){
                if(idxs[i][j]-idxs[i][j-1]>=k){
                    hash[i]--;
                }
            }
        }
        vector<ll>final;
        for(i=0;i<hash.size()&&i<k-1;i++){
            for(ll j = 0;j<hash[i];j++){
                final.push_back(i);
            }
        }
        vector<ll>finalHash(n+1);
        for(i=0;i<final.size();i++){
            finalHash[final[i]]++;
        }
        for(i=0;i<finalHash.size();i++){
            if(finalHash[i]==0){
                cout << i << endl; 
                return;
            }
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