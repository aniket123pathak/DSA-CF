#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:

    void buildTree(ll n,ll lvl ,ll i, ll l, ll r,vector<ll>& segTree, vector<ll>& a){
        if(l==r){
            segTree[i]=a[l];
            return;
        }

        ll mid = l+(r-l)/2;

        buildTree(n,lvl+1,2*i+1,l,mid,segTree,a);
        buildTree(n,lvl+1,2*i+2,mid+1,r,segTree,a);

        if((n-lvl)%2==0){
            segTree[i]=segTree[2*i+1]^segTree[2*i+2];
        }
        else{
            segTree[i]=segTree[2*i+1]|segTree[2*i+2];
        }
    }

    void updateTree(ll newIdx,ll newEle,ll n,ll lvl,ll i,ll l,ll r,vector<ll>& segTree, vector<ll>& a){
        if(l==r){
            segTree[i]=newEle;
            return;
        }

        ll mid = l+(r-l)/2;

        if(newIdx<=mid){
            updateTree(newIdx,newEle,n,lvl+1,2*i+1,l,mid,segTree,a);
        }
        else{
            updateTree(newIdx,newEle,n,lvl+1,2*i+2,mid+1,r,segTree,a);
        }

        if((n-lvl)%2==0){
            segTree[i]=segTree[2*i+1]^segTree[2*i+2];
        }
        else{
            segTree[i]=segTree[2*i+1]|segTree[2*i+2];
        }
    }

    void solve()
    {
        ll n,i,m;
        cin>>n>>m;
        ll numOfEle = pow(2,n);
        vector<ll>a(numOfEle);
        for(i=0;i<numOfEle;i++){
           cin>>a[i];
        }
        vector<ll>segTree(4*numOfEle);
        buildTree(n,0,0,0,numOfEle-1,segTree,a);

        for(i=0;i<m;i++){
            ll p,b;
            cin>>p;
            cin>>b;
            p--;
            updateTree(p,b,n,0,0,0,numOfEle-1,segTree,a);
            cout<<segTree[0]<<endl;
        }
        
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    int tc;
    
        s.solve();
    
    return 0;
}