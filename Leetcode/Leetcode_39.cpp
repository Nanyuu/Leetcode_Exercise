/*
* 给定一个数组，和一个目标输出
* 求输出目标的所有可能组合
* 
Input: candidates = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]
Explanation:
2 and 3 are candidates, and 2 + 2 + 3 = 7. Note that 2 can be used multiple times.
7 is a candidate, and 7 = 7.
*/

#include <iostream>
#include <vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		map<int, vector<vector<int>>> proj;
		vector<vector<int>> output;
		for(int i =0 ; i<candidates.size();i++)
			proj.insert({ candidates[i], {{candidates[i]}} });


		map<int, vector<vector<int>>>::iterator iter;
		for (iter = proj.begin(); iter != proj.end() ; iter++)
		{
			int temp_num = iter->first;		//key 值

			for (int lp_vc_id = 0; lp_vc_id < iter->second.size();lp_vc_id++)
			{
				int temp_first = iter->second[lp_vc_id].back();
				for (int i = 0 ; i<candidates.size();i++)
				{
					if (temp_first > candidates[i])
					{
						continue;
					}
					int sum_num = temp_num + candidates[i];
					if (sum_num > target)
					{
						//如果比目标大
						break;
					}
					else
					{
						//如果比目标小
						vector<int> temp_vec;
						temp_vec = proj[temp_num][lp_vc_id];
						temp_vec.push_back(candidates[i]);
						proj[sum_num].push_back(temp_vec);

					}
				}
			}


		}
		return proj[target];

	}

	vector<vector<int>> combinationSum_bt(vector<int>& candidates, int target) {
		//backtracking
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> output;
		bt_search(output, {}, candidates, target, 0, 0);
		return output;



	}
	void bt_search(vector<vector<int>>& output,vector<int> temp_vec,vector<int> candidates, int target, int temp_total, int temp_id)
	{
		
		if (temp_total == target)
		{
			//等于目标则，数组中加入
			output.push_back(temp_vec);
		}
		
		for (int lp_i = temp_id; lp_i < candidates.size();lp_i++)
		{
			int sum = candidates[lp_i] + temp_total;
			if (sum <= target)
			{
				temp_vec.push_back(candidates[lp_i]);
				bt_search(output, temp_vec, candidates, target, sum, lp_i);
				temp_vec.pop_back();
			}
			else
			{
				break;
			}
		}

	}


};


ostream& operator << (ostream& output, vector<vector<int>> vc)
{
	for (int i = 0 ; i< vc.size(); i++)
	{
		for(int j =0 ;j<vc[i].size();j++)
			output << vc[i][j] << "  ";
		output << endl;
	}
	output << endl;
	return output;
}

void main()
{
	vector<int> vc = { 2,7,6,3,5,1 };
	int target = 9;


	Solution S;
	cout << "结果为：" << endl << S.combinationSum_bt(vc, target);
	cout << endl;
	cout << endl;


}