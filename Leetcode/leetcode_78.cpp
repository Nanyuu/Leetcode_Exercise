/*
* leetcode_78 组合
* 给定一组数 如[1,2,3]
* 返回所有的组合
*[
*	[],
*	[1],
*	[1,2],
*	[1,2,3],
*	[2] ...
* ]
*/

#include<vector>
#include<iostream>
#include"ostream_overload.h"
using namespace std;

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> temp_vec;
		res.push_back({});	// 为空的也要计算
		for (int i = 0 ; i<nums.size(); i++)
		{
			temp_vec.push_back(nums[i]);
			inner_subset(res, nums, temp_vec, i+1);
			temp_vec.pop_back();
		}
		return res;
	}
	void inner_subset(vector<vector<int>> &res,vector<int>& nums, vector<int> &temp_vec, int temp_id)
	{
		res.push_back(temp_vec);
		//if (temp_id == nums.size() - 1)
		//{
		//	return;
		//}
		for (int i = temp_id; i < nums.size();i++)
		{
			temp_vec.push_back(nums[i]);
			inner_subset(res, nums, temp_vec, i + 1);
			temp_vec.pop_back();
		}
		return;

	}
};


int main()
{
	vector<int> my_vec = { 1,2,3 };
	Solution S;
	vector<vector<int>> res;

	res = S.subsets(my_vec);

	cout << res;

}