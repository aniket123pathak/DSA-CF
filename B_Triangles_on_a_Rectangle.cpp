#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]


/*
have to maximize the B*H

triangle will only formed btw two hori lines or two verticle lines
very very easyyyyyyyyyyyy
*/

class Solution {
public:
    void solve()
    {
        ll w,h,i,h0,h1,v0,v1;
        cin>>w>>h;

        cin>>h0;
        vector<ll>hori0(h0);
        for(i=0;i<h0;i++){
           cin>>hori0[i];
        }
        cin>>h1;
        vector<ll>hori1(h1);
        for(i=0;i<h1;i++){
           cin>>hori1[i];
        }
        cin>>v0;
        vector<ll>verti0(v0);
        for(i=0;i<v0;i++){
           cin>>verti0[i];
        }
        cin>>v1;
        vector<ll>verti1(v1);
        for(i=0;i<v1;i++){
           cin>>verti1[i];
        }

        ll m1 = (hori0[h0-1]-hori0[0])*h;
        ll m2 = (hori1[h1-1]-hori1[0])*h;

        ll m3 = (verti0[v0-1]-verti0[0])*w;
        ll m4 = (verti1[v1-1]-verti1[0])*w;

        cout<<max(max(m1,m2),max(m3,m4))<<endl;


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