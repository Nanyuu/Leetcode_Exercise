/*
* LeetCode 46 全排列，找到输入数组的所有可能元素排序
*/

#include<iostream>
#include <vector>

using namespace std;


class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> output;
		inner(output, nums, {});
		return output;
		
	}

	void inner(vector<vector<int>> &output,vector<int> nums, vector<int> temp_vec)
	{
		//出口
		if (temp_vec.size() == nums.size())
		{
			output.push_back(temp_vec);
			return;
		}
		
		for(int i=0; i<nums.size();i++)
		{
			if (temp_vec.end() == find(temp_vec.begin(),temp_vec.end(),nums[i]))
			{
				temp_vec.push_back(nums[i]);
				inner(output, nums, temp_vec);
				temp_vec.pop_back();
			}

		}
	}
};

//重载输出
ostream& operator<< (ostream& output, const vector<vector<int>> &vc)
{
	for (int lp_i = 0 ; lp_i<=vc.size()-1;lp_i++)
	{
		for (int lp_j = 0 ; lp_j < vc[lp_i].size();lp_j++)
		{
			output << vc[lp_i][lp_j]<<"  ";
		}
		output << endl;
	}
	return output;

}

void main()
{
	vector<int> input = { 1,2,3 };
	Solution S;
	cout<<S.permute(input);

}

