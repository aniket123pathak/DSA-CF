#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

/*
    answer always -1 for n=1 2 3
    

*/

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
        if(n==1||n==2||n==3){
            cout<<"-1\n";
            return;
        }

        ll first = 0 ;
        ll last = n-1;

        ll mx = n;
        ll mn = 1;

        while(first<=last){
            if(a[first]==mn){
                first++;
                mn++;
            }
            else if(a[first]==mx){
                first++;
                mx--;
            }
            else if(a[last]==mn){
                last--;
                mn++;
            }
            else if(a[last]==mx){
                last--;
                mx--;
            }
            else{
                cout<<first+1<<" "<<last+1<<endl;
                return;
            }
        }
        cout<<"-1\n";
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