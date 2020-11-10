/*
* 给定一个升序数组
* 找到一个目标的对应位置，如果没有该节点，则选择最好的位置
*/

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		if (nums.size() ==0)
		{
			return 0;
		}

		//二分查找
		int start = 0, end = nums.size() - 1;

		if (target > nums[end])
		{
			return nums.size();
		}

		while (start <end)
		{
			int mid = start + (end - start)/2;
			if (nums[mid]<target)
			{
				start = mid + 1;
			}
			else
			{
				end = mid;
			}
		}
		return start;

	}
};

void main()
{
	vector<int> vc = { 1,2,5 };
	int target = 3;
	Solution S;
	cout<< S.searchInsert(vc, target);
}