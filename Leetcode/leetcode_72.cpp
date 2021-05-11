/*
* 给定两个string字符串，
* 输出将一个字符串转变为另一个字符所需要的步数
* 1、插入一个字符
* 2、替换一个字符
* 3、删除一个字符
*/

#include<iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int minDistance(string word1, string word2) {
		//初始化记录数组
		vector<vector<int>> dp(word1.size()+1, vector<int>(word2.size()+1, 0));

		for (int i = 0 ; i<= word1.size();i++)
			dp[i][0] = i;

		for (int j = 0; j <= word2.size(); j++)
			dp[0][j] = j;

		for (int i =1 ; i<=word1.size();i++)
		{
			for (int j = 1; j <= word2.size(); j++)
			{
				//情况1：如果i和j相等
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

