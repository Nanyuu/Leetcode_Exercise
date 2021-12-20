package 剑指offer.Day2;

import java.util.LinkedList;

/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */



public class Q1 {

    public static class ListNode {
      int val;
      ListNode next;
      ListNode(int x) { val = x; }
    }

    /**
     * 输出链表内容， 按顺序逆向输出
     * @param head 头节点 （单链表）
     * @return 数组
     */
    public static int[] reversePrint(ListNode head) {
        LinkedList<Integer> myStack = new LinkedList<>();
        ListNode myNode = head;
        while(myNode!=null)
        {
            myStack.offerFirst(myNode.val);
            myNode= myNode.next;
        }

        int[] res = new int[myStack.size()];
        int mySize = myStack.size();
        for (int i = 0; i < mySize; i++){
            res[i] = myStack.pollFirst();
        }
        return res;
    }

    public static void main(String[] args) {
        ListNode first = new ListNode(1);
        ListNode second = new ListNode(2);
        ListNode third = new ListNode(3);
        first.next = second;
        second.next = third;
        third.next = null;

        System.out.println(Q1.reversePrint(first));
    }
}
