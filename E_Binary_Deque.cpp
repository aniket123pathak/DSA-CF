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
        ll n,i,s;
        cin>>n>>s;
        vector<ll>a(n);
        ll sum1=0;
        for(i=0;i<n;i++){
           cin>>a[i];
           if(a[i]==1){
            sum1++;
           }
        }

        if(sum1<s){
            cout<<-1<<endl;
            return;
        }
        if(sum1==s){
            cout<<0<<endl;
            return;
        }
        ll rem1 = sum1-s;

        vector<ll>front;
        vector<ll>back;
        ll temp=0;
        for(i=0;i<n;i++){
            temp+=a[i];
            if(a[i]==1)
                front.push_back(i);
            if(temp==rem1){
                break;
            }
        }
        temp=0;
        for(i=n-1;i>=0;i--){
            temp+=a[i];
            if(a[i]==1)
                back.push_back(i);
            if(temp==rem1){
                break;
            }
        }

        ll sz = front.size();
        ll mn = min(front[sz-1]+1,n-back[sz-1]);     
        
        ll left = sz-2;
        ll right = 0;

        for(i=0;i<sz-1;i++){
            mn = min(mn,n-back[i]+front[left-i]+1);
        }
        cout<<mn<<endl;
    
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