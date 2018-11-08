import java.util.Queue;
import java.util.LinkedList;
import java.util.ArrayList;
import java.util.Arrays;

class BinaryTree {
    Node root;

    BinaryTree() {
        this.root = null;
    }

    class Node {
        Node right;
        Node left;
        int data;

        Node(int d) {
            this.data = d;
            this.left = this.right = null;
        }
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
}

public class SumRootToLeaf {
    public static int sum(BinaryTree.Node root, int num) {
        if (root.left == null && root.right == null) {
            num = num * 10 + root.data;
            return num;
        }
        int left = 0;
        int right = 0;
        num = num * 10 + root.data;
        if (root.left != null)
            left = sum(root.left, num % 1003);
        if (root.right != null)
            right = sum(root.right, num % 1003);
            
        return (right + left) % 1003;
    }
    
    public static int sum(BinaryTree.Node root) {
        int a = sum(root, 0);
        return a;
    }

    public static void main(String[] args) {
        BinaryTree bt = new BinaryTree();
        bt.add(14);
        bt.add(11);
        bt.add(20);
        // bt.add(5);
        // bt.add(7);
        // bt.add(3);
        // bt.add(1);
        bt.printLevel();
        System.out.println(sum(bt.root));
    }
}