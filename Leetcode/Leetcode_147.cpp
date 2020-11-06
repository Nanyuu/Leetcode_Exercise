#include <iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		// ʵ��һ����������
		if (head->next ==nullptr)
		{
			return head;
		}


		ListNode* target_node = head;
		ListNode* search_node = head;
		while (target_node->next != nullptr)
		{
			int pre_val = target_node->val;
			target_node = target_node->next;

			if (target_node->val >= pre_val)
			{
				continue; //��λ�ò�Ӧ�ı�ʱ
			}


			//����λ��
			while (search_node->val <= target_node->val)
			{
				search_node = search_node->next;
			}

			//��¼λ��
			ListNode* target_position = search_node;
			int temp_pre = search_node->val;
			while (search_node->next->val != target_node->val)
			{
				int temp_val = search_node->next->val;
				search_node->next->val = temp_pre;
				search_node = search_node->next;
				temp_pre = temp_val;
			}
			target_position->val = target_node->val;
			search_node->next->val = temp_pre;
			
			search_node = head;
		}
		return head;
		

	}

	ListNode* insertionSortList_link(ListNode* head) {
		//������������ʵ��һ����������
		if (head->next == nullptr)
		{
			return head;
		}
		//����һ��ָ��ͷ��ָ��
		ListNode* pre_head = new ListNode(0, head);

		ListNode* target_node_pre = pre_head->next;
		ListNode* search_node_pre = pre_head;
		while (target_node_pre->next != nullptr)
		{
			

			if (target_node_pre->val < target_node_pre->next->val)
			{
				target_node_pre = target_node_pre->next;
				continue;
			}

			while (search_node_pre->next->val < target_node_pre->next->val)
			{
				search_node_pre = search_node_pre->next;
			}

			ListNode* target_node = target_node_pre->next;
			target_node_pre->next = target_node->next;
			target_node->next = search_node_pre->next;
			search_node_pre->next = target_node;

			search_node_pre = pre_head;


			//�ƶ�����ڵ�
		}
		return pre_head->next;


		

	}

	ListNode* Insertionsort_link_1(ListNode* Link_head)
	{ 
		if (Link_head == nullptr || Link_head->next == nullptr)
		{
			return Link_head;
		}
		ListNode* pre_head = new ListNode(0, Link_head);	//����ָ��ͷ��ָ��
		ListNode* pre_target = pre_head->next;
		ListNode* pre_check = pre_head;

		while (pre_target->next != nullptr)
		{
			/*
			*	1���ҵ�λ��
			*	2������
			*/
			int t_value = pre_target->next->val;
			if (pre_target->val <= t_value)
			{
				// ��ֵ�Ѿ�����Ҫ�ƶ�
				pre_target = pre_target->next;
				continue;
			}

			while (pre_check->next->val <= t_value)
			{
				//�ҵ�λ��
				pre_check = pre_check->next;
			}

			//����Ԫ��
			ListNode* target_node = pre_target->next;
			pre_target->next = pre_target->next->next;
			target_node->next = pre_check->next;
			pre_check->next = target_node;

			//��ԭpre_check
			pre_check = pre_head;
		}
		return pre_head->next;
	}


};

//�������� �������
ostream& operator <<(ostream& output, ListNode* link_head)
{
	ListNode* nodes = link_head;
	if (link_head == nullptr)
	{
		output << "����Ϊ��";
		return output;

	}
	else
	{
		while (nodes != nullptr)
		{
			output << nodes->val << "  ";
			nodes = nodes->next;
		}
		output << endl;
		return output;
	}
}

void main()
{
	ListNode* node_4 = new ListNode(0);
	ListNode* node_3 = new ListNode(4, node_4);
	ListNode* node_2 = new ListNode(3, node_3);
	ListNode* node_1 = new ListNode(5, node_2);
	ListNode* link_head = new ListNode(-1, node_1);

	Solution S;
	link_head = S.Insertionsort_link_1(link_head);

	cout << link_head;
	
	
	

}