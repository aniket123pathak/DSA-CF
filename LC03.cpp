#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        if(height.size()==1||height.size()==2){
            return 0;
        }
        int trappedWater = 0;
        vector<int>left(height.size()),right(height.size());
        left[0]=INT64_MIN;
        right[height.size()-1]=INT64_MIN;

        for (int i = 1; i < height.size(); i++)
        {
           left[i]=max(left[i-1],height[i-1]);
        }
        for(int i=height.size()-2;i>=0;i--){
            right[i]=max(right[i+1],height[i+1]);
        }

        for(int i=0;i<height.size();i++){
            if(min(left[i],right[i])-height[i]>0){
                trappedWater+=min(left[i],right[i])-height[i];
            }
        }
        return trappedWater;
    }
};