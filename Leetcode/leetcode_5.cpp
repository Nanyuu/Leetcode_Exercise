#include <iostream>
#include<stack>

using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int max_length = 0;
		string sub_string = s.substr(0, 1);

		short sub_length =0;
		short left_id = 0;
		short right_id = 0;
		bool flag = 0;

		for (int temp = 0; temp < s.size(); temp++)
		{
			//遍历每一个node
			sub_length = 1;
			left_id = temp - sub_length;
			right_id = temp + sub_length;
			flag = 0;
			while (true)
			{
				if (right_id >= s.size())
					break;
				else if (flag != 1 && s[right_id] == s[temp])
				{
					//右值相等
					if (sub_length > max_length)
					{
						max_length = sub_length;
						sub_string = s.substr(left_id+1, right_id - left_id );
					}
					sub_length++;
					right_id++;
				}
				else if (left_id < 0)
					break;
				else if (s[left_id] == s[right_id])
				{
					flag = 1;
					sub_length++;
					if (sub_length > max_length)
					{
						
						max_length = sub_length;
						sub_string = s.substr(left_id, right_id - left_id + 1);
					}
					sub_length++;
					left_id--;
					right_id++;
				}
				else
				{
					break;
				}
			}
		}

		return sub_string;
		


	}
};

void main()
{
	string s = "babcbcab";
	Solution S;
	cout<<"最长子串为"<<S.longestPalindrome(s);
}

