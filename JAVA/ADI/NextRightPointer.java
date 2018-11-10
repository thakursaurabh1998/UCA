import java.util.Queue;
import java.util.Stack;
import java.util.LinkedList;

class BinaryTree {
    Node root;

    BinaryTree() {
        this.root = null;
    }

    class Node {
        Node left;
        Node right;
        Node next;
        int val;

        Node(int d) {
            this.right = null;
            this.left = null;
            this.next = null;
            this.val = d;
        }
    }

    private Node add(Node root, int v) {
        if (root == null)
            return new Node(v);
        if (root.val > v)
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
                System.out.print(temp.val + " ");
                if (temp.left != null)
                    q.add(temp.left);
                if (temp.right != null)
                    q.add(temp.right);
            }
        }
    }
}

public class NextRightPointer {

    public static void next(BinaryTree.Node root) {
        Queue<BinaryTree.Node> q = new LinkedList<>();
        BinaryTree.Node r = root;
        q.add(r);
        q.add(null);
        while (!q.isEmpty()) {
            // System.out.println("`SIZE: " + q.size());
            BinaryTree.Node temp = q.remove();
            if (temp == null) {
                if (q.isEmpty())
                    break;
                q.add(null);
            } else {
                // System.out.print(temp.val + " ");
                temp.next = q.peek();
                if (temp.left != null)
                    q.add(temp.left);
                if (temp.right != null)
                    q.add(temp.right);
            }
        }
    }

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.add(4);
        tree.add(2);
        tree.add(5);
        tree.add(1);
        tree.add(3);
        tree.add(6);
        tree.printLevel();
        next(tree.root);
        if (tree.root.left.left.next.next!= null)
            System.out.println(tree.root.left.left.next.next.val);
    }
}