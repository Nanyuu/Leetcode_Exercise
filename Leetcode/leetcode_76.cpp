/*
* 给定一个长字符串和一个短字符串
* 求在长字符串中，一个短字符串内各个字符全都出现过得区间
* Input: s = "ADOBECODEBANC", t = "ABC"
* Output: "BANC"
*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include<algorithm>

using namespace std;


class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char, int> num_control;
		unordered_map<char, int> base_control; //保证t中的数量
		for (int i = 0 ;i <t.size();i++)
		{
			num_control.insert({ t[i], 0 });
			if (base_control.count(t[i]) == 0)
			{
				base_control.insert({ t[i], 1 });
			}
			else
				base_control[t[i]]++;
		}

		for (int i = 0 ; i<s.size();i++)
		{
			if (num_control.count(s[i]) != 0)
			{
				num_control[s[i]]++;
			}
		}

		unordered_map<char, int>::iterator iter;

		for (iter = num_control.begin(); iter!=num_control.end();iter++)
		{
			char temp_char = iter->first;
			if (num_control[temp_char] < base_control[temp_char])
			{
				return "";
			}
		}

		//从头开始遍历
		int start = 0;
		int end = s.length() - 1;
		int max_length = s.length();
		int final_start = 0;
		while (start <= end)
		{
			char temp_char = s[start];
			if (base_control.count(temp_char)==0)
			{
				start++;
				continue;
			}
			else
			{
				if (num_control[temp_char] == base_control[temp_char])
				{
					int temp_length = get_length(num_control, base_control, s.substr(start), t);
					if (temp_length < max_length)
					{
						final_start = start;
						max_length = temp_length;
					}
					break;
				}
				else
				{
					
					int temp_length = get_length(num_control, base_control, s.substr(start), t);
					if (temp_length < max_length)
					{
						final_start = start;
						max_length = temp_length;
					}
					num_control[temp_char]--;
					start++;
				}
			}

		}



		return s.substr(final_start, max_length + 1);

	}

	int get_length(unordered_map<char, int> num_control, unordered_map<char, int>& base_control, string s, string t)
	{
		int start = 0;
		int end = s.size() - 1;

		while (start <= end)
		{
			//让end往前搜索
			char temp_char = s[end];
			if (num_control.count(temp_char) == 0)
			{
				end--;
			}
			else
			{
				if (num_control[temp_char] == base_control[temp_char])
					break;
				else
				{
					num_control[temp_char]--;
					end--;
				}
			}
		}
		return end - start;

	}


	string find_start_end(unordered_map<char, int> num_control, unordered_map<char, int> base_control, string s, string t)
	{
		int start = 0;
		int end = s.size() - 1;

		while (start < end)
		{
			//让start往后搜索
			char temp_char = s[start];
			if (num_control.count(temp_char) == 0)
			{
				start++;
			}
			else 
			{
				if (num_control[temp_char] == base_control[temp_char])
					break;
				else
				{
					num_control[temp_char]--;
					start++;
				}
			}
		}
		while (start <end)
		{
			//让end往前搜索
			char temp_char = s[end];
			if (num_control.count(temp_char) == 0)
			{
				end--;
			}
			else
			{
				if (num_control[temp_char] == base_control[temp_char])
					break;
				else
				{
					num_control[temp_char]--;
					end--;
				}
			}
		}
		return s.substr(start, end - start + 1);
	}
};

void main()
{
	string s = "DOBECODEBANC";
	string t = "ABC";
	Solution S;
	cout << S.minWindow(s, t);
}