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
        string s;
        cin>>s;

        ll count1=0;
        ll count0 =0;
        ll ways=0;

        for(i=0;i<n;i++){
            if(s[i]=='0'){
                count0++;
            }
            else{
                count1++;
            }

            if(count1>count0){
                ways++;
            }
        }

        cout<<ways<<endl;

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