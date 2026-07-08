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
        ll n,p,i;
        cin>>n>>p;
        vector<ll>a(n);
        vector<ll>b(n);
        vector<pair<ll,ll>>pr(n);
        for(i=0;i<n;i++){
            cin>>a[i];
            pr[i].second = a[i];
        }
        for(i=0;i<n;i++){
            cin>>b[i];
            pr[i].first = b[i];
        }
        sort(pr.begin(),pr.end());
        ll ppl = n-1;
        ll cst = p;
        for(i=0;i<n;i++){
            if(pr[i].first<p){
                if(ppl>=pr[i].second){
                    ppl-=pr[i].second;
                    cst+=pr[i].first*pr[i].second;
                }
                else{
                    cst+=ppl*pr[i].first;
                    ppl=0;
                }
            }
            else{
                break;
            }
        }
        if(ppl>0){
            cst+=ppl*p;
        }
        cout<<cst<<endl;
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