/*
* 找到链表中倒数第K个节点的位置
* 
*/

#include <iostream>
#include<vector>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //由于元素n必定在链表中，不需要检查

        //创建指向头的指针
        ListNode* head_pre = new ListNode(0,head);
        ListNode* target_pre = head_pre;
        ListNode* post = head;
        
        //基于前后指针进行遍历
        for (int i =0 ; i < n ;i++)
        {
            post = post->next;
        }

        //找到元素
        while (post != nullptr)
        {
            post = post->next;
            target_pre = target_pre->next;
        }

        //删除元素
        target_pre->next = target_pre->next->next;

        return head_pre->next;
    }
};


// 创建链表
ListNode* create_list(vector<int> vc)
{
    ListNode* head = new ListNode(vc[0]);
    ListNode* temp_node_pre = head;
    for (int i= 1 ; i < vc.size();i++)
    {
        ListNode* temp_node = new ListNode(vc[i]);
        temp_node_pre->next = temp_node;
        temp_node_pre = temp_node;
    }
    return head;
}

//遍历链表
ostream& operator<<(ostream& output, ListNode* head)
{
    ListNode* node = head;
    while (node != nullptr)
    {
        output << node->val << "  ";
        node = node->next;
    }
    output << endl;
    return output;
}



void main()
{
    //创建链表
    vector<int> vc = { 1,2};

    ListNode* head = create_list(vc);

    cout << head;

    Solution S;

    ListNode* head_1 = S.removeNthFromEnd(head,2);

    cout << head_1;

}