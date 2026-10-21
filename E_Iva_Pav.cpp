#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        ll n,i,j;
        cin>>n;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        vector<vector<ll>>pfBitCnt(n+1,vector<ll>(32,0));

        for(i=0;i<n;i++){
            for(ll bit=0;bit<32;bit++){
                pfBitCnt[i+1][bit] =pfBitCnt[i][bit];
                if((a[i]>>bit)&1){
                    pfBitCnt[i+1][bit]++; 
                }
            }  
        }
        ll q;
        cin>>q;
        for(j=0;j<q;j++){
            ll l,k;
            cin>>l>>k;
            l--;
            if(a[l]<k){
			    cout<<-1<<" ";
			    continue;
		    }
            ll low = l;
            ll high = n-1;
            ll ans = -1;
            while(low<=high){
                ll mid = low+(high-low)/2;
                ll curAns = 0;
                ll len = mid-l+1;
	            for(ll bit=0;bit<32;bit++){
                    if(pfBitCnt[mid+1][bit]-pfBitCnt[l][bit]==len){
                        curAns+=(1LL<<bit);
                    }
                }
                if(curAns>=k){
                    ans = mid;
                    low = mid+1;
                }
                else{
                    high = mid-1;
                }
            }
            cout<<ans+1<<" ";
        }    
        cout<<endl;
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