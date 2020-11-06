# include<iostream>
using namespace std;

struct ListNode {
     int val;
    ListNode *next;
     ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
 };


//计算两个链表数的和

class Solution {
public:
    ListNode* addTwoNumbers_1(ListNode* l1, ListNode* l2) {
        ListNode *c1 = l1;
        ListNode *c2 = l2;
        ListNode* output = new ListNode(0);
        ListNode* temp_node = output;
        int sum = 0;
        while (c1 != nullptr || c2 != nullptr)
        {
            sum = sum / 10;
            if (c1 != nullptr)
            {
                sum = sum + c1->val;
            }
            if (c2 != nullptr)
            {
                sum = sum + c2->val;
            }

                ListNode* c = new ListNode(sum%10);
                temp_node->next = c;
                temp_node = c;


        }
        if (sum / 10)
        {
            ListNode* c = new ListNode(sum);
            temp_node->next = c;
        }
 
        return output->next;
    }






    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* c_head = new ListNode(-1);
        ListNode* c_temp = c_head;
        while (1)
        {
            int data = l1->val + l2->val + carry;
            cout << data << endl;
            carry = 0;
            if (data >= 10)
            {
                //产生借位
                carry = 1;
                data = data - 10;
            }
            if (c_head->val == -1)
            {
                c_head->val = data;
            }
            else {

                ListNode* c = new ListNode(data);
                c_temp->next = c;
                c_temp = c;
            }
            if (l1->next == nullptr || l2->next == nullptr)
            {
                break;
            }
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1->next == nullptr && l2->next == nullptr)
        {
            if (carry == 1)
            {
                ListNode* c = new ListNode(1);
                c_temp->next = c;
                c_temp = c;
            }
        }
        if (l1->next != nullptr)
        {
            while (1)
            {
                l1 = l1->next;
                int data = l1->val + carry;
                carry = 0;
                if (data >= 10)
                {
                    //产生借位
                    carry = 1;
                    data = data - 10;
                }
                ListNode* c = new ListNode(data);
                c_temp->next = c;
                c_temp = c;
                if (l1->next == nullptr)
                {
                    if (carry == 0)
                    {
                        break;
                    }
                    else
                    {
                        ListNode* c = new ListNode(1);
                        c_temp->next = c;
                        c_temp = c;
                        break;
                    }
                }
            }
        }
        if (l2->next != nullptr)
        {
            while (1)
            {
                l2 = l2->next;
                int data = l2->val + carry;
                carry = 0;
                if (data >= 10)
                {
                    //产生借位
                    carry = 1;
                    data = data - 10;
                }
                ListNode* c = new ListNode(data);
                c_temp->next = c;
                c_temp = c;
                if (l2->next == nullptr)
                {
                    if (carry == 0)
                    {
                        break;
                    }
                    else
                    {
                        ListNode* c = new ListNode(1);
                        c_temp->next = c;
                        c_temp = c;
                        break;
                    }
                }
            }
        }
        return c_head;

    }
};