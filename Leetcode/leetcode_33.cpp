/*
*	Leetcode 33
*	在一个旋转后的排序数组中找到对应的值index
* 
	Suppose that nums is rotated at some pivot unknown to you beforehand (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

	If target is found in the array return its index, otherwise, return -1.
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int start_id = 0;
		int end_id = nums.size() - 1;
		while (start_id!=end_id)
		{
			//二分查找
			int mid = start_id + (end_id - start_id) / 2;

			//在大小数组
			bool in_small = (nums[mid] <= nums[end_id]) ? 1 : 0;

			if ( (nums[mid]<target && nums[end_id]>=target && in_small)
				|| (nums[mid]<target && !in_small)
				|| (nums[mid]>=target && !in_small && nums[start_id]>target))
			{
				start_id = mid + 1;
			}
			else
			{
				end_id = mid;
			}
		}
		if (nums[start_id] == target)
		{
			return start_id;
		}
		return -1;
	}
};

void main()
{
	vector<int> nums = { 4,5,6,7,8,1,2,3};
	int target = 4;
	Solution S;
	cout << "index 为" << S.search(nums, target);
}