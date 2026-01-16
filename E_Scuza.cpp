#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

/*

 1 3 2 4 2 3 4 3 5 6 3 4 5 6

 1 4 6 10 12 15 19 22 27 33 36 40 45 51

 27 42 5 4

*/

class Solution {
public:
    void solve()
    {
        ll n,q,i;
        cin>>n>>q;
        vector<ll>a(n);
        vector<ll>height(n),maxStep(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        vector<ll>b(q);
        for(i=0;i<q;i++){
           cin>>b[i];   
        }
        height[0]=a[0];
        maxStep[0]=a[0];
        for(i=1;i<n;i++){
            maxStep[i]=max(maxStep[i-1],a[i]);
            height[i]=height[i-1]+a[i];
        }

        for(i=0;i<q;i++){
            ll left = 0;
            ll right = n-1;
            bool check = false;
            ll reach = 0;
            while(left<=right){
                ll mid=left+(right-left)/2;

                if(b[i]>=maxStep[mid]){
                    reach = mid;
                    left=mid+1;
                    check = true;
                }
                else{
                    right = mid-1;
                }
            }
            if(!check){
                cout<<"0 ";
            }
            else{
                cout<<height[reach]<<" ";
            }
        }
        cout<<"\n";

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