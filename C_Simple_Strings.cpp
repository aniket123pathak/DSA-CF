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
        string s;
        cin>>s;
        n=s.length();
        if(n==1){
            cout<<s<<endl;
            return;
        }

        vector<char>alpha={'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};

        if(s[0]==s[1]){
            for(j=0;j<26;j++){
                if(s[0]!=alpha[j]){
                    s[0]=alpha[j];
                    break;
                }
            }
        }
        for(i=1;i<n-1;i++){
            if(s[i]==s[i-1]&&s[i]==s[i+1]){
                for(j=0;j<26;j++){
                    if(s[i]!=alpha[j]){
                        s[i]=alpha[j];
                        break;
                    }
                }
            }
            else if(s[i]==s[i-1]){
                for(j=0;j<26;j++){
                    if((s[i-1]!=alpha[j])&&(s[i+1]!=alpha[j])){
                        s[i]=alpha[j];
                        break;
                    }
                }
            }
        }
        if(s[n-1]==s[n-2]){
            for(j=0;j<26;j++){
                if(s[n-2]!=alpha[j]){
                    s[n-1]=alpha[j];
                    break;
                }
            }
        }

        cout<<s<<endl;


        
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