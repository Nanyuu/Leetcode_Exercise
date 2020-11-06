#include<iostream>
#include<unordered_map>
#include<unordered_set>
using namespace std;

struct Deaultvalue {
    int i = -1;
};

class Solution {
public:
    // Use Vector map or set
    int lengthOfLongestSubstring(string s) {
            vector<int> check(256,-1);
            int s_start = 0;
            int s_end = 0;
            int longest = 0;
            while (s_end < s.size())
            {
                if (check[s[s_end]] != -1 )
                {
                    
                    if (check[s[s_end]] >= s_start)
                    {

                        if (check[s[s_end]] == s_start) {
                            s_start = s_start + 1;
                            check[s[s_end]] = s_end;
                        }
                        else {
                            s_start = check[s[s_end]] + 1;
                            check[s[s_end]] = s_end;
                        }
                    }
                    else
                    {
                        check[s[s_end]] = s_end;
                    }
                }
                else
                {
                    check[s[s_end]] = s_end;
                }
                longest = max(longest, s_end - s_start + 1);
                s_end = s_end + 1;

            }
            return longest;
    }


};



void main()
{
    Solution Sol;
    string S = "abcabcbb";
    cout << "最长子串长度为：" << Sol.lengthOfLongestSubstring(S);
}