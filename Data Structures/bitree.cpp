/*
* 二叉树相关操作
*/

#include <iostream>
#include <vector>
#include <deque>
#include <queue>
#include<stdlib.h>

using namespace std;

//树结构
struct Tree_node
{
	int info;
	Tree_node* l_node;
	Tree_node* r_node;
	Tree_node() :info(0), l_node(nullptr), r_node(nullptr) {}
	Tree_node(int p_info): info(p_info), l_node(nullptr), r_node(nullptr){}
};

ostream& operator<<(ostream& output, vector<int>vec)
{
	for (int i=0; i<vec.size(); i++)
	{
		output << vec[i] << "   ";
	}
	output << endl;
	return output;
}

class Bitree
{
private:
	vector<int> preorder;
	vector<int> inorder;
public:
	Bitree()
	{
		int a = 0, b = 0;
		cout << "请输入先序遍历,以-9999为结束" << endl;
		while (cin>>a)
		{
			if (a == -9999) break;
			this->preorder.push_back(a);
		}
		cout << preorder;

		cout << "请输入中序遍历，以-9999为结束" << endl;
		while (cin>>b)
		{
			if (b == -9999) break;
			this->inorder.push_back(b);
		}
		cout << inorder;
	}

	Bitree(vector<int>p_pre_order,vector<int>p_in_order):preorder(p_pre_order),inorder(p_in_order){}

	Tree_node* create_tree_preorder_inorder(Tree_node* Tree_root)
	{
		// 创建树
		create_pre_in_process(Tree_root, 0, inorder.size()-1,0, inorder.size()-1);

		return Tree_root;
	}

	void traverse_post_order(Tree_node* root)
	{
		if (root != nullptr)
		{
			traverse_post_order(root->l_node);
			traverse_post_order(root->r_node);
			cout<<root->info<<"   ";
		}
	}

	void traverse_layer(Tree_node* root)
	{
		//一层一层遍历
		if (root == nullptr) return;

		queue<Tree_node*> temp_queue;
		temp_queue.push(root);

		while (!temp_queue.empty())
		{
			Tree_node* temp_node = temp_queue.front();
			temp_queue.pop();
			cout << temp_node->info << endl;
			if (temp_node->l_node != nullptr)
			{
				temp_queue.push(temp_node->l_node);
			}
			if (temp_node->r_node != nullptr)
			{
				temp_queue.push(temp_node->r_node);
			}
		}



		
	}


	void create_pre_in_process(Tree_node* Tree_root, int start_pre, int end_pre, int start_in, int end_in)
	{
		Tree_root->info = this->preorder[start_pre];

		int temp_loc = start_in;
		for (int i = start_in; i<=end_in; i++)
		{
			if (preorder[start_pre] == inorder[i])
			{
				temp_loc = i;
				break;
			}
		}
		
		//有左子树
		if ( temp_loc != start_in)
		{
			Tree_node* left_child = new Tree_node();
			Tree_root->l_node = left_child;
			int temp_start_pre = start_pre + 1;
			int temp_end_pre = start_pre + temp_loc - start_in;
			create_pre_in_process(left_child, temp_start_pre,temp_end_pre, start_in, temp_loc-1);
		}

		//有右子树
		if (temp_loc != end_in)
		{
			Tree_node* right_child = new Tree_node();
			Tree_root->r_node = right_child;
			int temp_start_pre = start_pre + temp_loc - start_in + 1;
			int temp_end_pre = end_pre;
			create_pre_in_process(right_child, temp_start_pre, temp_end_pre, temp_loc + 1, end_in);
		}

	}

	int Tree_depth(Tree_node* tree_root)
	{
		if (tree_root == nullptr)
		{
			return 0;
		}
		if (tree_root->l_node == nullptr && tree_root->r_node == nullptr)
		{
			return 1;
		}
		else
		{
			return 1 + max(Tree_depth(tree_root->l_node), Tree_depth(tree_root->r_node));
		}
	}
};


void main()
{
	Tree_node* tree_root = new Tree_node();
	vector<int> pre_order = { 5, 4, 9, 8,11, 10, 6 };
	vector<int> in_order = { 9,4,11,8,5,6,10 };


	Bitree T = Bitree(pre_order,in_order);
	T.create_tree_preorder_inorder(tree_root);
	T.traverse_layer(tree_root);		//层次遍历
	//T.traverse_post_order(tree_root);	//后续遍历
	cout << "树的深度为" << T.Tree_depth(tree_root) << endl;




}