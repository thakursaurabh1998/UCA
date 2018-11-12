import java.util.Queue;
import java.util.Stack;
import java.util.Collections;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.LinkedList;

class BinaryTree {
    Node root;

    BinaryTree() {
        this.root = null;
    }

    class Node implements Comparable<Node> {
        Node left;
        Node right;
        int data;
        int displacement;

        Node(int d) {
            this.right = null;
            this.left = null;
            this.data = d;
        }

        @Override
        public int compareTo(Node a) {
            return this.displacement - a.displacement;
        }

        @Override
        public String toString() {
            return this.data + "";
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

    private void inorder(int s, Node root, ArrayList<Node> arr) {
        if (root == null)
            return;
        inorder(s - 1, root.left, arr);
        root.displacement = s;
        arr.add(root);
        inorder(s + 1, root.right, arr);
    }

    public int[] getDisplacement() {
        ArrayList<Node> arr = new ArrayList<>();
        inorder(0, this.root, arr);
        Collections.sort(arr);
        int[] res = new int[] { arr.get(0).displacement, arr.get(arr.size() - 1).displacement };
        return res;
    }

    public void visualize() {
        int[] minmax = getDisplacement();
        Queue<Node> q = new LinkedList<>();
        Node r = this.root;
        q.add(r);
        q.add(null);
        int level = 0;
        String a = "";
        int min;
        int max;
        while (!q.isEmpty()) {
            Node temp = q.remove();
            if (temp == null) {
                System.out.println(a);
                a = "";
                // System.out.println("-------------");
                System.out.println();
                level++;
                if (q.isEmpty())
                    break;
                q.add(null);
            } else {
                min = minmax[0];
                while (min < temp.displacement - (a.length() / 5)) {
                    min++;
                    a += "    ";
                }
                a += temp.data + "   ";
                if (temp.left != null)
                    q.add(temp.left);
                if (temp.right != null)
                    q.add(temp.right);
            }
        }
    }
}

public class VisualizeBT {
    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.add(10);
        tree.add(30);
        tree.add(40);
        tree.add(5);
        tree.add(6);
        tree.add(8);
        tree.add(-2);
        tree.add(2);
        tree.add(1);
        // tree.printLevel();
        tree.visualize();
    }
}