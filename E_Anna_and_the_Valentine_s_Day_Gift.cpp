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
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        } 
        vector<pair<ll,ll>>endZero;
        ll noZero=0;
        for(i=0;i<n;i++){
            if(a[i]%10==0){
                ll temp = a[i];
                ll dig = 0;
                ll zro = 0;
                bool check = true;
                while(temp>0){
                    ll rem = temp%10;
                    if(rem==0&&check){
                        zro++;
                    }
                    else{
                        check=false;
                    }
                    dig++;
                    temp/=10;
                }
                endZero.push_back({zro,dig});
            }
            else{
                ll temp = a[i];
                ll dig = 0;
                while(temp>0){
                    dig++;
                    temp/=10;
                }
                noZero+=dig;
            }
        }
        sort(endZero.rbegin(),endZero.rend());
        
        ll sz = endZero.size();

        for(i=0;i<sz;i++){
            if(i%2==0){
                noZero+=(endZero[i].second-endZero[i].first);
            }
            else{
                noZero+=endZero[i].second;
            }
        }

        if(noZero<=m){
            cout<<"Anna\n";
        }
        else{
            cout<<"Sasha\n";
        }


        
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