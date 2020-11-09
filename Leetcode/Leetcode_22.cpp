/*
* �������� �� ������е��������
* 
* ������ 3 
* ����� "((()))","(()())","(())()","()(())","()()()"
*/
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		//�����ⷨ
		vector<string> output = {};

		//�ܹ����n*2������
		for (int i=0;i<n*2; i++)
		{
			if (output.size() == 0)
			{
				output.push_back("(");
				continue;
			}

			int temp_size = output.size();

			//�����ַ���
			for (int j = 0; j < temp_size; j++)
			{
				int statistic_left = 0;
				int statistic_right = 0;
				for (int k = 0; k < output[0].size(); k++)
				{
					if (output[0][k] == '(') statistic_left++;
					else
					{
						statistic_right++;
					}
				}
				if (statistic_left < n)
				{
					output.push_back(output[0] + '(');
				}
				if (statistic_left > statistic_right)
				{
					output.push_back(output[0] + ')');
				}
				

				output.erase(output.begin()); //ɾ���ڵ�
			}
		}
		return output;
	}

	vector<string> generateParenthesis_1(int i)
	{
		//ʹ�õݹ������
		vector<string> res = {};
		recursive_step(res, "", i, i);

		return res;

	}

	void recursive_step(vector<string> &v, string t, int left_n, int right_n)
	{
		if (left_n ==0 && right_n==0)
		{
			v.push_back(t); //����Ԫ��
		}
		if (left_n != 0)	recursive_step(v, t + '(', left_n - 1, right_n);
		if (right_n > left_n)	recursive_step(v, t + ')', left_n, right_n - 1);


	}
};

ostream& operator <<(ostream& output, vector<string> sc)
{
	for (int i = 0; i < sc.size(); i++)
	{
		output << sc[i] << "  ";
	}
	output << endl;
	return output;
}


void main()
{
	Solution S;
	cout<<S.generateParenthesis_1(3);
	cout << endl;
}