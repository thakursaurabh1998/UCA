public class LinkedList {
    Node head;

    private class Node {
        Integer data;
        Node next;

        Node(Integer d) {
            this.data = d;
            this.next = null;
        }
    }

    LinkedList() {
        this.head = null;
    }

    public void add(Integer v) {
        Node root = this.head;
        if (head == null) {
            this.head = new Node(v);
            return;
        }
        while (root.next != null) {
            root = root.next;
        }
        root.next = new Node(v);
    }

    public String toString() {
        String res = "HEAD -> ";
        Node root = this.head;
        while (root != null) {
            res = res + root.data.toString() + " -> ";
            root = root.next;
        }
        return res;
    }

    public static void main(String[] args) {
        LinkedList ll = new LinkedList();
        ll.add(1);
        ll.add(2);
        ll.add(3);
        ll.add(4);
        System.out.println(ll.toString());
    }
}