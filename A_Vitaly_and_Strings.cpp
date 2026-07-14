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
        string s,t;
        cin>>s>>t;
        string newString1 = s;
        string newString2 = s;
        
        n = s.length();
        string temp = "abcdefghijklmnopqrstuvwxyz";
        bool check = false;
        
        for(i=0;i<n;i++){
            if(t[i]-s[i]>1){
                for(ll j=0;j<26;j++){
                    if(temp[j]>s[i]&&temp[j]<t[i]){
                        s[i]=temp[j];
                        break;
                    }
                }
                cout<<s<<endl;
                return;
            }
            else if(t[i]-s[i]==1){
                check = true;
                ll idx = i;
                newString1[i]=t[i];
                for(ll j=idx+1;j<n;j++){
                    newString1[j]='a';
                }
                newString2[i]=s[i];
                for(ll j=idx+1;j<n;j++){
                    newString2[j]='z';
                }
                break;
            }
        }

        if(check){
            if(newString1<t){
                cout<<newString1<<endl;
            }
            else if(newString2>s){
                cout<<newString2<<endl;
            }
            else{
                cout<<"No such string\n";
            }
        }
        else{
            cout<<"No such string\n";
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