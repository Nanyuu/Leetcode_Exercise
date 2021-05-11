/*
* ��������string�ַ�����
* �����һ���ַ���ת��Ϊ��һ���ַ�����Ҫ�Ĳ���
* 1������һ���ַ�
* 2���滻һ���ַ�
* 3��ɾ��һ���ַ�
*/

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		//��ʼ����¼����
		vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));

		for (int i = 0 ; i<= word1.size();i++)
			dp[i][0] = i;

		for (int j = 0; j <= word2.size(); j++)
			dp[0][j] = j;

		for (int i =1 ; i<=word1.size();i++)
		{
			for (int j = 1; j <= word2.size(); j++)
			{
				//���1�����i��j���
				if (word1[i-1]==word2[j-1])
				{
					dp[i][j] = dp[i - 1][j - 1];
				}
				else
				{
					dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i - 1][j - 1]), dp[i][j - 1]);
				}
			}
		}
		return dp[word1.size()][word2.size()];


	}
};

void main()
{
	string word1 = "";
	string word2 = "";
	Solution S;
	cout << S.minDistance(word1, word2) << endl;
}

