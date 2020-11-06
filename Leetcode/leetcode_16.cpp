/*
* ����֮����ӽ�ֵ 
*/

#include <vector>
#include <iostream>
#include<algorithm>

using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		//��ӽ�ֵ��¼
		int closest_d = 9999;
		int closest_value = 9999;

		//��������
		sort(nums.begin(),nums.end());

		//�ӵ�һ��Ԫ��i��ʼ
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
					//������ֵ���ʱ�����ҵ��ӽ�ֵ
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
	cout<<"������Ϊ"<<S.threeSumClosest(vc, -1);


}