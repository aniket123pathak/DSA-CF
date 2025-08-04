#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int Score(int n,int k)
        {
            int i=0;
            int count=0;
            int arr[50];
            for(i=0;i<n;i++)
            {
                cin>>arr[i];
            }
            for(i=0;i<n;i++)
            {
                if(arr[k-1]<=arr[i]&&arr[i]>0)
                {
                    count++;
                }
            }
            return count;
        }
};

int main () {
    Solution s;
    int n,k;
    cin>>n>>k;
    cout<<s.Score(n,k);
    return 0;
}