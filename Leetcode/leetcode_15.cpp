/*
* 在数组中找到3个数，要求和为0
* 3 Sum
* 
*/
#include <vector>
#include<iostream>
#include<map>
#include <algorithm>

using namespace std;



class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		// 时间复杂度过高
		if (nums.size()<3)
		{
			return vector<vector<int>> {};
		}


		// 利用two_sum的思想，借助map来找相等值
		vector<vector<int>> output;

		multimap<int, vector<int>> record_mat;

		for (int num_id_1 = 0; num_id_1 < nums.size() - 2; num_id_1++)
		{
			record_mat.clear();
			//从头到尾遍历
			for (int num_id_2 = num_id_1+1; num_id_2<nums.size();num_id_2++)
			{
				
				//检查是否有对应数值
				
				auto point = record_mat.equal_range(nums[num_id_2]);
				if (point.first == end(record_mat))
				{
					//没有对应数值
				}
				else
				{
					//有对应数值
					for (auto iter = point.first; iter != point.second; iter++)
					{
						vector<int> temp_vector = { iter->second[0], iter->second[1], nums[num_id_2] };
						sort(temp_vector.begin(), temp_vector.end());
						bool flag = 0;

						for (int iner_lop = 0; iner_lop < output.size(); iner_lop ++)
						{
							if (output[iner_lop] == temp_vector)
							{
								flag = 1; //已经有了这个pair
								break;
							}
						}

						if (flag == 0)
						{
							output.push_back(temp_vector);
						}
					}
				}

				//作为target key 的情况
				int target_key = 0 - nums[num_id_1] - nums[num_id_2];
				auto point_target_key = record_mat.equal_range(target_key);
				if (point_target_key.first == end(record_mat))
				{
					//无target key 的情况, 执行插入.
					record_mat.insert({ target_key, vector<int> {nums[num_id_1],nums[num_id_2]} });
				}
				else
				{
					//有target key 的情况，比较是否相同.
					int flag = 0;
					for (auto iter = point_target_key.first; iter != point_target_key.second; iter++)
					{
						if ( (iter->second[0] == nums[num_id_1] && nums[num_id_2] == iter->second[1])||(iter->second[1] == nums[num_id_1] && nums[num_id_2] == iter->second[0]))
						{
							flag = 1;
							break;
						}
					}
					if (flag == 0)
					{
						record_mat.insert({ target_key, vector<int> {nums[num_id_1],nums[num_id_2]} });
					}
				}
			}

		}

		return output;
	}


	vector<vector<int>> threeSum_1(vector<int>& nums) {
		//先排序后，再进行搜索

		//如果数组长度小于3 则直接返回
		if (nums.size()<3)
		{
			return {};
		}

		//对原数组排序
		sort(nums.begin(), nums.end());

		//创建输出用的数组
		vector<vector<int>> output = {};

		for (int i =0; i<nums.size()-2;)
		{
			//遍历每一个节点
			
			int start = i + 1;	//左值
			int end = nums.size() - 1;	//右值

			while (start < end)
			{
				if (0 == nums[i] + nums[start] + nums[end])
				{	//如果有符合条件的值，插入
					output.push_back({ nums[i],nums[start],nums[end] });

					//移动start和end，指向下一个
					start++;
					end--;
					while ((start<end) && nums[start] == nums[start - 1])
					{
						start++;
					}
					while ((start < end) && nums[end] == nums[end+1])
					{
						end--;
					}
				}
				else if (nums[i] + nums[start] + nums[end] < 0)
				{
					//此时 应该增加数值
					start++;
					while ((start < end) && nums[start] == nums[start-1])
					{
						start++;
					}
				}
				else
				{
					//此时 应该减少值
					end--;
					while ((start < end) && nums[end] == nums[end+1])
					{
						end--;
					}
				}

			}

			// 为了规避duplicate 
			i++;
			while ((i < nums.size() - 2) && nums[i]== nums[i-1])
			{
				i++;
			}
			
		}
		return output;

	}
};


ostream& operator<<(ostream& output, vector<vector<int>> target)
{
	for (int i = 0 ; i< target.size();i++)
	{
		output << target[i][0] << "  " << target[i][1] << "  " << target[i][2] << endl;
	}
	return output;
}

void main()
{
	vector<int> a = { -1,0,1,2,-1,-4 };

	Solution S;
	vector<vector<int>> output = S.threeSum_1(a);
	cout << output;
}