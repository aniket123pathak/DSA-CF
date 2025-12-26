#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll k,n,i;
        cin>>k>>n;
        if(k==n){
            for(i=0;i<n;i++){
                cout<<i+1<<" ";
            }
            cout<<endl;
            return;
        }
        ll curPr = 1;
        k--; 
        cout<<curPr<<" ";
        i=1;
        while(k>0){
            ll nowPr=curPr+i;
            k--;
            if((n-nowPr)>=k){
                curPr=nowPr;
                cout<<curPr<<" ";
            }
            else{
                k++;
                break;
            }
            i++;
        }

        while(k-->0){
            curPr++;
            cout<<curPr<<" ";
        }
        cout<<endl;
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