/*
* 给定一个数组串，求连续数的最大输出值
*/
#include<vector>
#include<iostream>
using namespace std;


class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.size()==0)
		{
			return 0;
		}
		int temp = nums[0];
		int max_num = temp;
		for (int i = 1; i < nums.size(); i++)
		{
			(temp < 0) ? temp = nums[i] : temp = nums[i] + temp;
			max_num = max(max_num, temp);
		}
		return max_num;

	}
};

void main()
{
	vector<int> input = { -2,1,-3,4,-1,2,1,-5,4 };
	Solution S;
	cout << S.maxSubArray(input) << endl;
}

