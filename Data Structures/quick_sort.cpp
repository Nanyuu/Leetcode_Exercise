#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

ostream &operator<<(ostream &output,vector<int> lists)
{
	for (int i = 0; i < lists.size(); i++)
	{
		output << lists[i] << endl;
	}
	return output;

}

int inner_quick_sort(vector<int>& lists, int low, int high)
{
	//找到mid并进行排序
	int mid = low + (high - low) / 2;
	swap(lists[mid], lists[high]);
	int start = low - 1;
	for (int i = low; i < high; i++)
	{
		if (lists[i] < lists[high])
		{
			start++;
			if (start != low)
			{
				swap(lists[i], lists[start]);
			}
		}
	}
	start++;
	swap(lists[start], lists[high]);
	return start;
}

void qucik_sort(vector<int>& lists, int low, int high)
{
	if (low == high)
	{
		return; //
	}
	
	//找到二分节点,并根据low high排序已有节点
	int mid = inner_quick_sort(lists, low, high);
	if (mid < high)
		qucik_sort(lists, mid + 1, high);
	if (mid > low)
		qucik_sort(lists, low, mid - 1);
}


void main()
{
	vector<int> lists{1,4,3,5,2,7,6,10};
	//lists.push_back(5);
	qucik_sort(lists, 0, lists.size() - 1);
	cout << lists<< endl;
	
}