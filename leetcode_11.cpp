/*
* Leetcode 11
* ����ľ�峤�ȣ�������ݻ�
*/
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		//�뱩���ⷨ����ȥ���ֲ���Ҫ�����ľ��
		if (height.size() == 1)
		{
			return 0;
		}
		long long max_vol = 0;

		for (int id_left = 0; id_left<height.size();id_left++)
		{
			int id_right = id_left;
			//��ȥһ���ֲ���Ҫ�ļ���
			id_right = id_right + max_vol / height[id_left];
			for (; id_right<height.size(); id_right++)
			{
				long long temp_vol;
				//��ȥһ���ֲ���Ҫ�����ľ��
				if (height[id_left] > height[id_right])
				{
					temp_vol = height[id_right] * (id_right - id_left);
				}
				else
				{
					temp_vol = height[id_left] * (id_right - id_left);
				}

				// �жϸı�
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
		//optim�ⷨ O(n) , ���������ҿ�ʼ
		//����Ҫ�ҵ����������Ҹ����volume�� ����Ҫʹ��height���� min(��ߣ��Ҹ�)����˿��Բ�������Ѱ��

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
	cout << "����ݻ�Ϊ" << S.maxArea_optim(height);
}