/*
* ����һ�����󣬴�Ȩ�أ�������ϵ����µ���̾���
*/

#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	int minPathSum(vector<vector<int>>& grid) {
		int grid_m = grid.size();
		int grid_n = grid[0].size();
		//��ʼ����ά����
		vector<vector <int>> grid_min_length(grid_m, vector<int>(grid_n, 0));


		for (int i = 0; i < grid_m; i++)
		{
			for (int j = 0; j < grid_n; j++)
			{
				if (i == 0 && j == 0)
				{
					grid_min_length[i][j] = grid[i][j];
					continue;
				}

				int left = 9999, top = 9999;
				if (j != 0)
				{
					left = grid_min_length[i][j - 1];
				}
				if (i != 0)
				{
					top = grid_min_length[i - 1][j];
				}

				grid_min_length[i][j] = min(left,top) + grid[i][j];
			}
		}
		return grid_min_length[grid_m-1][grid_n-1];

	}
};

void main()
{
	vector<vector<int>> grid = { {0,3,1},{1,5,1},{4,2,1} };
	Solution S;
	cout<<"Ȩֵ"<<S.minPathSum(grid);
}