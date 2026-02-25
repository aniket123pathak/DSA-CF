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
        char c;
        cin>>c;
        string s;
        cin>>s;
        vector<ll>idx;
        vector<ll>temp;
        for(i=0;i<n;i++){
            if(s[i]!=c){
                idx.push_back(i+1);
            }
            else{
                temp.push_back(i+1);
            }
        }
        ll sz = idx.size();
        if(sz==0){
            cout<<"0\n";
            return;
        }

        if(idx[sz-1]!=n){
            cout<<1<<endl;
            cout<<n<<endl;
            return;
        }
        ll tpSz = temp.size();
        for(i=tpSz-1;i>=0;i--){
            bool check = true;
            for(ll j = sz-1;j>=0;j--){
                if(idx[j]>temp[i]){
                    if(idx[j]%temp[i]==0){
                        check = false;
                        break;     
                    }
                }
            }
            if(check){
                cout<<1<<endl;
                cout<<temp[i]<<endl;
                return;
            }
        }

        cout<<2<<endl;
        cout<<n<<" "<<n-1<<endl;

        
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