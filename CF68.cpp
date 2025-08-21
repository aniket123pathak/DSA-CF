#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n,x,i,count=0;
            cin>>n>>x;
            vector<long long> v(n);
            for(i=0;i<n;i++){
                cin>>v[i];
            }
            sort(v.begin(),v.end());
            for(i=n-1;i>=0;i--){
                if(v[i]>=x){
                    count++;
                }
                else{
                    break;
                }
            }
            if(count==n){
                cout<<n<<"\n";//4 5 3 3 2 6-> 2 3 3 4 5 6
                return;
            }
            n=i+1;
            long long j = 0;

            while(i>0){
            for(i=n-1;i>=0;i--)
            {
                if(v[n-1-j]*(n-i)>=x){
                    count++;
                    n=n-1-j;
                    j=0;
                    break;
                }
                else{
                j++;
                }
            }
        }
        cout<<count<<endl;
        }
};
int main () {
    Solution s;
    int tc;
    cin>>tc;
    while(tc-->0)
    {
        s.solve();
    }
    return 0;
}


/*
5
6 4
4 5 3 3 2 6
4 10
4 2 1 3
5 3
5 3 2 3 2
3 6
9 1 7
6 10
6 1 3 6 3 2
*/
/*
4 0 4 2 1
*/