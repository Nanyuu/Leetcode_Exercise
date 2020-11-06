/*
* �ҵ������е�����K���ڵ��λ��
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
        //����Ԫ��n�ض��������У�����Ҫ���

        //����ָ��ͷ��ָ��
        ListNode* head_pre = new ListNode(0,head);
        ListNode* target_pre = head_pre;
        ListNode* post = head;
        
        //����ǰ��ָ����б���
        for (int i =0 ; i < n ;i++)
        {
            post = post->next;
        }

        //�ҵ�Ԫ��
        while (post != nullptr)
        {
            post = post->next;
            target_pre = target_pre->next;
        }

        //ɾ��Ԫ��
        target_pre->next = target_pre->next->next;

        return head_pre->next;
    }
};


// ��������
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

//��������
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
    //��������
    vector<int> vc = { 1,2};

    ListNode* head = create_list(vc);

    cout << head;

    Solution S;

    ListNode* head_1 = S.removeNthFromEnd(head,2);

    cout << head_1;

}