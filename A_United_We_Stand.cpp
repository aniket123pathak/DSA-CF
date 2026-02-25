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
        ll n,i;
        cin>>n;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        sort(a.begin(),a.end());
        vector<ll>b;
        vector<ll>c;
        
        b.push_back(a[0]);
        for(i=1;i<n;i++){
            if(a[i]==a[0]){
                if(i==n-1){
                    cout<<-1<<endl;
                    return;
                }
                b.push_back(a[i]);
            }
            else{
                break;
            }
        }
        while(i<n){
            c.push_back(a[i]);
            i++;
        }

        if(c.size()==0){
            cout<<-1<<endl;
        }
        cout<<b.size()<<' '<<c.size()<<endl;
        for(i=0;i<b.size();i++){
            cout<<b[i]<<" ";
        }
        cout<<endl;
        
        for(i=0;i<c.size();i++){
            cout<<c[i]<<" ";
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