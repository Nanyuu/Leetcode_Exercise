/*
* �ϲ�����������ɺ������
*/
#include <iostream>
#include <vector>
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        // ���µ�������ʵ��
        ListNode* node_1 = l1;
        ListNode* node_2 = l2;

        ListNode* head_l3 = new ListNode();
        ListNode* node_3 = head_l3;

        while (node_1 != nullptr && node_2 != nullptr)
        {
            if (node_1->val >= node_2->val)
            {
                ListNode* new_node_3 = new ListNode(node_2->val);
				node_3->next = new_node_3;
				node_3 = new_node_3;
                node_2 = node_2->next;
            }
            else
            {
                ListNode* new_node_3 = new ListNode(node_1->val);
                node_3->next = new_node_3;
                node_3 = new_node_3;
                node_1 = node_1->next;
            }
        }
        while (node_1 != nullptr)
        {
            ListNode* new_node_3 = new ListNode(node_1->val);
            node_3->next = new_node_3;
            node_3 = new_node_3;
            node_1 = node_1->next;
        }

		while (node_2 != nullptr)
		{
			ListNode* new_node_3 = new ListNode(node_2->val);
			node_3->next = new_node_3;
			node_3 = new_node_3;
			node_2 = node_2->next;
		}

        return head_l3->next;


    }

    ListNode* mergeTwoLists_1(ListNode* l1, ListNode* l2)
    {
        //����������Ľڵ�ʵ��
		ListNode* node_1 = l1;
		ListNode* node_2 = l2;

		ListNode* head_l3 = new ListNode();
		ListNode* node_3 = head_l3;

        while (node_1 != nullptr && node_2!=nullptr)
        {
            if (node_1->val <= node_2->val)
            {
                node_3->next = node_1;
                node_1 = node_1->next;
            }
            else
            {
                node_3->next = node_2;
                node_2 = node_2->next;
            }
            node_3 = node_3->next;
        }

        if (node_1 !=nullptr)
        {
            node_3->next = node_1;
        }
        if(node_2 != nullptr)
        {
            node_3->next = node_2;
        }

        return head_l3->next;
    }

    ListNode* mergeTwoLists_2(ListNode* l1, ListNode* l2)
    {
        //�õݹ���ʵ��

        //�������
        if (l2 == nullptr)   return l1;
        if (l1 == nullptr)   return l2;

        //ִ�еݹ�
        if (l1->val <= l2->val)
        {
            l1->next = mergeTwoLists_2(l1->next, l2);
            return l1;
        }
        else
        {
            l2->next = mergeTwoLists_2(l1, l2->next);
            return l2;
        }
    }
};

ListNode* Create_List(vector<int> vc)
{
    //��������
    if (vc.size() == 0)    return {};

    ListNode* head = new ListNode(vc[0]);
    ListNode* temp_node = head;
    for (int i = 1; i < vc.size(); i++)
    {
        ListNode* new_node = new ListNode(vc[i]);
        temp_node->next = new_node;
        temp_node = new_node;
    }

    return head;
}

//��������
ostream& operator << (ostream& output, ListNode* head)
{
    ListNode* node = head;
    while (node!=nullptr)
    {
        output << node->val<< "  ";
        node = node->next;
    }
    output << endl;

    return output;
}

void main()
{
    vector<int> list1 = {1,2,3 ,8 };
    vector<int> list2 = { 4,5,6,7 };
    ListNode* head_list1 = Create_List(list1);
    ListNode* head_list2 = Create_List(list2);

    Solution S;
    ListNode* head_list3 = S.mergeTwoLists_2(head_list1, head_list2);

    cout << "list3 = " << head_list3;
}