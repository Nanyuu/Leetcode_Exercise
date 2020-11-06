#include<vector>
#include<math.h>
#include<iostream>
using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int mid = sqrt(area);
        while (area % mid )
        {
            mid = mid - 1;
        }
        return vector<int>{mid, area/mid};
    }

    vector<int> constructRectangle_1(int area) {
        int mid = sqrt(area);
        for (int temp = 0; temp < mid; temp++)
        {
            if (!(area % (mid - temp)))
            {
                return vector<int>{area/ (mid - temp), mid - temp};
            }
        }
        return vector<int>{area, 1};
    }
};

void main()
{
    Solution sol;
    while (1)
    {
        int a;
        cout << "请输入数" << endl;
        cin >> a;
        vector<int>b = sol.constructRectangle_1(a);
        cout << "计算得到的B值为" << b[0] << "," << b[1] << endl;
    }
}