/*
* �����ӣ�ÿ������1~2�ף����ж���������
*/

#include <iostream>
using namespace std;

class Solution {
public:
	int climbStairs(int n) {
		//dp
		int prepre = 1;
		int pre = 2;
		int temp = 0;
		if (n == 1)
		{
			return prepre;
		}
		if (n == 2)
		{
			return pre;
		}
		for (int i = 3; i <= n; i++)
		{
			temp = pre + prepre;
			prepre = pre;
			pre = temp;
		}
		return temp;
	}
};

void main()
{
	int n = 4;
	Solution S;
	cout<<S.climbStairs(n);
}