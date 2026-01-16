#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

/*
    sjfnsifdnwhffjdisofj


*/

class Solution {
public:
    void solve()
    {
        ll n,i;
        cin>>n;
        string s;
        cin>>s;
        vector<ll>hash1(26,0);
        vector<ll>hash2(26,0);
        vector<ll>hash3(n+1,0);
        vector<ll>hash4(n+1,0);
        ll cnt = 0;

        for(i=0;i<n;i++){
            if(hash1[s[i]-'a']==0){
                cnt++;
            }
            hash1[s[i]-'a']++;
            hash3[i]=cnt;
        }
        cnt=0;
        for(i=n-1;i>=0;i--){
            if(hash2[s[i]-'a']==0){
                cnt++;
            }
            hash2[s[i]-'a']++;
            hash4[i]=cnt;
        }
        cnt=0;
        for(i=0;i<n-1;i++){
            cnt=max(cnt,hash3[i]+hash4[i+1]);
        }
        cout<<cnt<<endl;
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