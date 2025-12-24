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
        long long n,x,sum=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>x;
            sum+=x;
        }

        cout<<float(sum)/float(n);
    }
};

int main() {
    Solution s;
    int tc;
    
    
        s.solve();
    return 0;
}