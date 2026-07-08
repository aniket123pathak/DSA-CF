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

        if(a[n-2]>a[n-1]){
            cout<<-1<<endl;
            return;
        }

        if(a[n-1]<0){
            if(is_sorted(a.begin(),a.end())){
                cout<<0<<endl;
            }
            else{
                cout<<-1<<endl;
            }
            return;
        }

        if(a[n-1]>=0){
            cout<<n-2<<endl;
            for(i=0;i<n-2;i++){
                cout<<i+1<<" "<<n-1<<" "<<n<<endl;
            }
            return;
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