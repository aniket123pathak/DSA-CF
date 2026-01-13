#include <iostream>
#include <vector>
#include <algorithm>
#include<unordered_map>
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
        vector<pair<ll,ll>>a(n);
        vector<pair<ll,ll>>b(n);
        vector<pair<ll,ll>>c(n);
        for(i=0;i<n;i++){
            cin>>a[i].first;
            a[i].second = i;
        }
        for(i=0;i<n;i++){
            cin>>b[i].first;
            b[i].second = i;
        }
        for(i=0;i<n;i++){
            cin>>c[i].first;
            c[i].second = i;
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        sort(c.begin(),c.end());

        vector<pair<ll,ll>> am;
        am.push_back(a[n-1]);
        am.push_back(a[n-2]);
        am.push_back(a[n-3]);

        vector<pair<ll,ll>> bm;
        bm.push_back(b[n-1]);
        bm.push_back(b[n-2]);
        bm.push_back(b[n-3]);

        vector<pair<ll,ll>> cm;
        cm.push_back(c[n-1]);
        cm.push_back(c[n-2]);
        cm.push_back(c[n-3]);
        
        ll maxS = 0;

        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(am[i].second!=bm[j].second && am[i].second!=cm[k].second && cm[k].second!=bm[j].second){
                        maxS = max(maxS,am[i].first+bm[j].first+cm[k].first);
                    }
                }
            }
        }

        cout<<maxS<<endl;
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