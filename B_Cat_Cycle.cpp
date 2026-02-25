#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

/*
11 25

 3  4  5  6  7  8  9  10  11  1   2   B
11 10  9  8  7  6  5  4   3   2   1   A


1  2  3  4 5 6 7 8 9 10 11 12  B
12 11 10 9 8 7 6 5 4 3 2 1   A

*/
class Solution {
public:
    void solve()
    {
        ll n,i,k;
        cin>>n>>k;

        if(n%2==0){
            if(k%n==0){
                cout<<n<<endl;
            }
            else{
                cout<<k%n<<endl;
            }
            return;
        }
        ll ele = n/2;

        ll div = (k-1)/ele;
        
        ll total = div+(k-1);

        cout<<(total%n)+1<<endl;

        


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