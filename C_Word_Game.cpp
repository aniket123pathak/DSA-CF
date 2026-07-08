#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define no cout<<'NO'<<endl
#define yes cout<<'YES'<<endl
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i;
        cin>>n;
        vector<vector<string>> a(3,vector<string>(n));
        unordered_map<string,ll> freq;
    
        for(i=0;i<3;i++){
            for(ll j=0;j<n;j++){
                cin>>a[i][j];
                freq[a[i][j]]++;
            }
        }
    

        for(i=0;i<3;i++){
            ll score=0;
            for(ll j=0;j<n;j++){
                if(freq[a[i][j]]==1){
                    score+=3;
                }
                else if(freq[a[i][j]]==2){
                    score+=1;
                }
            }
            cout<<score<<" ";
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