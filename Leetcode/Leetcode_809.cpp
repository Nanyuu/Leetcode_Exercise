#include<iostream>
#include<vector>
#include<string>
using namespace std;
#define mian main;


/*
Leetcode 809 , �������ַ�����չ, �����������չ��Ŀ�괮,��+1������Ϊ0
���� heeello ����hello��չ���ã�
    ���޷���helo��չ�õ�����Ϊhelo��l�޷���չ��ll����չ����С��3

*/
class Solution {
public:
    int expressiveWords(string S, vector<string>& words) {
        int word_num = words.size();
        int total_num = 0;
        for (int word_id = 0; word_id < words.size(); word_id++)
        {
            string temp_word = words[word_id];
            int temp_word_id = 0;
            if (S.length() < temp_word.length())
            {
                continue;
            }
            for (int j = 0; j <= S.length(); j++)
            {
                if (j == S.length())
                {
                    total_num = total_num + 1;
                    
                }
                else if (S[j] == temp_word[temp_word_id])
                {
                        temp_word_id++;     
                        continue;
                }
                else
                {
                    //��Ҫ��չ
                    if (S[j - 1] == S[j] && S[j] == S[j + 1])
                    {
                        j = j + 1;
                        continue;
                    }
                    else if (j <= 1)
                    {
                        break;
                    }
                    else if (S[j - 1] == S[j] && S[j] == S[j - 2])
                    {
                        continue;
                    }
                    else
                    {
                        break;
                    }
                }
            }
        }
        return total_num;


    }
};

void main()
{
    vector<string> words = {  "qjuvi"};
    string a = "qqjjjjjjuuuuuvvvviiii";
    
       

    Solution sol;
    int output = sol.expressiveWords(a, words);

    cout << "�ַ���ƥ������:" <<output<< endl;



}