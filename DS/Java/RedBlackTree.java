// Every node is Red or Black
// root/Null/leaves are Black
// New element is Red
// root -> any leaf => number of black nodes is constant
// Red node cannot have both red children

// LEFT LEANING RBT
// Red is not right child
// left child and left of left child both cannot be red
// Both children can't be red

import java.util.Queue;
import java.util.LinkedList;

public class RedBlackTree {
    private Node head;
    private final boolean BLACK = false;
    private final boolean RED = true;

    private class Node {
        Node left, right;
        int key;
        boolean color; // true: red; false: black

        Node(int k) {
            this.key = k;
            this.color = RED;
            this.left = null;
            this.right = null;
        }
    }

    RedBlackTree() {
        this.head = null;
    }

    private Node leftRotate(Node root) {
        Node nr = root.right;
        Node t = nr.left;
        root.right = t;
        nr.left = root;
        // swapColor(nr);
        // swapColor(root);
        return nr;
    }

    private Node rightRotate(Node root) {
        Node nr = root.left;
        Node t = nr.right;
        root.left = t;
        nr.right = root;
        // swapColor(nr);
        // swapColor(root);
        return nr;
    }

    public void add(int k) {
        this.head = add(this.head, k);
        this.head.color = BLACK;
    }

    private Node add(Node root, int k) {
        if (root == null)
            return new Node(k);
        if (root.key > k)
            root.left = add(root.left, k);
        else
            root.right = add(root.right, k);

        return this.fixer(root);
    }

    private Node fixer(Node root) {
        if (getColor(root.left) == RED && getColor(root.right) == RED && (root.left.left != null
                || root.left.right != null || root.right.left != null || root.right.right != null)) {
            swapColor(root.left);
            swapColor(root.right);
            swapColor(root);
            System.out.println("Procedure performed on " + root.key + " with root " + root.key + " " + 1);
        } else if (getColor(root.left) == RED && getColor(root.left.left) == RED) {
            // System.out.println("Procedure performed on " + root.key + " with root " +
            // root.key + " " + 2);
            root = rightRotate(root);
            swapColor(root);
            swapColor(root.right);
        } else if (getColor(root.right) == RED && getColor(root.right.right) == RED) {
            // System.out.println("Procedure performed on " + root.key + " with root " +
            // root.key + " " + 3);
            root = leftRotate(root);
            swapColor(root);
            swapColor(root.left);
        } else if (getColor(root.right) == RED && getColor(root.right.left) == RED) {
            // System.out.println("Procedure performed on " + root.right.key + " with root "
            // + root.key + " " + 4);
            root.right = rightRotate(root.right);
            root = this.fixer(root);
        } else if (getColor(root.left) == RED && getColor(root.left.right) == RED) {
            // System.out.println("Procedure performed on " + root.left.key + " with root "
            // + root.key + " " + 5);
            root.left = leftRotate(root.left);
            root = this.fixer(root);
        }
        return root;
    }

    public void print() {
        print(this.head);
    }

    private boolean getColor(Node r) {
        if (r == null)
            return BLACK;
        return r.color;
    }

    private void swapColor(Node r) {
        r.color = !r.color;
    }

    private void print(Node head) {
        if (head == null)
            return;
        System.out.println(head.key + " : " + (head.color ? "red" : "black"));
        print(head.left);
        print(head.right);
    }

    public void printLevel() {
        Queue<Node> q = new LinkedList<>();
        Node r = this.head;
        q.add(r);
        q.add(null);
        while (!q.isEmpty()) {
            // System.out.println("`SIZE: " + q.size());
            Node temp = q.remove();
            if (temp == null) {
                System.out.println("-------------");
                if (q.isEmpty())
                    break;
                q.add(null);
            } else {
                System.out.println(temp.key + "\t" + (!temp.color ? "Black" : "-Red-"));
                if (temp.left != null)
                    q.add(temp.left);
                if (temp.right != null)
                    q.add(temp.right);
            }
        }
    }

    public static void main(String[] args) {
        RedBlackTree rbt = new RedBlackTree();
        rbt.add(4);
        rbt.add(7);
        rbt.add(12);
        rbt.add(15);
        rbt.add(3);
        rbt.add(5);
        rbt.add(14);
        rbt.add(18);
        rbt.add(16);
        rbt.add(17);
        rbt.printLevel();
    }
}