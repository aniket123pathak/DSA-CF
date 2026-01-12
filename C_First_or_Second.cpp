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
        v(a,n);
        fin(i,0,n,a);
        ll x=0;
        
        for(i=0;i<n-2;i++){
            ll first =a[i+1];
            ll second=a[i+2];

            if(first>0&&second>0){
                x+=first;
                a.erase(a.begin()+0);
            }
            else if(first<0&&second<0){
                x+=abs(second);
                a.erase(a.begin()+1);
            }
            else if(first>0&&second<0){
                ll max1 = max(first,abs(second));
                if(max1==first){
                    x+=first;
                    a.erase(a.begin()+0);
                }
                else{
                    x+=abs(second);
                    a.erase(a.begin()+1);
                }
            }
            else{
                ll min1 = min(abs(first),second);

                if(min1==abs(first)){
                    x-=abs(first);
                    a.erase(a.begin());
                }
                else{
                    x-=second;
                    a.erase(a.begin()+1);
                }
            }
        }
        cout<<x<<endl;
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