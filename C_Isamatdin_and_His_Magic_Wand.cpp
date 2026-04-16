#include <bits/stdc++.h>
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
        vector<ll>a(n);
        bool check1 = true;
        bool check2 = true;
        vector<ll>odd;
        vector<ll>even;
        for(i=0;i<n;i++){
           cin>>a[i];
           if(a[i]%2==0){
            check2=false;
            even.push_back(a[i]);
           }
           else{
            check1 = false;
            odd.push_back(a[i]);
           }
        }
        if(check1||check2){
            for(int i = 0;i<n;i++){
                cout<<a[i]<<" ";
            }
            cout<<endl;
            return;
        }
        sort(odd.begin(),odd.end());
        sort(even.begin(),even.end());
        ll m = even.size();
        ll x = odd.size();
        ll o=0;
        ll e = 0;

        while(o<x&&e<m){
            if(even[e]>odd[o]){
                cout<<odd[o]<<" ";
                o++;
            }
            else{
                cout<<even[e]<<" ";
                e++;
            }
        }
        while(o<x){
            cout<<odd[o]<<" ";
            o++;
        }
        while(e<m){
            cout<<even[e]<<" ";
            e++;
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