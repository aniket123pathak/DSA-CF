#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n,i;
            cin>>n;
            vector<long long>a(n);

            for(i=0;i<n;i++){
                cin>>a[i];
            }

            long long count = 0;

            for(i=1;i<n;i++){
                if(a[i]<a[i-1]){
                    count+=a[i-1]-a[i];
                    a[i]=a[i-1];
                }
            }
            cout<<count<<endl;
        }
};

int main () {
    Solution s;
    s.solve();
    return 0;
}