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
        /*
        1 3 3 1 1.  => 1 1
        */
        ll cnt1 = 0;
        ll cnt2 = 0;
        ll cnt3 = 0;
        ll idx = n;
        bool check1 = false; 
        for(i=0;i<n;i++){
            if(a[i]==1){
                cnt1++;
            }
            else if(a[i]==2){
                cnt2++;
            }
            else{
                cnt3++;
            }
            if(cnt1>=cnt2+cnt3){
                check1=true;
                idx=i+1;
                break;
            }
        }
        if(!check1){
            cout<<"NO\n";
            return;
        }
        ll cnt = cnt1-(cnt2+cnt3);
        while(idx<n&&a[idx]==3&&cnt>0){
            idx++;
            cnt--;
        }
        cnt1=0;
        cnt2=0;
        cnt3=0;
        bool check2 = false; 
        ll idx2 = n;
        for(i=idx;i<n;i++){
            if(a[i]==1){
                cnt1++;
            }
            else if(a[i]==2){
                cnt2++;
            }
            else{
                cnt3++;
            }
            if(cnt1+cnt2>=cnt3){
                check2=true;
                idx2=i+1;
                break;
            }
        }
        if(!check2||idx2==n){
            cout<<"NO\n";
            return;
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