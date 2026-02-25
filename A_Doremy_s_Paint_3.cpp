#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include<map>
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
        set<ll>st;
        map<ll,ll>mp;
        for(i=0;i<n;i++){
           cin>>a[i];
           st.insert(a[i]);
           mp[a[i]]++;
        }
        if(st.size()>2){
            cout<<"NO\n";
            return;
        }
        if(st.size()==1||n==3){
            cout<<"YES\n";
            return;
        }
        ll temp1=*st.begin();
        ll temp2=*st.rbegin();


        if(n%2==0){
            if(mp[temp1]==mp[temp2]){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }   
        }
        else{
            if(abs(mp[temp1]-mp[temp2])==1){
                cout<<"YES\n";
            }
            else{
                cout<<"NO\n";
            }   
        }
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