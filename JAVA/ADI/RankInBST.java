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

    private Node findPredecessor(Node root) {
        Node parent = root;
        root = root.left;
        if (root == null)
            return null;
        while (root.right != null && root.right != parent)
            root = root.right;
        return root;
    }

    private int morisonInorder(int d) {
        Node curr = root;
        Node predecessor = root;
        int index = 1;
        while (curr != null) {
            if (curr.left == null) {
                if (d == curr.data)
                    return index;
                index++;
                curr = curr.right;
            } else {
                predecessor = findPredecessor(curr);
                if (predecessor.right == null) {
                    predecessor.right = curr;
                    curr = curr.left;
                } else if (predecessor.right == curr) {
                    if (d == curr.data)
                        return index;
                    index++;
                    curr = curr.right;
                    predecessor.right = null;
                }
            }
        }
        return -1;
    }

    public void rank(int r) {
        System.out.println(this.morisonInorder(r));
    }
}

public class RankInBST {

    public static void main(String[] args) {
        BST tree = new BST();
        tree.add(6);
        tree.add(7);
        tree.add(3);
        tree.add(9);
        tree.add(2);
        tree.add(8);
        tree.add(4);
        tree.add(10);
        tree.add(5);
        tree.printLevel();
        tree.rank(2);
    }
}