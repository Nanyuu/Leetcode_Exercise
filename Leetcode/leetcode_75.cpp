/*
* 给定一个含0,1,2的数组
* 要求排序
*/

#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
	void sortColors(vector<int>& nums) {
		map<int, int> map_to_num;
		for (int i = 0 ; i<nums.size();i++)
		{
			if (map_to_num.count(nums[i])!=0)
			{
				map_to_num[nums[i]]++;
			}
			else
			{
				map_to_num[nums[i]] = 1;
			}
		}
		vector<int> nums_1;
		map<int, int>::iterator iter;
		for (iter = map_to_num.begin();iter !=map_to_num.end();iter++)
		{
			for (int time = 0; time < iter->second; time++)
			{
				nums_1.push_back(iter->first);
			}

		}
		nums = nums_1;
	}
};

ostream& operator <<(ostream& output, vector<int> vec)
{
	for (int i = 0 ;i <vec.size(); i++)
	{
		cout << vec[i]<<"  ";
	}
	return output;
}

void main()
{
	vector<int> nums = {  };
	cout << nums << endl;
	Solution S;
	S.sortColors(nums);
	cout << nums << endl;

}