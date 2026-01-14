#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

/*

ex    1 2 3 4 5 6 7 8 9 => maxStep = 4 = (n/2);
ex    1 2 3 4 5 6 7 8 => maxStep = 3 = (n/2)-1;


so what if we brute force our solution for mx step to less..

for(i=0;i<=mxSt;i++){
            ll curClr = a[i];
            ll curPl = i; 1
            bool check = true;
            int repaintChance = 1;
            while(curPl<n){
                if(curClr!=a[curPl] && repaintChance==1){
                    repaintChance=0;
                }
                else if(curClr!=a[curPl] && repaintChance==0){
                    check = false;
                    break;
                }
                else{
                    ;
                }
                curPl+=(i+1);
            }
            if(check){
                mxSt = min(mxSt,i);
            }
        }

getting error on 1 5 2 1 2 4
n=6
mxSt = 2;




*/

class Solution {
public:
    void solve()
    {
        ll n,k,i;
        cin>>n>>k;

        vector<ll>a(n);
        vector<vector<ll>>map(k+1);

        for(i=0;i<n;i++){
            cin>>a[i];
        }

        if(k==1){
            cout<<"0\n";
            return;
        }
        ll mxSt = 0;

        for(i=1;i<=k;i++){
            map[i].push_back(0);
        }

        for(i=0;i<n;i++){
            map[a[i]].push_back(i+1);
        }

        for(i=1;i<=k;i++){
            map[i].push_back(n+1);
        }

        vector<vector<ll>> diff(k+1);

        for(i=1;i<=k;i++){
            for(ll j = 0;j<map[i].size()-1;j++){
                diff[i].push_back(abs(map[i][j]-map[i][j+1])-1);
            }
        }

        for(i=1;i<=k;i++){
            sort(diff[i].begin(),diff[i].end());
        }

        vector<pair<ll,ll>> maxJumps(k+1);

        for(i=1;i<=k;i++){
            maxJumps[i].first = diff[i][diff[i].size()-1];
            maxJumps[i].second = diff[i][diff[i].size()-2];
        }

        vector<ll> final(k+1,INT64_MAX);

        for(i=1;i<=k;i++){
            final[i]=max(maxJumps[i].first/2,maxJumps[i].second);
        }

        mxSt=*min_element(final.begin(),final.end());

        cout<<mxSt<<endl;
    }
};

int main() {
    Solution s;
    int tc;
    cin >> tc;
    while (tc-- > 0)
    {
        s.solve();
    }
    return 0;
}