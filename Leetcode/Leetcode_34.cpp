/*
* ��һ�������������ҵ�ֵ����Ӧ������
* �� 
	Input: nums = [5,7,7,8,8,10], target = 8
	Output: [3,4]
* 
*/
#include<vector>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.size()==0)
		{
			return vector<int> {-1, -1};
		}
		//���ֲ���
		int start_id = 0;
		int end_id = nums.size()- 1;
		while (start_id!=end_id)
		{
			int mid = start_id + (end_id - start_id) / 2;
			if (nums[mid] < target)
			{
				start_id=mid+1;
			}
			else
			{
				end_id = mid;
			}
		}
		if (nums[start_id] != target)
		{
			return vector<int> {-1, -1};
		}

		int pre = start_id;

		//��һ�����ֲ����ҵ��ıض��ǵ�һ��ָ���Ӧ�ڵ��λ��


		int post = start_id;

		while ((post + 1 < nums.size()) && nums[post + 1] == target)
		{
			post++;
		}

		return vector<int> {pre, post};
	}

	vector<int> searchRange_1(vector<int>& nums, int target) {
		//˫���ֲ���
		if (nums.size() == 0)
		{
			return vector<int> {-1, -1};
		}
		//���ֲ���
		int start_id = 0;
		int end_id = nums.size() - 1;
		while (start_id != end_id)
		{
			int mid = start_id + (end_id - start_id) / 2;
			if (nums[mid] < target)
			{
				start_id = mid + 1;
			}
			else
			{
				end_id = mid;
			}
		}
		if (nums[start_id] != target)
		{
			return vector<int> {-1, -1};
		}

		int pre = start_id;

		//��һ�����ֲ����ҵ��ıض��ǵ�һ��ָ���Ӧ�ڵ��λ��

		//���еڶ������ֲ��ң��ҵ�β��
		end_id = nums.size() - 1;
		while (start_id<end_id)
		{
			int mid = start_id + (end_id - start_id) / 2 + 1;
			if (nums[mid] > target)
			{
				end_id = mid -1;
			}
			else
			{
				start_id = mid;
			}
		}


		return vector<int> {pre, end_id};
	}
};

void main()
{
	vector<int> vec = {1,1,1,2,2,2,2,2,2,2 };
	int traget = 2;
	Solution S;
	
	vector<int> result = S.searchRange(vec, traget);
	cout << "pre = " << result[0] << endl << "end = " << result[1] << endl;

}