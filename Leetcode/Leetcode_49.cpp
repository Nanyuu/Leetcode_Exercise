/*
* 查找在数组中的duplicate
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		unordered_map<string,int> check_map ;
		int output_id = 0;
		vector<vector<string>> output = {};
		for (int i =0 ;i<strs.size();i++)
		{
			//排序strs
			string temp_string = strs[i];
			sort(temp_string.begin(), temp_string.end());
			if (check_map.count(temp_string)==0)
			{
				//不含指定key
				check_map.insert({ temp_string, output_id });
				output_id++;
				output.push_back({ strs[i] });
			}
			else
			{
				int idx = check_map[temp_string];
				output[idx].push_back(strs[i]);
			}
		}
		return output;

	}
};

ostream& operator <<(ostream& output, vector<vector<string>> vec)
{
	for (int i = 0; i<vec.size();i++)
	{
		for (int j = 0; j < vec[i].size(); j++)
		{
			output << vec[i][j]<<"  ";
		}
		output << endl;
	}
	return output;
}


void main()
{
	vector<string> input = { "eat","tea","tan","ate","nat","bat" };
	Solution S;
	vector<vector<string>> output;
	output = S.groupAnagrams(input);

	cout << output;


}