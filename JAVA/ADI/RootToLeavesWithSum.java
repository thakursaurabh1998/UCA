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
        int val;

        Node(int d) {
            this.val = d;
            this.left = this.right = null;
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

public class RootToLeavesWithSum {
    static ArrayList<ArrayList<Integer>> path(BinaryTree.Node root, ArrayList<Integer> arr) {
        if (root.left == null && root.right == null) {
            ArrayList<ArrayList<Integer>> full = new ArrayList<>();
            ArrayList<Integer> temp = new ArrayList<>();
            temp.addAll(arr);
            temp.add(root.val);
            full.add(temp);
            return full;
        }
        ArrayList<Integer> newarr = new ArrayList<>();
        newarr.addAll(arr);
        newarr.add(root.val);

        ArrayList<ArrayList<Integer>> leftarr = null;
        ArrayList<ArrayList<Integer>> rightarr = null;
        int l = 0;
        int r = 0;
        if (root.left != null)
            leftarr = path(root.left, newarr);
        if (root.right != null)
            rightarr = path(root.right, newarr);
        if (leftarr != null)
            l = leftarr.size();
        if (rightarr != null)
            r = rightarr.size();
        ArrayList<ArrayList<Integer>> darr = new ArrayList<>();
        if (l != 0)
            darr.addAll(leftarr);
        if (r != 0)
            darr.addAll(rightarr);
        leftarr = null;
        rightarr = null;
        return darr;
    }

    static ArrayList<ArrayList<Integer>> pathSum(BinaryTree.Node root, int sum) {
        ArrayList<Integer> arr = new ArrayList<>();
        ArrayList<ArrayList<Integer>> a = path(root, arr);
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        for (int i = 0; i < a.size(); i++) {
            int s = 0;
            for (int j = 0; j < a.get(i).size(); j++)
                s += a.get(i).get(j);
            if (s == sum)
                res.add(a.get(i));
        }
        return res;
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
        bt.add(8);
        bt.add(-1);
        bt.add(-2);
        bt.add(4);
        bt.printLevel();
        ArrayList<ArrayList<Integer>> res = pathSum(bt.root, 29);
        System.out.println(res.toString());
    }
}