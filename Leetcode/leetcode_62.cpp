/*
* �����ֲ�ͬ��·��
* һ�������˴������ϵ������µĿ���·��
* ���ƣ�ֻ�����һ�������
*/


#include<vector>
#include<iostream>

using namespace std;

class Solution {
public:
	int uniquePaths(int m, int n) {
		int temp_i = 0, temp_j = 0;
		int path_num = 0;
		recursion_path(path_num, temp_i, temp_j, m, n);
		return path_num;

	}

	void recursion_path(int& path_num, int i, int j, int m,int n)
	{
		//recursion
		//�ݹ鷽���������⣬��μ�����ͬһ�����
		//�������
		if (i == m-1 && j == n-1)
		{
			path_num++;
			return;
		}
		if (i< m-1)
		{
			recursion_path(path_num, i + 1, j, m, n);
		}
		if(j< n-1)
		{
			recursion_path(path_num, i, j+1, m, n);
		}
		return;

	}

	int uniquePaths_1(int m, int n) {
		// DP����
		//��ʼ������
		int **path_num = new int*[m];
		for (int i = 0; i < m; i++)
		{
			path_num[i] = new int[n]();
		}

		int temp_i = 0, temp_j = 0;

		while (path_num[m-1][n-1] ==0)
		{
			//������
			for (int i = temp_i; i< m;i++)
			{
				int up = 1, left = 0;
				if (temp_j != 0)
				{
					left = path_num[i][temp_j - 1] ;
				}
				if (i !=0)
				{
					up = path_num[i - 1][temp_j] ;
				}
				path_num[i][temp_j] = left + up ;
			}


			//������
			for (int j = temp_j; j < n; j++)
			{
				int up = 1, left = 0;
				if (temp_j != 0)
				{
					left = path_num[temp_i-1][j] ;
				}
				if (j != 0)
				{
					up = path_num[temp_i][j-1] ;
				}
				path_num[temp_i][j] = up + left;
			}

			//����I��J
			if (temp_i != m - 1)
			{
				temp_i++;
			}
			if (temp_j != n - 1)
			{
				temp_j++;
			}

		}


		return path_num[m-1][n-1];

	}

};

void main()
{
	int m = 1, n = 1;
	Solution S;
	cout<<"·������Ϊ"<<S.uniquePaths_1(m, n);
}