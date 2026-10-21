#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define v(a,n) vector<long long> a(n)
#define fin(i,x,n,a) for(i=x;i<n;i++) cin>>a[i]

class Solution {
public:
    void solve()
    {
        double n,i;
        cin>>n;
        if(n<0 || n>100){
            cout<<"Out of Intervals";
            return;
        }

        if(n>=0.0&&n<=25.0){
            cout<<"Interval [0,25]";
        } 
        else if(n>25.0&&n<=50.0){
            cout<<"Interval (25,50]";
        } 
        else if(n>50.0&&n<=75.0){
            cout<<"Interval (50,75]";
        } 
        else if (n > 75.0 && n <= 100.0) {
            cout << "Interval (75,100]";
        } 
        else {
            cout << "Out of Intervals";
        }
        return;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Solution s;    
    s.solve();
    return 0;
}