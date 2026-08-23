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
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        vector<ll>a2(n);
        for(i=0;i<n;i++){
           cin>>a2[i];
        }
        ll firstDiff = n;
        for(i=0;i<n;i++){
            if(a[i]!=a2[i]){
                firstDiff = i;
                break;
            }
        }
        if(firstDiff==n){
            cout<<"1 "<<n<<endl;
            return;
        }
        ll upto = n;
        for(i=firstDiff;i<n-1;i++){
            if(a2[i]>a2[i+1]){
                upto = i;
                break;
            }
        }

        ll l = firstDiff;
        ll r = upto;

        ll first = firstDiff-1;
        while(first>=0){
            if(a2[first]<=a2[first+1]){
                first--;
            }
            else{
                break;
            }
        }
        l = first+1;
        if(r==n){
            r = upto-1;
        }
        ll second = r+1;
        while(second<n){
            if(a2[second]>=a2[second-1]){
                second++;
            }
            else{
                break;
            }
        }
        r = second-1;
        
        cout<<l+1<<" "<<r+1<<endl;
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