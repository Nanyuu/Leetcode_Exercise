
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// leetcode 1201 
// 找到第n个能被a/b/c整除的数


//找到最小公约数
unsigned int gcd(unsigned int n1, unsigned int n2) {
	return (n2 == 0) ? n1 : gcd(n2, n1 % n2);
}

class Solution {
public:
	int nthUglyNumber(int n, int A, int B, int C) {
		//暴力解法， a/b/c分别乘n后记录数组
		//创建三个数组
		long a = long(A);
		long b = long(B);
		long c = long(C);
		int ai = 1;
		int bi = 1;
		int ci = 1;

		int next = min(ci * c, min(ai * a, bi * b));
		int i = 0;
		while (i < n)
		{
			next = min(ci * c, min(ai * a, bi * b));

			if (next == ci * c) ci++;
			if (next == ai * a) ai++;
			if (next == bi * b) bi++;
			i = i + 1;
		}
		return next;
	}

	// 用二分法搜索解决
	int uglyNumber_optim(int n, int A, int B, int C)
	{

		long a = int(A);
		long b = int(B);
		long c = int(C);
		
		//找到最小公倍数
		long ab = a * b / gcd(a, b);
		long ac = a * c / gcd(a, c);
		long bc = b * c / gcd(b, c);
		long abc = a * bc / gcd(a, bc);

		//二分查找
		int low = 1;
		long long high = 2e10;

		while (low < high)
		{
			long long mid = low + (high - low) / 2;
			long long temp = mid / a + mid / b + mid / c - mid / ab - mid / ac + mid / abc;
			if (temp < n)
			{
				low = mid + 1;
			}
			else
			{
				high = mid;
			}
		}
		return low;


	}

};


void main()
{
	Solution Sol;
	int a, b, c, n;
	while (1)
	{
		cout << "请输入 a,b,c,n" << endl;
		cin >>n>>a >> b >> c ;

		long next = Sol.uglyNumber_optim(n, a, b, c);

		cout << "找到的数为 " << next << endl;
	}


	
}