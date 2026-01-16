#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

/*

4000 2

2000 1000 500 250 125 62 31 15 7 3 1 0..    12
400 40 4 0 12
800 160 32 6 1 0 9


1337 1
1337 2 1
if(1337/b*b > 1337/b+1 )
*/

class Solution {
public:
    void solve()
    {
        ll a,b,i;
        cin>>a>>b;
        if(b>a){
            cout<<"1\n";
            return;
        }
        if(b==a){
            cout<<"2\n";
            return;
        }
        ll minstep = INT64_MAX;
        for(i=0;i<35;i++){
            if(b+i==1){
                continue;
            }
            ll tempCount = i;
            ll tempB = b+i;
            ll tempA = a;
            while(tempA!=0){
                tempA/=tempB;
                tempCount++;
            }
            minstep=min(tempCount,minstep);
        }

        cout<<minstep<<endl;


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