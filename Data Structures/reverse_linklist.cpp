#include<iostream>

using namespace std;

struct LinkNode
{
	int info;
	struct LinkNode* next;
};

//��������
LinkNode* create_Linklist(LinkNode *Linkhead)
{

	LinkNode* LinkNode_temp = Linkhead;
	
	int info = 0;
	cout << "�����������е���,�Կո��˳�" << endl;
	cin >> info;
	while (info != EOF)
	{
		
		
		LinkNode* temp_linknode = new LinkNode;
		temp_linknode->info = info;
		temp_linknode->next = nullptr;

		LinkNode_temp->next = temp_linknode;
		LinkNode_temp = temp_linknode;
		cout << "�����������е���,�Կո��˳�" << endl;
		cin >> info;
	}

	return Linkhead;
}

ostream& operator <<(ostream& output, LinkNode* LinkList_head)
{
	LinkNode* node = new LinkNode;
	if (LinkList_head ->next == nullptr)
	{
		output << "����Ϊ��" << endl;
		return output;
	}
	node = LinkList_head;
	while (node ->next != nullptr)
	{
		node = node->next;
		output << node->info <<"  ";
	}
	output << endl;
	return output;
}

//����Ԫ�ص�ָ��λ��
LinkNode* assert_node(LinkNode* Linkhead, int position, int value)
{
	LinkNode* Node = Linkhead->next;
	int temp_position = 1;
	while (Node->next != nullptr && temp_position != position)
	{
		Node = Node->next;
		temp_position = temp_position + 1;
	}
	if (Node->next != nullptr)
	{
		LinkNode* new_node = new LinkNode;
		new_node->info = value;
		new_node->next = Node->next;
		Node->next = new_node;

	}
	else
	{
		cout << "�ڵ�λ�ò�����" << endl;
	}
	return Linkhead;
}

// ��ת����
LinkNode* reverse_linklist(LinkNode* Link_head)
{
	if (Link_head->next == nullptr)
	{
		cout << "����Ϊ��" << endl;
		return Link_head;
	}

	LinkNode* PRE = Link_head->next;
	LinkNode* temp = PRE->next;
	
	while (temp ->next != nullptr)
	{
		LinkNode* POST = temp->next;
		temp->next = PRE;
		PRE = temp;
		temp = POST;
	}
	temp->next = PRE;
	Link_head->next->next = nullptr;
	Link_head->next = temp;
}




void main()
{
	LinkNode* LinkList_head = new LinkNode;
	LinkList_head->info = 0;
	LinkList_head->next = nullptr;

	LinkList_head = create_Linklist(LinkList_head);
	cout << "����Ϊ"<<LinkList_head;

	LinkList_head = assert_node(LinkList_head, 3, 10);
	cout << "����Ԫ�غ������Ϊ��"<<LinkList_head;

	LinkList_head = reverse_linklist(LinkList_head);
	cout << "��ת�������Ϊ" << LinkList_head << endl;

}