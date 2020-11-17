/*
* ��Ծ����Զ����
* ����һ�����飬���ܷ������յ�
*/

#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		//��dp
		int max_jump = 0;
		for (int i = 0; i <= max_jump; i++)
		{
			max_jump = max(max_jump, i + nums[i]);
			if (max_jump>= nums.size()-1)
			{
				return true;
			}
		}
		return false;
	}
};

void main()
{
	vector<int> input = { 3,2,1,0,4 };
	Solution S;
	cout << S.canJump(input) << endl;
}