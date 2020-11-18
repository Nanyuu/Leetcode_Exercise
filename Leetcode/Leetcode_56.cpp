/*
* 给定一组组范围间距
* 融合这些间距
*/

#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		//根据第一个元素进行排序
		map<int, int> sorted_map;
		vector<vector<int>> output;
		for (int i = 0 ; i<intervals.size() ; i++)
		{
			if (sorted_map.find(intervals[i][0]) == sorted_map.end())
			{
				sorted_map.insert({ intervals[i][0],intervals[i][1] });
			}
			else
			{
				sorted_map[intervals[i][0]] = max(sorted_map[intervals[i][0]], intervals[i][1]);
			}
			
		}
		map<int, int>::iterator iter;
		for (iter = sorted_map.begin();iter != sorted_map.end();)
		{
			int temp_start = iter->first;
			int temp_end = iter->second;
			iter++;
			while ( iter!=sorted_map.end()&&(iter)->first <= temp_end)
			{
				temp_end = max(iter->second,temp_end);
				iter++;
			}
			output.push_back({ temp_start,temp_end });

		}
		return output;

	}

	vector<vector<int>> merge_1(vector<vector<int>>& intervals)
	{
		//对vector进行排序
		sort(intervals.begin(), intervals.end(), [](vector<int> a, vector<int> b)
			{
				return a[0] < b[0];	//lambda,自定义排序
			});
		
		vector<vector<int>> output;
		for (int i=0;i<intervals.size();)
		{
			int temp_left = intervals[i][0];
			int temp_right = intervals[i][1];
			while (i<intervals.size()-1 && intervals[i+1][0] <= temp_right)
			{
				temp_right = max(intervals[i + 1][1], temp_right);
				i++;
			}
			i++;
			output.push_back({ temp_left,temp_right });
		}

		return output;


	}
};

ostream& operator <<(ostream& output, vector<vector<int>> vec)
{
	for (int i = 0; i < vec.size(); i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			output << vec[i][j] << "  ";
		}
		output << endl;
	}
	return output;
}

void main()
{
	//vector<vector<int>> input = { {1,3},{1,5},{10,12},{6,8} };
	vector<vector<int>> input = {  };
	Solution S;
	cout<<S.merge_1(input)<<endl;
	cout << endl;

	//测试map的功能
	//map<int, int> test_map;
	//test_map.insert({ 1,2 });


}