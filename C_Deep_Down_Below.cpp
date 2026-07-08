#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,k;
        cin>>n;
        vector<pair<ll,ll>>ans;
        ll smK = 0;
        for(i=0;i<n;i++){
            cin>>k;
            smK+=k;
            vector<ll>temp(k);
            for(ll j = 0;j<k;j++){
                cin>>temp[j];
            }
            ll left = *min_element(temp.begin(),temp.end())+1;
            ll right = *max_element(temp.begin(),temp.end())+1;
            ll as = INT64_MAX;
            while(left<=right){
                ll mid = left+(right-left)/2;
                ll curP = mid;
                bool check = true;
                for(ll l=0;l<k;l++){
                    if(curP<=temp[l]){
                        check = false;
                        break;
                    }
                    curP++;
                }
                if(check){
                    right = mid-1;
                    as=min(as,mid);
                }
                else{
                    left = mid+1;
                }
            }
            ans.push_back({as,k});
        }

        ll final = INT64_MAX;
        sort(ans.begin(),ans.end());
        ll left = ans[0].first;
        ll right = ans[n-1].first;

        while(left<=right){
            ll mid = left + (right - left)/2;
            bool check = true;
            ll p = mid;
            for(i=0;i<ans.size();i++){
                if(p>=ans[i].first){
                    p+=ans[i].second;
                }
                else{
                    check=false;
                    break;
                }
            }
            if(check){
                final = mid;
                right = mid-1;
            }
            else{
                left = mid+1;
            }
        }
        cout<<final<<endl;






        
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