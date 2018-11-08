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

public class RootToLeaves {
    static int[][] path(BinaryTree.Node root, int[] arr) {
        if (root.left == null && root.right == null) {
            int full[][] = new int[1][arr.length+1];
            System.arraycopy(arr, 0, full[0], 0, arr.length);
            full[0][arr.length] = root.data;
            return full;
        }
        int newarr[] = new int[arr.length + 1];
        System.arraycopy(arr, 0, newarr, 0, arr.length);
        newarr[arr.length] = root.data;
        int leftarr[][] = null;
        int rightarr[][] = null;
        int l = 0;
        int r = 0;
        if (root.left != null)
            leftarr = path(root.left, newarr);
        if (root.right != null)
            rightarr = path(root.right, newarr);
        if (leftarr != null)
            l = leftarr.length;
        if (rightarr != null)
            r = rightarr.length;
        int darr[][] = new int[l + r][];
        int p = 0;
        if (l != 0) {
            for (int i = 0; i < l; i++) {
                darr[p++] = new int[leftarr[i].length];
            }
            System.arraycopy(leftarr, 0, darr, 0, l);
        }
        if (r != 0) {
            for (int i = 0; i < l; i++) {
                darr[p++] = new int[rightarr[i].length];
            }
            System.arraycopy(rightarr, 0, darr, l, r);
        }
        return darr;
    }

    static int[][] path(BinaryTree.Node root) {
        int arr[] = new int[0];
        int a[][] = path(root, arr);

        return a;
    }

    public static void main(String[] args) {
        BinaryTree bt = new BinaryTree();
        bt.add(3);
        bt.add(2);
        bt.add(1);
        bt.add(5);
        bt.add(6);
        bt.add(4);
        bt.add(7);
        bt.printLevel();
        int res[][] = path(bt.root);
        for(int[] i: res)
            System.out.println(Arrays.toString(i));
    }
}