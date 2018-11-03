import java.util.Queue;
import java.util.LinkedList;

class DoubleLinkedList {
    Node head;
    Node tail;

    private class Node {
        int val;
        Node prev;
        Node next;

        Node(int v) {
            if (head == null) {
                this.val = v;
                this.prev = this;
                this.next = this;
            } else {
                this.val = v;
                this.prev = tail;
                this.next = head;
            }
        }
    }

    DoubleLinkedList() {
        this.head = null;
        this.tail = null;
    }

    public void add(int v) {
        if (this.head == null) {
            this.head = new Node(v);
            this.tail = this.head;
        } else {
            this.tail = new Node(v);
        }
    }
}

class Node {
    public Node left;
    public Node right;
    public int data;

    Node(int d) {
        this.right = null;
        this.left = null;
        this.data = d;
    }
}

class BST {
    public Node root;

    BST() {
        this.root = null;
    }

    private Node add(Node root, int v) {
        if (root == null)
            return new Node(v);
        if (root.data > v)
            root.left = add(root.left, v);
        else
            root.right = add(root.right, v);

        return root;
    }

    public Node getroot() {
        return this.root;
    }

    public void add(int v) {
        this.root = add(this.root, v);
    }

    public void printLevel() {
        Queue<Node> q = new LinkedList<>();
        Node r = this.root;
        q.add(r);
        q.add(null);
        while (!q.isEmpty()) {
            // System.out.println("`SIZE: " + q.size());
            Node temp = q.remove();
            if (temp == null) {
                System.out.println();
                System.out.println("-------------");
                if (q.isEmpty())
                    break;
                q.add(null);
            } else {
                System.out.print(temp.data + " ");
                if (temp.left != null)
                    q.add(temp.left);
                if (temp.right != null)
                    q.add(temp.right);
            }
        }
    }
}

class LL {
    Node head;
    Node tail;

    private class Node {
        int val;
        Node next;

        Node(int v) {
            this.val = v;
            this.next = null;
        }
    }

    LL() {
        this.head = null;
        this.tail = null;
    }

    public void add(int v) {
        if (this.head == null) {
            this.head = new Node(v);
            this.tail = this.head;
        } else {
            this.tail.next = new Node(v);
            this.tail = this.tail.next;
        }
        // System.out.println(this.tail.val);
    }

    public void print() {
        Node root = this.head;
        while (root != null) {
            System.out.print(root.val + " -> ");
            root = root.next;
        }
    }
}

public class BSTtoLL {
    public static void inorder(Node r, LL l) {
        if (r == null)
            return;
        inorder(r.left, l);
        l.add(r.data);
        inorder(r.right, l);
    }

    public static LL createLL(BST root) {
        LL ll = new LL();
        inorder(root.getroot(), ll);
        return ll;
    }

    public static void main(String[] args) {
        BST tree = new BST();
        tree.add(5);
        tree.add(3);
        tree.add(6);
        tree.add(2);
        tree.add(4);
        // tree.printLevel();
        LL l = new LL();
        l = createLL(tree);
        l.print();
        // tree.printLevel();
    }
}