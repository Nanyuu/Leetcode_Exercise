/*
* 整合K个排序后的链表
* 例：
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
* 
*/

#include<iostream>
#include<vector>
#include<map>

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
		//暴力解法
		ListNode* new_list_head = new ListNode();
		ListNode* new_node = new_list_head;

		while (1)
		{
			int record_id = 0;
			int min_value = 9999;

			for (int i = 0; i < lists.size(); i++)
			{
				if (lists[i]!=nullptr && lists[i]->val < min_value)
				{
					min_value = lists[i]->val;
					record_id = i;
				}
			}

			if (min_value == (9999))
			{
				break;
			}
			else
			{
				new_node->next = lists[record_id];
				new_node = new_node->next;
				lists[record_id] = lists[record_id]->next;
 			}

		}
		return new_list_head->next;

    }

	ListNode* mergeKLists_1(vector<ListNode*>& lists) {
		//利用map的红黑树，自动找到最大值

		//利用multimap，自带映射
		multimap<int, ListNode*> map_1;
		for (auto l : lists)
		{
			if (l != nullptr)
			{
				map_1.insert({ l->val, l }); //插入数据
			}
			
		}

		ListNode* head_new_list = new ListNode();
		ListNode* new_node = head_new_list;

		while (!map_1.empty())
		{
			//取出最大值
			multimap<int, ListNode*>::iterator it = map_1.begin();

			new_node->next = it->second;
			new_node = new_node->next;

			if (it->second->next != nullptr)
			{
				//不为空时插入新元素
				map_1.insert({ it->second->next->val, it->second->next });
			}

			map_1.erase(it);

		}

		return head_new_list->next;


	}
};


//创建链表
ListNode* create_list(vector<int> vc)
{
	ListNode* head = new ListNode(vc[0]);
	ListNode* temp_node_pre = head;
	for (int i = 1; i < vc.size(); i++)
	{
		ListNode* temp_node = new ListNode(vc[i]);
		temp_node_pre->next = temp_node;
		temp_node_pre = temp_node;
	}
	return head;
}

//输出重载
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
	//[[1,3,4,6,8,9,12],[1,2,5,7,11,21,24],[-4,0,4,7,10,14,22,29]]
    //vector<int> list_1 = { };
    //vector<int> list_2 = { };
    //vector<int> list_3 = { };
    //ListNode* head_1 = create_list(list_1);
    //ListNode* head_2 = create_list(list_2);
    //ListNode* head_3 = create_list(list_3);

	vector<ListNode*> linked_lists = { {} };
	
	Solution S;
	
	cout << S.mergeKLists_1(linked_lists)<< endl;


}
