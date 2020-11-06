
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

// leetcode 1201 
// �ҵ���n���ܱ�a/b/c��������


//�ҵ���С��Լ��
unsigned int gcd(unsigned int n1, unsigned int n2) {
	return (n2 == 0) ? n1 : gcd(n2, n1 % n2);
}

class Solution {
public:
	int nthUglyNumber(int n, int A, int B, int C) {
		//�����ⷨ�� a/b/c�ֱ��n���¼����
		//������������
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

	// �ö��ַ��������
	int uglyNumber_optim(int n, int A, int B, int C)
	{

		long a = int(A);
		long b = int(B);
		long c = int(C);
		
		//�ҵ���С������
		long ab = a * b / gcd(a, b);
		long ac = a * c / gcd(a, c);
		long bc = b * c / gcd(b, c);
		long abc = a * bc / gcd(a, bc);

		//���ֲ���
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
		cout << "������ a,b,c,n" << endl;
		cin >>n>>a >> b >> c ;

		long next = Sol.uglyNumber_optim(n, a, b, c);

		cout << "�ҵ�����Ϊ " << next << endl;
	}


	
}