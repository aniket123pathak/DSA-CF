#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct Node {
    ll mnVal;
    ll mnIdx;
    ll mxVal;
    ll mxIdx;
};

class Solution {
public:
    void buildTree(ll i, ll l, ll r, vector<Node>& segTree,vector<ll>& a) {
        if (l == r) {
            segTree[i] = {a[l], l, a[l], l};
            return;
        }
        ll mid = l + (r - l)/2;
        buildTree(2*i+1,l,mid,segTree,a);
        buildTree(2*i+2,mid+1,r,segTree,a);


        Node leftChild = segTree[2 * i + 1];
        Node rightChild = segTree[2 * i + 2];
        
        if(leftChild.mnVal<rightChild.mnVal){
            segTree[i].mnVal=leftChild.mnVal;
            segTree[i].mnIdx=leftChild.mnIdx;
        } 
        else{
            segTree[i].mnVal=rightChild.mnVal;
            segTree[i].mnIdx=rightChild.mnIdx;
        }
        
        if(leftChild.mxVal>rightChild.mxVal){
            segTree[i].mxVal=leftChild.mxVal;
            segTree[i].mxIdx=leftChild.mxIdx;
        } 
        else{
            segTree[i].mxVal=rightChild.mxVal;
            segTree[i].mxIdx=rightChild.mxIdx;
        }
    }

    Node query(ll l, ll r, ll i, ll st, ll ed, const vector<Node>& segTree) {
        if (l > ed || r < st) {
            return {INT64_MAX,-1,INT64_MIN,-1};
        }
        if (l<=st&&ed<=r) {
            return segTree[i];
        }
        
        ll mid = st + (ed - st) / 2;
        Node leftChild = query(l, r, 2 * i + 1, st, mid, segTree);
        Node rightChild = query(l, r, 2 * i + 2, mid + 1, ed, segTree);
        
        Node ans;
        
        if(leftChild.mnVal<rightChild.mnVal){
            ans.mnVal=leftChild.mnVal;
            ans.mnIdx=leftChild.mnIdx;
        } 
        else {
            ans.mnVal=rightChild.mnVal;
            ans.mnIdx=rightChild.mnIdx;
        }
        
  
        if(leftChild.mxVal>rightChild.mxVal){
            ans.mxVal=leftChild.mxVal;
            ans.mxIdx=leftChild.mxIdx;
        } 
        else{
            ans.mxVal=rightChild.mxVal;
            ans.mxIdx=rightChild.mxIdx;
        }
        
        return ans;
    }

    void solve() {
        ll n, i;
        cin >> n;
        vector<ll> a(n);
        for (i = 0; i < n; i++) {
           cin >> a[i];
        }
        
        vector<Node> segTree(4 * n);
        buildTree(0,0,n-1,segTree,a);
        
        ll q;
        cin>>q;
        for(i=0;i<q;i++) {
            ll l, r;
            cin>>l>>r;
            l--; 
            r--;
    
            Node ans = query(l, r, 0, 0, n-1, segTree);

            if (ans.mxVal == ans.mnVal) {
                cout <<-1<<" "<<-1<<endl;
            } 
            else{
                cout<<ans.mnIdx+1<<" "<<ans.mxIdx+1<<endl;
            }
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
    while (tc-- > 0) {
        s.solve();
    }
    return 0;
}