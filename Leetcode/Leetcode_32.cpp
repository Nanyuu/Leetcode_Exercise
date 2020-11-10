/*
* 找出最长的pattern， '(' 和 ')'
* 
* 如
	")()"		-> 2
*	"()())"		->4
*/
#include<iostream>
#include<stack>
#include<vector>

using namespace std;


class Solution {
public:
	int longestValidParentheses(string s) {

		int max_length = 0;
		int left = 0;
		int right = 0;
		int temp_lengh = 0;
		for (int i=0;i<s.size();i++)
		{
			if (s[i] == '(')
			{
				//左括号时直接判定为可加入
				left++;
				temp_lengh++;
			}
			else if (s[i] == ')')
			{
				//右括号时需要判定左括号个数
				if (left > right)
				{
					//可以直接添加
					right++;
					temp_lengh++;
				}
				else
				{
					//不符合规则
					max_length = max(max_length, temp_lengh); //最大值保存
					left = 0;
					right = 0;
					temp_lengh = 0;
				}
			}
		}

		if (temp_lengh < max_length)
		{
			//如果temp_length 小于max_length 直接输出max_length
			return max_length;
		}
		else
		{
			//对已有字符串进行栈操作计数

			stack<char> st;

		}
		
		// 没写出来（？
		return 0;


	}

	int longestValidParentheses_1(string s) {
		//用DP来解
		//根据已有的最大长度来解问题
		vector<int> length = { 0 };
		int max_length = 0;

		for (int s_i= 1;s_i <s.size();s_i++)
		{
			if (s[s_i] == '(')
			{
				//左括号，最大长度为0
				length.push_back(0);
			}
			else
			{
				if (s[s_i - 1] == '(')
				{
					if (s_i - 2 >= 0)
					{
						length.push_back( length[s_i - 2] + 2); //左括号匹配，则根据i-2位来推断长度
					}
					else
					{
						length.push_back(2);	//如果长度太小，则置2
					}
				}
				else if (s[s_i-1] == ')')
				{
					if ((s_i - length[s_i - 1] - 1)>=0 && s[s_i - length[s_i - 1] - 1] == '(')
					{
						if ((s_i - length[s_i - 1] - 2) >= 0)
						{
							length.push_back(length[s_i - 1] + length[s_i - length[s_i - 1] - 2] + 2);
						}
						else
						{
							length.push_back(length[s_i - 1]  + 2);
						}

					}
					else
					{
						length.push_back(0);
					}
				}

			}
			max_length = max(max_length, length[s_i]);
		}

		return max_length;


	}

	int longestValidParentheses_2(string s) {
		//用栈来解
		stack<int> st;
		st.push(-1);
		int max_length = 0;
		
		for (int i = 0; i < s.size(); i++)
		{
			//提取当前的top
			int top = st.top();

			if (top != -1 && s[i] == ')' && s[top] == '(')
			{
				st.pop();	//出栈
				//意味着可以增加长度
				max_length = max(max_length, i - st.top());
				
			}
			else
			{
				st.push(i);
			}
		}
		return max_length;
	}

};


void main()
{
	string str = "(()())";
	Solution S;
	cout<<S.longestValidParentheses_1(str);
}