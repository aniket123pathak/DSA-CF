#include <iostream>
#include <vector>
#include <algorithm>
#include<set>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll a,b,xk,yk,xq,yq;
        cin>>a>>b>>xk>>yk>>xq>>yq;

        pair<long long,long long>kpr1;
        pair<long long,long long>kpr2;
        pair<long long,long long>kpr3;
        pair<long long,long long>kpr4;
        pair<long long,long long>kpr5;
        pair<long long,long long>kpr6;
        pair<long long,long long>kpr7;
        pair<long long,long long>kpr8;
        kpr1.first=xk+a;
        kpr1.second=yk+b;
        kpr2.first=xk+a;
        kpr2.second=yk-b;
        kpr3.first=xk-a;
        kpr3.second=yk+b;
        kpr4.first=xk-a;
        kpr4.second=yk-b;
        kpr5.first=xk+b;
        kpr5.second=yk+a;
        kpr6.first=xk+b;
        kpr6.second=yk-a;
        kpr7.first=xk-b;
        kpr7.second=yk+a;
        kpr8.first=xk-b;
        kpr8.second=yk-a;
        pair<long long,long long>qpr1;
        pair<long long,long long>qpr2;
        pair<long long,long long>qpr3;
        pair<long long,long long>qpr4;
        pair<long long,long long>qpr5;
        pair<long long,long long>qpr6;
        pair<long long,long long>qpr7;
        pair<long long,long long>qpr8;
        qpr1.first=xq+a;
        qpr1.second=yq+b;
        qpr2.first=xq+a;
        qpr2.second=yq-b;
        qpr3.first=xq-a;
        qpr3.second=yq+b;
        qpr4.first=xq-a;
        qpr4.second=yq-b;
        qpr5.first=xq+b;
        qpr5.second=yq+a;
        qpr6.first=xq+b;
        qpr6.second=yq-a;
        qpr7.first=xq-b;
        qpr7.second=yq+a;
        qpr8.first=xq-b;
        qpr8.second=yq-a;

        set<pair<ll,ll>>kSt;
        set<pair<ll,ll>>qSt;

        kSt.insert(kpr1);
        kSt.insert(kpr2);
        kSt.insert(kpr3);
        kSt.insert(kpr4);
        kSt.insert(kpr5);
        kSt.insert(kpr6);
        kSt.insert(kpr7);
        kSt.insert(kpr8);
        
        qSt.insert(qpr1);
        qSt.insert(qpr2);
        qSt.insert(qpr3);
        qSt.insert(qpr4);
        qSt.insert(qpr5);
        qSt.insert(qpr6);
        qSt.insert(qpr7);
        qSt.insert(qpr8);
        
        ll ans=0;
        for(auto pos : kSt) {
            if(qSt.count(pos)) {
                ans++;
            }
        }
        cout<<ans<<"\n";
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