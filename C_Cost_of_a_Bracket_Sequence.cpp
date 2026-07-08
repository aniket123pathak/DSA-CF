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
        cin>>n>>k;
        string s;
        cin>>s;
        vector<ll>ans(n,0);

        // so find the longest subsequesnce and then remove the opening brackets of that subsequences and decrese the k one by one 
        // if k remain>0 then remove next rem opening brackets
        //so this is how we get to our soln and the cost will decrese automatically..
        // but why this will work ha..?? 
        // by removing one open bracket cost will decrese by 2...
        // if there are any smaller subsequnces with lesser cost that subsequnces will already. gets coverd in the longest one know..
        // cause its a SUBSEQUENCE not a SUBARRAY..
        // now how to find the longest subsequnce with the indices
        // changing logic to greedy one..self Implemented bad code

        ll finalCst = INT64_MAX;
        for(ll j=0;j<=k;j++){
            ll start = 0;
            ll open = j;
            ll idx = 0;
            vector<ll>openIdxs;
            while(open>0 && idx<n){
                if(s[idx]=='('){
                    openIdxs.push_back(idx);
                    open--;
                }
                idx++;
            }
            if(open>0){
                continue;
            }
            else{
                start=idx;
            }

            ll end = n-1;
            ll close = k-j;
            idx = n-1;
            vector<ll>closeIdxs;
            while(close>0&&idx>=0){
                if(s[idx]==')'){
                    closeIdxs.push_back(idx);
                    close--;
                }
                idx--;
            }
            if(close>0){
                continue;
            }
            else{
                end = idx;
            }

            ll openBracket =0;
            ll pr = 0;
            for(i=start;i<=end;i++){
                if(s[i]=='('){
                    openBracket++;
                }
                else{
                    if(openBracket>0){
                        pr++;
                        openBracket--;
                    }
                }
            }
            ll cst = pr*2;
            vector<ll>curAns(n,0);
            
            if(finalCst>=cst){
                finalCst=cst;
                for(ll x = 0;x<openIdxs.size();x++){
                    curAns[openIdxs[x]]=1;
                }
                for(ll x = 0;x<closeIdxs.size();x++){
                    curAns[closeIdxs[x]]=1;
                }
                ans=curAns;
            }

            

        }

        for(i=0;i<n;i++){
            cout<<ans[i];
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