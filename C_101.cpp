#include <bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
    void solve()
    {
        ll n, i;
        cin >> n;
        vector<ll> a(n);
        ll firstIdx = -1;
        ll lastIdx = -1;
        for(i=0;i<n;i++){
           cin>>a[i];
           if(a[i]!=0){
               if(firstIdx==-1){
                firstIdx=i;
               }
               lastIdx=i;
           }
        }
        
        if(firstIdx!=-1){
            if(a[firstIdx]==-1){
                a[firstIdx]= 1;
            }
            if(a[lastIdx]==-1){
                a[lastIdx]=1;
            }
        }
        
        for(i =0;i<n;i++){
            if(a[i]==-1){
                a[i]=0;
            }
            cout<<a[i]<<" ";
        }
        cout<<endl;
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