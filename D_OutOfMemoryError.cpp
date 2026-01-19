#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,m,h,i;
        cin>>n>>m>>h;
        vector<ll>a(n);
        vector<ll>c(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        c=a;
        vector<pair<ll,ll>>b(m);
        for(i=0;i<m;i++){
            cin>>b[i].first;
            cin>>b[i].second;
        }
vector<bool> modified(n, false);
        vector<ll>idx;
        for(i=0;i<m;i++){
            if(a[b[i].first-1]+b[i].second>h){
                for(ll j=0;j<idx.size();j++){
                    a[idx[j]]=c[idx[j]];
                    modified[idx[j]] = false;
                }
                idx.clear();
            }
            else{
                a[b[i].first-1]+=b[i].second;

                if(!modified[b[i].first-1]){
                    modified[b[i].first-1] = true;
                    idx.push_back(b[i].first-1);
                }
            }
        }

        for(i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";


    }
};

int main() {
    Solution s;
    int tc;
    cin >> tc;
    while (tc-- > 0)
    {
        s.solve();
    }
    return 0;
}