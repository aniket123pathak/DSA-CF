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
        ll a,b,i;
        cin>>a>>b;
        if(a==b){
            cout<<"0\n";
            return;
        }
        ll div = -1;//if div is the power of 2 then onlt it is possible otherwise its impossible
        if(max(a,b)%min(a,b)==0){
            div = max(a,b)/min(a,b);
        }
        else{
            cout<<"-1\n";
            return;
        }
        vector<ll>pow2(71,0);
        pow2[1]=2;
        for(i=2;i<70;i++){
            pow2[i]=pow2[i-1]*2;
        }
        bool check = false;
        for(i=1;i<70;i++){
            if(pow2[i]==div){
                check = true;
            }
        }

        if(!check){
            cout<<"-1\n";
            return;
        }
        ll count=0;

        while(div!=1){
            if(div%8==0 && div/8>0){
                div/=8;
                count++;
            }
            else if(div%4==0&&div/4>0){
                div/=4;
                count++;
            }
            else{
                div/=2;
                count++;
            }
        }
        cout<<count<<"\n";
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