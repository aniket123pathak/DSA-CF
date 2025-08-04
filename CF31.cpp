#include<iostream>
using namespace std;

class Solution {
    public:
        void Square()
        {
            int n;
            cin>>n;
            int p1=49;
            int p2=50;
            for(int i = 0;i<100;i++)
            {
                while(p1>=0&&p2<100)
                {
                    if((p1+i)*(p1+i)==n)
                    {
                        cout<<i<<" "<<p1<<endl;
                        return ;
                    }  
                    if((p2+i)*(p2+i)==n)
                    {
                        cout<<i<<" "<<p2<<endl;
                        return ;
                    }
                    p1--;
                    p2++;
                }
            }
            cout<<"-1"<<endl;
        }
};

int main () {
    Solution s;
    int tc;
    cin>>tc;
    while(tc-->0)
    {
        s.Square();
    }   
    return 0;
}