#include<iostream>
using namespace std;

class Solution {
    public:
        int matrix()
        {
            int i,j;
            int arr[5][5];
            for(i = 0 ; i<5;i++)
            {
                for(j = 0 ;j < 5;j++)
                {
                    cin>>arr[i][j];
                }
            }
            for(i = 0 ; i<5;i++)
            {
                for(j = 0 ;j<5;j++)
                {
                    if(arr[i][j]==1)
                    {
                        i=i-2;
                        j=j-2;
                        if(i<0){
                            i=(-i);
                        }
                        if(j<0){
                            j=(-j);
                        }
                        return i+j;
                    }
                }
            }
            
        }
};

int main () {
    Solution s;
    cout<<s.matrix();
    return 0;
}