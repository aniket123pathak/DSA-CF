#include<iostream>
using namespace std;

class Solution {
    public:
        void solve ()
        {
            int n;
            cin>>n;
            string a;
            cin>>a;
            int count=0;
            for(int i = 0;i<n;i++)
            {
                if(a[i]=='1')
                  count++;
            }
            int n1=count,sum=0;
            for(int i = 0;i<n;i++)
            {
                count=n1;
                if(a[i]=='0')
                {
                    count++;
                    sum+=count;
                }
                if(a[i]=='1')
                {
                    count--;
                    sum+=count;
                }
            }
            cout<<sum<<"\n";
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