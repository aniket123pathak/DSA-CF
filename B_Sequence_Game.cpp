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
        v(a,n);
        fin(i,0,n,a);
        ll count=1;

        for(i=1;i<n;i++){
            if(a[i]>=a[i-1]){
                count++;
            }
            else{
                count+=2;
            }
        }
        cout<<count<<endl;
        cout<<a[0]<<" ";
        for(i=1;i<n;i++){
            if(a[i]>=a[i-1]){
                cout<<a[i]<<" ";
                count++;
            }
            else{
                cout<<"1"<<" "<<a[i]<<" ";\
                count+=2;
            }
        }
        cout<<endl;

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