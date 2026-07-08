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
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        // fuckkk noice question.....we are only shifting the prime factors of each number to other so overall product will be same
        // 30 50 27 20 
        // 30 => 2 3 5
        // 50 => 2 5 5
        // 27 => 3 3 3
        // 20 => 2 2 5
        // so if we equally divide all the prime factors to n numbers then its possible ..means each cnt of prime factor should br divisible by n lol

        map<ll,ll>mp;

        for(i=0;i<n;i++){
            for(ll j = 2;j*j<=a[i];j++){
                while (a[i] % j == 0){
					mp[j]++;
					a[i]/=j;
				}
            }
            if(a[i]>1){
				mp[a[i]]++;
			}
        }
        for(auto tr : mp){
            if(tr.second%n!=0){
                cout<<"NO\n";
                return;
            }
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