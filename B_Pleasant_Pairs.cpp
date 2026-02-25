#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]


/*
ai*aj=i+j

3 1 5 9 2
1 2 3 4 5

3 4 5 6  
5 6 7    
7 8
9

2n-1

*/
class Solution {
public:
    void solve()
    {
        ll n,i,j;
        cin>>n;
        vector<ll>a(n);
        vector<pair<ll,ll>>pr(n);
        for(i=0;i<n;i++){
           cin>>a[i];
           pr[i].first=a[i];
           pr[i].second=i+1;
        }
        sort(pr.begin(),pr.end());
        ll cnt = 0;
        for(i=0;i<n-1;i++){
            for(j=i+1;j<n;j++){
                if(pr[i].first*pr[j].first>2*n-1){
                    break;
                }
                if(pr[i].second+pr[j].second==pr[i].first*pr[j].first){
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
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