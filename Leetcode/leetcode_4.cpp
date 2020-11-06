#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		vector<int> nums_sum(nums1.size() + nums2.size());

		int nums1_id = 0, nums2_id = 0;
		int sum_id = 0;
		if (nums2.size() != 0 && nums1.size() != 0)
		{

			for (; sum_id < nums_sum.size() - 1; sum_id++)
			{
				if (nums1[nums1_id] <= nums2[nums2_id])
				{
					nums_sum[sum_id] = nums1[nums1_id];
					nums1_id++;
					if (nums1_id >= nums1.size())
					{
						sum_id++;
						break;
					}
				}
				else
				{
					nums_sum[sum_id] = nums2[nums2_id];
					nums2_id++;
					if (nums2_id >= nums2.size())
					{
						sum_id++;
						break;
					}
				}
			}
		}

		if (nums2_id < nums2.size())
		{
			for (; nums2_id < nums2.size(); nums2_id++)
			{
				nums_sum[sum_id] = nums2[nums2_id];
				sum_id++;
			}
		}
		else if(nums1_id< nums1.size())
		{
			for (; nums1_id < nums1.size(); nums1_id++)
			{
				nums_sum[sum_id] = nums1[nums1_id];
				sum_id++;
			}
		}

		int mid_num = nums_sum.size() / 2;
		//找到中位数
		if (nums_sum.size()%2)
		{
			return nums_sum[mid_num];
		}
		else
		{
			return float((nums_sum[mid_num] + nums_sum[mid_num - 1]))/2;
		}

	}

	double findMedianSortedArrays_1(vector<int>& nums1, vector<int>& nums2) {
		//尝试不构造数组，直接找中位数
		int mid = (nums1.size() + nums2.size())/2;
		int nums1_id = 0, nums2_id = 0;
		int sum_id = 0;
		int temp_value = 0;
		int temp_last = 0;
		if (nums1.size() != 0 && nums2.size() != 0)
		{
			while (sum_id <= mid)
			{
				sum_id++;
				if (nums1[nums1_id] < nums2[nums2_id])
				{
					temp_last = temp_value;
					temp_value = nums1[nums1_id];
					nums1_id++;
					if (nums1_id >= nums1.size())
					{
						break;
					}
				}
				else
				{
					temp_last = temp_value;
					temp_value = nums2[nums2_id];
					nums2_id++;
					if (nums2_id >= nums2.size())
					{
						break;
					}
				}
			}
		}
		if (sum_id <= mid)
		{
			if (nums1_id < nums1.size())
			{
				while (sum_id <= mid)
				{
					temp_last = temp_value;
					temp_value = nums1[nums1_id];
					sum_id++;
					nums1_id++;
				}
			}
			else
			{
				while (sum_id <= mid)
				{
					temp_last = temp_value;
					temp_value = nums2[nums2_id];
					sum_id++;
					nums2_id++;
				}
			}
		}

		if ((nums1.size()+nums2.size())%2)
		{
			return temp_value;
		}
		else
		{
			return float(temp_value + temp_last) / 2;
		}


	}


	double findMedianSortedArrays_optim(vector<int> array_a, vector<int> array_b)
	{
		if (array_a.size() > array_b.size())
		{
			return findMedianSortedArrays_optim(array_b, array_a);
		}
		bool is_odd = (array_a.size() + array_b.size()) % 2;

		int idx_i = 0, idx_j = 0;

		int low = 0;
		int high = array_a.size() - 1;

		if (array_a.size() == 0)
		{
			//a数组为空时
			if (is_odd)
			{
				return array_b[array_b.size() / 2];
			}
			else
			{
				return float(array_b[(array_b.size() / 2 - 1)] + array_b[array_b.size() / 2]) / 2;
			}
		}

		while (true)
		{
			idx_i = low + (high - low) / 2;
			idx_j = (array_a.size() + array_b.size()+1) / 2 - idx_i;



			if ( idx_i<array_a.size() &&array_a[idx_i] <array_b[idx_j-1])
			{
				low = idx_i + 1;
			}
			else if ( idx_i>0 && array_a[idx_i-1] > array_b[idx_j])
			{
				high = idx_i;
			}
			//满足条件
			else
			{
				float max_left = 0, min_right = 0;
				if (idx_i == 0)	max_left = array_b[idx_j - 1];
				else if (idx_j == 0)	max_left = array_a[idx_i - 1];
				else max_left = max(array_a[idx_i - 1], array_b[idx_j - 1]);

				if (idx_i == array_a.size()) min_right = array_b[idx_j];
				else if (idx_j == array_b.size()) min_right = array_a[idx_i];
				else min_right = min(array_b[idx_j], array_a[idx_i]);

				if (is_odd)
					return max_left;
				else
					return float((min_right + max_left)) / 2;

			}


		}

	}
};


void main()
{
	vector<int> nums_1 = { };
	vector<int> nums_2 = { 1};

	Solution S;
	cout << S.findMedianSortedArrays_optim(nums_1, nums_2) << endl;
	cout << 1;
}