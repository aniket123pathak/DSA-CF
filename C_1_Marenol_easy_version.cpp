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
        string a,b;
        cin>>a>>b;
        ll cnt1a = 0;
        ll cnt1b = 0;
        ll cnt0a = 0;
        ll cnt0b = 0;
        if(a==b){
            cout<<"YES\n";
            return;
        }
        for(i=0;i<n;i++){
            if(a[i]=='1'){
                cnt1a++;
            }
            else{
                cnt0a++;
            }
            if(b[i]=='1'){
                cnt1b++;
            }
            else{
                cnt0b++;
            }
        }
        if(cnt1a!=cnt1b || cnt0a!=cnt0b){
            cout<<"NO\n";
            return;
        }


        //1001100
        //0000111

        /*
            0011100
            0011001
            0010011
            0000111

            0010101010
            1000101010


            ex: 110000101011
            =>  000011101011

        */
        if(cnt1a%2!=0&&cnt0a%2!=0){
            cout<<"NO\n";
        }
        cout<<"YES\n";
        
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