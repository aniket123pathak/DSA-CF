#include<iostream>
using namespace std;

class Solution {
    public:
        void array(int i ,int arr[],int n) 
        {
            if(i>=n-1-i)
            {
                return ;
            }    
            swap(arr[i],arr[n-i-1]);
            array(i+1,arr,n);
        }
};

int main () {
    Solution s;
    int arr[] = {1,2,3,4,5,6};
    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    s.array(0,arr,6);
    for(int i=0;i<6;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}