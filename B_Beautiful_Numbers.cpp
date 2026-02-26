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
        ll x = n;
        ll numberOfDig = 0;
        ll sum=0;
        vector<ll>rems;
        while(x>0){
            ll rem = x%10;
            rems.push_back(rem);
            numberOfDig++;
            sum+=rem;
            x/=10;
        }

        ll y =sum;
        ll sum2 = 0;
        while(y>0){
            sum2+=y%10;
            y/=10;
        }
        if(sum==sum2){
            cout<<"0\n";
            return;
        }
        vector<ll>revRem;
        for(i=rems.size()-1;i>=0;i--){
            revRem.push_back(rems[i]);
        }
        sort(revRem.begin()+1,revRem.end());
        ll temp = revRem[0];
        ll cnt = 1;

        for(i=1;i<revRem.size();i++){
            if(temp+revRem[i]<10){
                temp+=revRem[i];
                cnt++;
            }
            else{
                break;
            }

        }
        ll ans1=numberOfDig-cnt;

        ll temp2=1;
        ll cnt2 =0;
        for(i=1;i<revRem.size();i++){
            if(temp2+revRem[i]<10){
                temp2+=revRem[i];
                cnt2++;
            }
            else{
                break;
            }

        }
        ll ans2=numberOfDig-cnt2;

        cout<<min(ans1,ans2)<<endl;

        
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