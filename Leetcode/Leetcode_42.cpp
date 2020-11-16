/*
* 给定一组向量，求可容纳的水最大为多少
*/
#include<vector>
#include<iostream>

using namespace std;


class Solution {
public:
	int trap(vector<int>& height) {
		if (height.size()==0)
		{
			return 0;
		}
		int start = 0, end = height.size() - 1;
		bool search = (height[start]<height[end])? 1: 0;
		int temp_min = min(height[start],height[end]);
		int total_water = 0;
		while (start < end)
		{
			if (search)
			{
				//代表在从start开始找
				while (start<end )
				{
					if (height[start] <= temp_min)
					{
						total_water = total_water - height[start] + temp_min;

					}
					else if (height[start] <= height[end])
					{
						temp_min = height[start];
					}
					else
					{
						temp_min = height[end];
						search = false;
						end--;
						break;
					}
					start++;
				}
			}
			else
			{
				while (start<end )
				{
					if (height[end]<=temp_min)
					{
						total_water = total_water - height[end] + temp_min;
						
					}
					else if (height[end] <= height[start])
					{
						temp_min = height[end];
					}
					else
					{
						temp_min = height[start];
						search = true;
						start++;
						break;
					}
					end--;
					
				}
			}
		}

		return total_water;

	}
};

void main()
{
	vector<int> input = { 6,4,2,0,3,2,0,3,1,4,5,3,2,7,5,3,0,1,2,1,3,4,6,8,1,3 };
	Solution S;
	cout << S.trap(input) << endl;
}