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

        set<pair<long long,long long>>st;

        st.insert(kpr1);
        st.insert(kpr2);
        st.insert(kpr3);
        st.insert(kpr4);
        st.insert(kpr5);
        st.insert(kpr6);
        st.insert(kpr7);
        st.insert(kpr8);
        st.insert(qpr1);
        st.insert(qpr2);
        st.insert(qpr3);
        st.insert(qpr4);
        st.insert(qpr5);
        st.insert(qpr6);
        st.insert(qpr7);
        st.insert(qpr8);
        

        
        
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