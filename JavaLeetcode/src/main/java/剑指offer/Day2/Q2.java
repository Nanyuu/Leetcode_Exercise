package 剑指offer.Day2;


/**
 * 反转链表
 */
public class Q2 {
    public static class ListNode {
        int val;
        ListNode next;
        ListNode(int x) { val = x; }
    }
    public static ListNode reverseList(ListNode head) {
        ListNode preNode = head;
        if(preNode == null || preNode.next == null)
        {
            return preNode;
        }
        ListNode tempNode = preNode.next;
        while(tempNode != null){
            ListNode nextNode = tempNode.next;
            tempNode.next = preNode;
            preNode = tempNode;
            tempNode = nextNode;
        }
        head.next =null;
        return preNode;

    }

    public static void main(String[] args) {
        Q2.ListNode first = new Q2.ListNode(1);
        Q2.ListNode second = new Q2.ListNode(2);
        Q2.ListNode third = new Q2.ListNode(3);
        first.next = second;
        second.next = third;
        third.next = null;

        System.out.println(Q2.reverseList(first));
    }
}
