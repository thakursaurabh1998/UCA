import java.util.LinkedList;
import java.util.Queue;

class BST {
    public Node root;

    private class Node {
        public Node left;
        public Node right;
        public int data;

        Node(int d) {
            this.right = null;
            this.left = null;
            this.data = d;
        }
    }

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

    public int diff() {
        Queue<Node> q = new LinkedList<>();
        Node r = this.root;
        q.add(r);
        q.add(null);
        int level = 1;
        int even = 0, odd = 0;
        while (!q.isEmpty()) {
            Node temp = q.remove();
            if (temp == null) {
                level++;
                if (q.isEmpty())
                    break;
                q.add(null);
            } else {
                if (level % 2 == 0) {
                    even += temp.data;
                } else {
                    odd += temp.data;
                }
                if (temp.left != null)
                    q.add(temp.left);
                if (temp.right != null)
                    q.add(temp.right);
            }
        }

        System.out.println(even + " " + odd);

        return odd - even;
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

public class OddEvenNodes {

    public static void main(String[] args) {
        BST tree = new BST();
        tree.add(4);
        tree.add(7);
        tree.add(12);
        tree.add(15);
        tree.add(3);
        tree.add(5);
        tree.add(14);
        tree.add(18);
        tree.add(16);
        tree.add(17);
        tree.printLevel();
        System.out.println(tree.diff());
    }
}