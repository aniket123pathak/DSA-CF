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

        ll last = n;
        ll from = n-(k-1);
        ll odd = 0;
        if(from%2==0&&last%2==0){
            odd=(last-from)/2;
        }
        if(from%2!=0&&last%2!=0){
            odd=(last-from)/2 + 1;
        }
        if(from%2!=0&&last%2==0){
            odd=(last-from-1)/2 + 1;
        }
        if(from%2==0&&last%2!=0){
            odd=(last-1-from)/2 +1;
        }
        if(odd%2==0){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }

        
        
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