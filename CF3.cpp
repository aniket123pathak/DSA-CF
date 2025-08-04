#include<iostream>
using namespace std;

class Solution {
    public:
        void Door(int n,int x,int arr[])
        {
            int i = 0;
            int z = 0;
            while(i<n&&arr[i]!=1)
            {   
                z++;
                i++;
            }
            if((n-z)<x)
            {
                cout<<"Yes\n";
            }
            else{
                i=n-1;
                while(i>=z&&arr[i]!=1)
                {
                    i--;
                }
                if((i-z)<x)
                {
                    cout<<"Yes\n";
                }
                else
                {
                    cout<<"No\n";
                }
            }
            
        }
};

int main () {
    Solution s;
    int tc;
    cin>>tc;
    int n,x;
    int arr[10];
    for(int i = 0 ;i<tc;i++)
    {
        cin>>n>>x;
        for(int i =0 ;i<n;i++)
        {
            cin>>arr[i];
        }
        s.Door(n,x,arr);
    }
    
    
    return 0;
}