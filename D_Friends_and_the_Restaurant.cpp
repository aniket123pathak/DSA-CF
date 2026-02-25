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
        vector<ll>b(n);
        for(i=0;i<n;i++){
           cin>>b[i];
        }
        vector<ll>diff(n);
        for(i=0;i<n;i++){
            diff[i]=b[i]-a[i];
        }
        sort(diff.begin(),diff.end());
        ll count = 0;
        ll right = n-1;
        ll left=0;
        while(left<right){
            if(diff[left]+diff[right]>=0){
                left++;
                right--;
                count++;
            }
            else{
                left++;
            }
        }
        cout<<count<<endl;
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