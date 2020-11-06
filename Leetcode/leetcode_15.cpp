/*
* ���������ҵ�3������Ҫ���Ϊ0
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
		// ʱ�临�Ӷȹ���
		if (nums.size()<3)
		{
			return vector<vector<int>> {};
		}


		// ����two_sum��˼�룬����map�������ֵ
		vector<vector<int>> output;

		multimap<int, vector<int>> record_mat;

		for (int num_id_1 = 0; num_id_1 < nums.size() - 2; num_id_1++)
		{
			record_mat.clear();
			//��ͷ��β����
			for (int num_id_2 = num_id_1+1; num_id_2<nums.size();num_id_2++)
			{
				
				//����Ƿ��ж�Ӧ��ֵ
				
				auto point = record_mat.equal_range(nums[num_id_2]);
				if (point.first == end(record_mat))
				{
					//û�ж�Ӧ��ֵ
				}
				else
				{
					//�ж�Ӧ��ֵ
					for (auto iter = point.first; iter != point.second; iter++)
					{
						vector<int> temp_vector = { iter->second[0], iter->second[1], nums[num_id_2] };
						sort(temp_vector.begin(), temp_vector.end());
						bool flag = 0;

						for (int iner_lop = 0; iner_lop < output.size(); iner_lop ++)
						{
							if (output[iner_lop] == temp_vector)
							{
								flag = 1; //�Ѿ��������pair
								break;
							}
						}

						if (flag == 0)
						{
							output.push_back(temp_vector);
						}
					}
				}

				//��Ϊtarget key �����
				int target_key = 0 - nums[num_id_1] - nums[num_id_2];
				auto point_target_key = record_mat.equal_range(target_key);
				if (point_target_key.first == end(record_mat))
				{
					//��target key �����, ִ�в���.
					record_mat.insert({ target_key, vector<int> {nums[num_id_1],nums[num_id_2]} });
				}
				else
				{
					//��target key ��������Ƚ��Ƿ���ͬ.
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
		//��������ٽ�������

		//������鳤��С��3 ��ֱ�ӷ���
		if (nums.size()<3)
		{
			return {};
		}

		//��ԭ��������
		sort(nums.begin(), nums.end());

		//��������õ�����
		vector<vector<int>> output = {};

		for (int i =0; i<nums.size()-2;)
		{
			//����ÿһ���ڵ�
			
			int start = i + 1;	//��ֵ
			int end = nums.size() - 1;	//��ֵ

			while (start < end)
			{
				if (0 == nums[i] + nums[start] + nums[end])
				{	//����з���������ֵ������
					output.push_back({ nums[i],nums[start],nums[end] });

					//�ƶ�start��end��ָ����һ��
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
					//��ʱ Ӧ��������ֵ
					start++;
					while ((start < end) && nums[start] == nums[start-1])
					{
						start++;
					}
				}
				else
				{
					//��ʱ Ӧ�ü���ֵ
					end--;
					while ((start < end) && nums[end] == nums[end+1])
					{
						end--;
					}
				}

			}

			// Ϊ�˹��duplicate 
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