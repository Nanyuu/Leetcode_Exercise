/*
* ������˳ʱ����ת90��
* Ҫ�󣺲�������������
* 
*/

#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		//��Ȧ������
		//��Ҫ�����Ȧ��

		for (int lp_circle = 0; lp_circle<matrix.size()/2 ; lp_circle++)
		{
			//����i,j��ʼֵ
			int i_1 = lp_circle, j_1 = lp_circle;
			int inner_size = matrix.size() - lp_circle * 2;

			vector<int> temp_mat = {};
			//�������
			for (;j_1 <matrix.size()-lp_circle - 1;j_1++)
			{
				temp_mat.push_back(matrix[i_1][j_1]);
			}

			int mat_i = 0;
			while (1)
			{
				if (i_1 == lp_circle)
				{
					if (j_1 == lp_circle)
					{
						for (; j_1 < matrix.size() - lp_circle - 1; j_1++)
						{

							swap(temp_mat[mat_i], matrix[i_1][j_1]);
							mat_i++;
						}
						break;
					}
					else
					{
						for (; i_1 < matrix.size() - lp_circle - 1; i_1++)
						{

							swap(temp_mat[mat_i], matrix[i_1][j_1]);
							mat_i++;
						}
					}
				}
				else
				{
					if (j_1 == lp_circle)
					{
						for (; i_1> lp_circle ; i_1--)
						{

							swap(temp_mat[mat_i], matrix[i_1][j_1]);
							mat_i++;
						}					}
					else
					{
						for (; j_1 > lp_circle ; j_1--)
						{

							swap(temp_mat[mat_i], matrix[i_1][j_1]);
							mat_i++;
						}

					}
				}
				mat_i = 0;
			}

		}
	}

	void rotate_simple(vector<vector<int>>& matrix)
	{
		//�뷽��1һ����˼�룬���̴�����
		int mat_size = matrix.size();
		int a = 0;
		int b = mat_size - 1;

		while (a<b)
		{
			for (int i = 0; i < (b - a); i++)
			{
				swap(matrix[a][a+i], matrix[a+i][ b]);
				swap(matrix[a][ a + i], matrix[b][ b - i]);
				swap(matrix[a][ a + i], matrix[b - i][ a]);
			}
			a++;
			b--;
		}
	}

	//ͼ��ת�ľ���ⷨ
	/*
	* ˳ʱ�뷭ת�������·�ת->Ȼ���ضԽ��߽���Ԫ��
	* ��ʱ�뷭ת�������ҷ�ת->Ȼ���ضԽ��߽���Ԫ��
	*/
	void clock_rotate(vector<vector<int>> &matrix)
	{
		//���·�ת
		reverse(matrix.begin(), matrix.end());
		//�Խ���Ԫ�ؽ���
		for (int a = 0; a<matrix.size();a++)
		{
			for (int b = a+1; b < matrix.size(); b++)
			{
				swap(matrix[a][b], matrix[b][a]);
			}
		}
	}
};

ostream& operator << (ostream & output, vector<vector<int>> input)
{
	for (int i = 0; i < input.size(); i++)
	{
		for (int j = 0; j < input[i].size(); j++)
		{
			output << input[i][j] << "  ";
		}
		output << endl;
	}
	return output;


}

void main()
{
	//vector<vector<int>> input_mat = { {1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
	vector<vector<int>> input_mat = { {5, 1, 9, 11} , {2, 4, 8, 10},{13, 3, 6, 7},{15, 14, 12, 16} };
	//vector<vector<int>> input_mat = { {1,2},{3,4} };


	Solution S;
	S.clock_rotate(input_mat);

	cout << input_mat;
	cout << endl;


}



