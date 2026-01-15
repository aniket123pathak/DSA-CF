#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

/*
    if n==1 then contrast zero so one ele in b
    if contrast == 0 then also one ele in b 

    ex 5 4 2 1 0 0 4 contrast = 9
    => 5 4 2 1 0 4 contrast 9
    => 5 0 4 contrast 9

    so if we remove the elements in decending order and ascending also
    if we have to check both ascending and descending so to avoid overlap 
    we have to remove the consecative dulicates
    ..then we may get ans...



*/

class Solution {
public:
    void solve()
    {
        ll n,i;
        cin>>n;
        vector<ll>a(n);
        for(i=0;i<n;i++){
           cin>>a[i];
        }
        vector<ll>b;
        for(i=0;i<n;i++) {
            if(i==0||a[i]!=a[i-1]){
                b.push_back(a[i]);
            }
        }
        if(n==1){
            cout<<"1\n";
            return;
        }
        ll contrast = 0 ;
        for(i=0;i<b.size();i++){
            contrast+=abs(b[i]-b[i+1]);
        }
        if(contrast == 0 ){
            cout<<"1\n";
            return;
        }
        ll cur = 0 ;
        ll next = 1;

        ll count = 0 ;
        vector<ll>c;

        while(next<b.size()){   
            if(b[next-1]>=b[next]){ // 5 4 1 2 0 0 4
                next++;
            }
            else{
                count+=max(next-cur-2,(ll)0);
                cur=next;
                next++;
            }
        }
        cur=0;
        next=1;

        while(next<b.size()){   
            if(b[next-1]<=b[next]){ // 5 4 2 1 0 0 4
                next++;
            }
            else{
                count+=max(next-cur-2,(ll)0);
                cur=next;
                next++;
            }
        }

        cout<<n-count<<endl;




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