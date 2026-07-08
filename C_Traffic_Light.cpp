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
        ll n,i;
        cin>>n;
        char c;
        cin>>c;
        string s;
        cin>>s;
        if(c=='g'){
            cout<<0<< "\n";
            return;
        }
        ll lastIdx = 0;
        for(i=n-1;i>=0;i--){
            if(s[i]=='g'){
                lastIdx=i;
                break;
            }
        }
        
        vector<vector<ll>>pr(n);
        ll temp = 0;
        for(i=lastIdx;i<n;i++){
            if(s[i]==c){
                pr[temp].push_back(i);
            }
        }
        for(i=0;i<=lastIdx;i++){
            if(s[i]==c){
                pr[temp].push_back(i);
            }
            else if(s[i]=='g'){
                pr[temp].push_back(i);
                temp++;
            }
        }
        ll ans = 0;
        for(i=0;i<pr.size();i++){
            if (pr[i].empty()) continue;
            if(s[pr[i][0]]==c){
                ll sIdx=pr[i][0];
                ll eIdx =pr[i].back();
                if(sIdx>eIdx) {
                    ans=max(ans,n-sIdx+eIdx);
                } 
                else{
                    ans=max(ans,eIdx-sIdx);
                }
            }
        }
        cout<<ans<<endl;

        
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