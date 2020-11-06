/*
* 三数之和最接近值 
*/

#include <vector>
#include <iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		//最接近值记录
		int closest_d = 9999;
		int closest_value = 9999;

		//排序数组
		sort(nums.begin(),nums.end());

		//从第一个元素i开始
		for (int i =0; i<=nums.size()-2;)
		{
			int start_id = i + 1;
			int end_id = nums.size() - 1;

			while (start_id< end_id)
			{
				int temp_value = nums[i] + nums[start_id] + nums[end_id];
				int temp_close = temp_value - target;
				if (abs(temp_close) < abs(closest_d))
				{
					//当绝对值相近时，即找到接近值
					closest_d = abs(temp_close);
					closest_value = temp_value;

				}

				if (temp_close < 0)
				{
					start_id++;
				}
				else
				{
					end_id--;
				}

			}
			i++;
		}

		return closest_value;


		

	}
};

ostream& operator <<(ostream& output, vector<int> vc)
{
	for (int i = 0; i < vc.size() - 1; i++)
	{
		output << vc[i] << "  ";
	}
	output << endl;
	return output;
}

void main()
{
	/*
	[1,1,-1,-1,3]
		-1
	*/
	vector<int> vc = { 1,1,-1,-1,3 };
	Solution S;
	cout<<"输出结果为"<<S.threeSumClosest(vc, -1);


}