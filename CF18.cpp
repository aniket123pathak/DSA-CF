#include<iostream>
using namespace std;

class Solution {
    public:
        int matrix()
        {
            int n,m;
            int i,j;
            int arr[100000][100000];
            int max=INT_MIN;
            cin>>n>>m;
            for(i=0;i<n;i++)
            {
                for(j=0;j<m;j++)
                {
                    cin>>arr[i][j];
                    if(arr[i][j]>max)
                    {
                        max=arr[i][j];
                    }
                }
            }
            



        }
};

int main () {
    Solution s;
    int tc;
    cin>>tc;
    while(tc--)
    {
        cout<<s.matrix();
    }
    return 0;
}