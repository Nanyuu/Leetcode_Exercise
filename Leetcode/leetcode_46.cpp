/*
* LeetCode 46 ȫ���У��ҵ�������������п���Ԫ������
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
		//����
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

//�������
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

