package 剑指offer.Day2;


import java.util.HashMap;

/**
 * Copy a linkList
 * next->   Node
 * random next-> Node
 * value -> Int
 */
public class Q3 {
    public Node copyRandomList(Node head) {
        // copy the next
        Node tempNode = head;

        HashMap<Node, Node> myMap = new HashMap<>();


        // create the DulpHead;
        Node newHead = new Node(-1);
        Node newPre = newHead;

        while(tempNode != null){
            Node newNode = new Node(tempNode.val);
            myMap.put(tempNode, newNode);
            newPre.next = newNode;
            newPre = newNode;
            tempNode =tempNode.next;
        }

        tempNode = head;
        Node newTempNode = newHead.next;
        while(tempNode != null){
            newTempNode.random = myMap.get(tempNode.random);
            tempNode = tempNode.next;
            newTempNode = newTempNode.next;
        }
        return newHead.next;

    }
}
