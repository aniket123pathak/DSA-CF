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
        ll cnte=0;
        ll cnto=0;
        vector<ll>odd;
        vector<ll>even;
        for(i=0;i<n;i++){
           cin>>a[i];
           if(a[i]%2==0){
            cnte++;
            even.push_back(i+1);
           }
           else{
            cnto++;
            odd.push_back(i+1);
           }
        }
        if((cnto>0&&cnte>1)||(cnto>2)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
            return;
        }
        if(cnto>2){
            for(i=0;i<3;i++){
                cout<<odd[i]<<" ";
            }
            cout<<endl;
            return;
        }
        else{
            cout<<odd[0]<<" ";
            cout<<even[1]<<" ";
            cout<<even[0]<<" ";
            cout<<endl;
            return;
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