#include<iostream>
using namespace std;

class Solution {
    public:
        int pos(int n,int s)
        {
            int i = 0;
            float arr[10];
            for(i=0;i<n;i++)
            {
                cin>>arr[i];
            }
            if(s>=arr[n-1])
            {
                return s-arr[0];
            }
            else if(s<=arr[0])
            {
                return arr[n-1]-s;
            }
            else{
                if((arr[n-1]-s)<=(s-arr[0]))
                {
                    return arr[n-1]-s+arr[n-1]-arr[0];
                }
                else{
                    return s-arr[0]+arr[n-1]-arr[0];
                }
            }
        }
        
};

int main () {
    Solution S;
    int tc;
    cin>>tc;
    int n,s;
    while(tc>0)
    {
        cin>>n>>s;
        cout<<S.pos(n,s);
        tc--;
        cout<<endl;
    }
    return 0;
}