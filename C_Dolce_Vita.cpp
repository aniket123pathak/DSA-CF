#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

/*
7
1 2 2=>3
2 3 3=>2
3 4 4=>2
4 5 5=>1
5 6 6=>1
6 7 7=>1
7 8 8=>1
3
*/
class Solution {
public:
    void solve()
    {
        ll n,i,x;
        cin>>n>>x;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        sort(a.begin(),a.end());
        if(a[0]>x){
            cout<<0<<endl;
            return;
        }
        vector<ll>pf(n);
        pf[0]=a[0];
        for(i=1;i<n;i++){
            pf[i]=pf[i-1]+a[i];
        }
        
        ll count = 0;
        // logic was right , i  just have to calculate how much days we can buy an item
        // insted of while loop , now i just have to solve the mathematical equation.. 
        for(i=0;i<n;i++){
            ll temp = i+1;//insted of while loop
            if(pf[i]>x){// cost = pf[i]+(noOfIthem * noOfDay)
                break;// cost <= x => pf[i]+(noOfIthem * noOfDay)<=x
            }// noOfDay = (x-pf[i])/noOfItem  +1
            count+= ((x-pf[i])/temp) +1;
        }
        cout<<count<<endl; 
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