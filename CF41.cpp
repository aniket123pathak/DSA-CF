#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
    public:
        void solve()
        {
            string a;
            cin>>a;
            long long i;
            long long count=1,count2=0;
            for(i=1;i<a.length();i++)
            {
                if(a[i]=='(')
                {
                    count++;
                    continue;
                }
                if(a[i]==')')
                {
                  count2++;
                }
                if(count==count2)
                {
                    i++;
                    break;
                }
            }
            if(a[i]!='\0')
            {
                cout<<"Yes\n";
                return;
            }
            cout<<"No\n";


        }
};

int main () {
    Solution s;
    int tc;
    cin>>tc;
    while(tc-->0)s.solve();
    return 0;
}