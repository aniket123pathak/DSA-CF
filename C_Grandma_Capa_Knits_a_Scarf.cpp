#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

/*

rprarlap


abcckba

*/

class Solution {
public:
    void solve()
    {
        ll n,i;
        cin>>n;
        string s;
        cin>>s;
        string temp = "abcdefghijklmnopqrstuvwxyz";
        ll ans = 1e9;
        for(i=0;i<26;i++){
            char cur = temp[i];
            ll curAns = 0;
            ll left = 0;
            ll right = n-1;
            bool check = true;
            while(left<right){
                if(s[left]==s[right]){
                    left++;
                    right--;
                }
                else if(s[left]!=s[right] && (s[left]!=cur && s[right]!=cur)){
                    check = false;
                    break;
                }
                else{
                    if(s[left]==cur){
                        left++;
                    }
                    else{
                        right--;
                    }
                    curAns++;
                }
            }
            if(check){ 
                ans=min(curAns,ans);
            }
        }
        if(ans!=1e9){
            cout<<ans<<endl;
        }
        else{
            cout<<-1<<endl;
        }
        
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