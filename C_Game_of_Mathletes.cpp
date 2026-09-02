#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,target;
        cin>>n>>target;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        sort(a.begin(),a.end());
        ll left = 0;
        ll right = n-1;
        ll cnt = 0;
        while(left<right){
            ll sum = a[left]+a[right];
            if(sum==target){
                cnt++;
                left++;
                right--;
            }
            else if(sum>target){
                right--;
            }
            else{
                left++;
            }
        }
        cout<<cnt<<endl;
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