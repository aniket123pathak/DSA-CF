#include<iostream>
using namespace std;

class Solution {
    public:
        int Contest(int tc)
        {
            int i=0,j=0;
            int arr[1000][3];
            for(i=0;i<tc;i++)
            {
                for(j=0;j<3;j++)
                {
                    cin>>arr[i][j];
                }
            }
            int count=0;
            int op=0;
            for(i=0;i<tc;i++)
            {
                for(j=0;j<3;j++)
                {
                    if(arr[i][j]==1)
                    {
                        count++;
                    }
                    if(count==2 ||(j==1&&count>1))
                    {
                        break;
                    }
                }
                if(count>=2)
                {
                    op++;
                }
                count=0;
            }
            return op;
        }
        
};

int main () {
    Solution s;
    int tc;
    cin>>tc;
    cout<<s.Contest(tc);
    return 0;
}