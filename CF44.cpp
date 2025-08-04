#include<iostream>
using namespace std;

class Solution {
    public:
        void solve()
        {
            long long n,m,a,b;
            cin>>n>>m>>a>>b;
            if(n-a+1<a)
            {
                a=n+1-a;
            }
            if(m-b+1<b)
            {
                b=m-b+1;
            }

            long long verMAX=0,horMAX=0;
            
            verMAX=temp(a)+temp(m);
            horMAX=temp(n)+temp(b);

            cout<<1+min(verMAX,horMAX)<<"\n";
        }

        int temp(long long i)
        {
            long long count=0;
            while(i>1)
            {
                i=(i+1)/2;
                count++;
            }
            return count;
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