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
        ll n;
        cin>>n;
        
        ll count=0;

        while(n!=0){
            if(n-5>=0){
                n-=5;
                count++;
            }
            else if(n-4>=0){
                n-=4;
                count++;
            }
            else if(n-3>=0){
                n-=3;
                count++;
            }
            else if(n-2>=0){
                n-=2;
                count++;
            }
            else if(n-1>=0){
                n-=1;
                count++;
            }
        }
        cout<<count<<endl;
    }
};

int main() {
    Solution s;
        s.solve();
    
    return 0;
}