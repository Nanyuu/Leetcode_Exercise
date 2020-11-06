/*
* Leetcode 11
* 给定木板长度，求最大容积
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		//半暴力解法，除去部分不需要计算的木板
		if (height.size() == 1)
		{
			return 0;
		}
		long long max_vol = 0;

		for (int id_left = 0; id_left<height.size();id_left++)
		{
			int id_right = id_left;
			//略去一部分不需要的计算
			id_right = id_right + max_vol / height[id_left];
			for (; id_right<height.size(); id_right++)
			{
				long long temp_vol;
				//略去一部分不需要计算的木板
				if (height[id_left] > height[id_right])
				{
					temp_vol = height[id_right] * (id_right - id_left);
				}
				else
				{
					temp_vol = height[id_left] * (id_right - id_left);
				}

				// 判断改变
				if (temp_vol > max_vol)
				{
					max_vol = temp_vol;
				}

			}
			

		}
		return max_vol;

	}

	int maxArea_optim(vector<int> height)
	{
		//optim解法 O(n) , 从最左最右开始
		//由于要找到比最左最右更大的volume， 必须要使其height大于 min(左高，右高)，因此可以不断往内寻找

		int max_vol = 0;
		int start = 0, end = height.size() - 1;
		while (start < end)
		{
			int min_h = min(height[start], height[end]);
			max_vol = max(max_vol, min_h * (end - start));
			while (height[start] <= min_h && start<end)
			{
				start++;
			}
			while (height[end] <= min_h && start < end)
			{
				end--;
			}
		}
		return max_vol;
	}
};

void main()
{
	vector<int> height = { 1};
	Solution S;
	cout << "最大容积为" << S.maxArea_optim(height);
}