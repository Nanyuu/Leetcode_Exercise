/*
* Leetcode 77 Combinations
* 组合， 给定两个数 n和k
* 求 在[1,n]范围外的所有组合
*/


#include<vector>
#include<iostream>
#include"ostream_overload.h"
using namespace std;

class Solution {
public:
	vector<vector<int>> combine(int n, int k) {
		vector<vector<int>> res;
		vector<int> temp_vec;
		for (int i = 1; i <= n - k + 1; i++)
		{
			temp_vec.push_back(i);
			inner_combine(res, n, k, temp_vec);
			temp_vec.pop_back();

		}
		return res;
	}
	void inner_combine(vector<vector<int>> &res,const int &n, const int &k, vector<int> &temp_vec)
	{
		if (temp_vec.size() == k)
		{
			res.push_back(temp_vec);
			return;
		}
		for (int i = temp_vec.back()+1; i<=n;i++)
		{
			temp_vec.push_back(i);
			inner_combine(res, n, k, temp_vec);
			temp_vec.pop_back();
		}
		return;
	}
};

int main()
{
	int n = 4;
	int k = 2;
	Solution S;
	vector<vector<int>> res;
	res = S.combine(n, k);
	cout << res;
}