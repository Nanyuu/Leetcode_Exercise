/*
* Leetcode 17
* ģ���ֻ��Ź�������
* �� 2 = a/b/c ; 3 = d/e/f
* �������� "23"
* ����� ["ad","ae","af","bd","be","bf","cd","ce","cf"]
*/


#include <iostream>
#include<vector>
#include<unordered_map>
#include<string>

using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		unordered_map<int, string> num_to_string;

		char start_char = 'a';
		string t;
		//�����Ӧ��ϵ
		for (int i = 2; i <= 9; i++)
		{
			if (i==7 || i==9)
			{
				char temp_char[5] = { start_char++, start_char++, start_char++, start_char++ };
				t = temp_char;
			}
			else
			{
				char temp_char[4] = { start_char++,start_char++,start_char++};
				t = temp_char;
			}
			num_to_string.insert({ i,t });
		}

		// ���������
		vector<string> output;
		for (int digit_id=0; digit_id<digits.size(); digit_id++)
		{
			int digit_num = digits[digit_id] - '0';
			if (output.size() == 0)
			{
				//���������Ϊ��ʱ
				for (int s_id =0 ; s_id < num_to_string[digit_num].size() ; s_id++)
				{
					output.push_back(string({ num_to_string[digit_num][s_id] }));
				}
			}
			else
			{
				//��������鲻Ϊ��ʱ

				int pre_output_size = output.size();
				for (int pre_output_id = 0; pre_output_id < pre_output_size; pre_output_id++)
				{
					//�õ���ǰ�ַ���
					string temp_string = output.front(); 

					for (int s_id = 0; s_id < num_to_string[digit_num].size(); s_id++)
					{
						output.push_back(temp_string+num_to_string[digit_num][s_id]);
					}

					//ɾ����ǰ���Ԫ��
					output.erase(output.begin());

				}
			}
		}


		return output;




	}
};

ostream& operator <<(ostream& output, vector<string> st)
{
	for (int i = 0; i < st.size(); i++)
	{
		output << st[i] << "  ";
	}
	output << endl;

	return output;
}


void main()
{
	std::string st("2345");
	Solution S;
	cout << S.letterCombinations(st);
	cout << endl;
}
