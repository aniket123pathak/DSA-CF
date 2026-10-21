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
        string s;
        cin>>s;
        
        /*
        x = add
        y = sub
        p= add a
        r =adc b 
        q =sun a
        s=sub b
        pa+rb-(qa+sb)=0
        pa+(x-p)b-(qa+(y-q)b)=0
        pa+xb-pb-(qa+yb-qb)=0
        pa+xb-pb-qa-yb+qb=0
        pa-qa+xb-yb+qb-pb=0
        (p-q)a+(x-y)b+(q-p)b=0
        (p-q)a+(x-y)b-(p-q)b=0
        (p-q)(a-b)+(x-y)b=0
        p-q=(y-x)b/(a-b)

        butttt p-q is constant..soo we can
        c = (y-x)b/(a-b)
        */
        ll add=0;
        ll sub = 0;
        for(i=0;i<n;i++){
            if(s[i]=='+'){
                add++;
            }
            else{
                sub++;
            }
        }
        ll q;
        cin>>q;
        for(i=0;i<q;i++){
            ll a,b;
            cin>>a>>b;
            if(add==sub){
                cout<<"YES\n";
                continue;
            }
            if(a==b){
                cout<<"NO\n";
                continue;
            }
            ll numntr=(sub-add)*b;
            ll denomntr=a-b;

            if(numntr%denomntr==0) {
                ll c =numntr/denomntr;                
                if(c>=-sub && c<=add){
                    cout<<"YES\n";
                } 
                else{
                    cout<<"NO\n";
                }
            } 
            else{
                cout<<"NO\n";
            }
        }
        
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;
    s.solve();
    return 0;
}