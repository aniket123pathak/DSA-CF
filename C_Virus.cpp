#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,m;
        cin>>n>>m;
        vector<ll>a(m);
        for(i=0;i<m;i++){
           cin>>a[i];
        }
        sort(a.begin(),a.end());
        // 1 2 |3| 4 5 |6| 7 |8| 9 10
        vector<ll>diff;
        diff.push_back((n-a[m-1])+(a[0]-1));
        for(i=0;i<m-1;i++){
            diff.push_back(a[i+1]-a[i]-1);
        }

        sort(diff.rbegin(),diff.rend());
        ll rem = 0;
        ll cur = 0;
        for(i=0;i<diff.size();i++){
            ll curDiff = diff[i]-cur;
            if(curDiff<=0){
                break;
            }
            else if(curDiff==1||curDiff==2){
                rem++;
                cur+=2;
            }
            else{
                rem+=curDiff-1;
                cur+=4;
            }
        }
        cout<<n-rem<<endl;

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