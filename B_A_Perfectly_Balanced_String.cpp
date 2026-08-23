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
        string a;
        cin>>a;
        n = a.length();
        bool check = true;
        for(i=0;i<n-1;i++){
            if(a[i]!=a[i+1]){
                check = false;
                break;
            }
        }
        if(check){
            cout<<"YES\n";
            return;
        }
        vector<ll>hash(26,0);
        ll firstDiff = n;
        for(i=0;i<n;i++){
            hash[a[i]-'a']++;
            if(hash[a[i]-'a']>1){
                firstDiff = i;
                break;
            }
        }
        ll left = 0;
        ll right = firstDiff;
        while(right<n){
            if(a[left]!=a[right]){
                cout<<"NO\n";
                return;
            }
            left++;
            right++;
        }
        cout<<"YES\n";
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