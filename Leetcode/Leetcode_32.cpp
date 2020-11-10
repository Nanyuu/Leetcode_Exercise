/*
* �ҳ����pattern�� '(' �� ')'
* 
* ��
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
				//������ʱֱ���ж�Ϊ�ɼ���
				left++;
				temp_lengh++;
			}
			else if (s[i] == ')')
			{
				//������ʱ��Ҫ�ж������Ÿ���
				if (left > right)
				{
					//����ֱ�����
					right++;
					temp_lengh++;
				}
				else
				{
					//�����Ϲ���
					max_length = max(max_length, temp_lengh); //���ֵ����
					left = 0;
					right = 0;
					temp_lengh = 0;
				}
			}
		}

		if (temp_lengh < max_length)
		{
			//���temp_length С��max_length ֱ�����max_length
			return max_length;
		}
		else
		{
			//�������ַ�������ջ��������

			stack<char> st;

		}
		
		// ûд��������
		return 0;


	}

	int longestValidParentheses_1(string s) {
		//��DP����
		//�������е���󳤶���������
		vector<int> length = { 0 };
		int max_length = 0;

		for (int s_i= 1;s_i <s.size();s_i++)
		{
			if (s[s_i] == '(')
			{
				//�����ţ���󳤶�Ϊ0
				length.push_back(0);
			}
			else
			{
				if (s[s_i - 1] == '(')
				{
					if (s_i - 2 >= 0)
					{
						length.push_back( length[s_i - 2] + 2); //������ƥ�䣬�����i-2λ���ƶϳ���
					}
					else
					{
						length.push_back(2);	//�������̫С������2
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
		//��ջ����
		stack<int> st;
		st.push(-1);
		int max_length = 0;
		
		for (int i = 0; i < s.size(); i++)
		{
			//��ȡ��ǰ��top
			int top = st.top();

			if (top != -1 && s[i] == ')' && s[top] == '(')
			{
				st.pop();	//��ջ
				//��ζ�ſ������ӳ���
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