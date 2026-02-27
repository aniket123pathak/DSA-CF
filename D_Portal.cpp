#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,x,y;
        cin>>n>>x>>y;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        vector<ll>left;
        vector<ll>mid;
        vector<ll>right;
        for(i=0;i<n;i++){
            if(i<x){
                left.push_back(a[i]);
            }
            else if(i>=x&&i<y){
                mid.push_back(a[i]);
            }
            else{
                right.push_back(a[i]);
            }
        }
        if(mid.size()==0){
            for(i=0;i<left.size();i++){
                cout<<left[i]<<" ";
            }
            for(i=0;i<right.size();i++){
                cout<<left[i]<<" ";
            }
            cout<<endl;
            return;
        }
        ll minM = *min_element(mid.begin(),mid.end());
        vector<ll>newMid;
        ll idx = -1;
        for(i=0;i<mid.size();i++){
            if(mid[i]==minM){
                newMid.push_back(mid[i]);
                idx=i;
                break;
            }
        }
        for(i=idx+1;i<mid.size();i++){
            newMid.push_back(mid[i]);
        }
        for(i=0;i<idx;i++){
            newMid.push_back(mid[i]);
        }
        vector<ll>newLR;

        for(i=0;i<left.size();i++){
            newLR.push_back(left[i]);
        }
        for(i=0;i<right.size();i++){
            newLR.push_back(right[i]);
        }
        ll stored=n;
        for(i=0;i<newLR.size();i++){
            if(newLR[i]>minM){
                stored=i;
                break;
            }
            else{
                cout<<newLR[i]<<" ";
            }
        }
        for(i=0;i<newMid.size();i++){
            cout<<newMid[i]<<" ";
        }
        for(i=stored;i<newLR.size();i++){
            cout<<newLR[i]<<" ";
        }
        cout<<endl;
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