import java.util.Queue;
import java.util.Stack;
import java.util.ArrayList;
import java.util.LinkedList;

class BinaryTree {
    Node root;

    BinaryTree() {
        this.root = null;
    }

    class Node {
        Node left;
        Node right;
        int data;

        Node(int d) {
            this.right = null;
            this.left = null;
            this.data = d;
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

public class ZigZagTraversal {
    public static ArrayList<ArrayList<Integer>> zigzag(BinaryTree.Node root) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        Queue<BinaryTree.Node> q = new LinkedList<>();
        BinaryTree.Node r = root;
        q.add(r);
        int level = 1;
        q.add(null);
        Stack<Integer> stk = new Stack<>();
        ArrayList<Integer> arr = new ArrayList<>();
        while (!q.isEmpty()) {
            BinaryTree.Node temp = q.remove();
            if (temp == null) {
                // res.add(arr);
                if (level % 2 == 0) {
                    arr = new ArrayList<>();
                    while (!stk.isEmpty()) {
                        arr.add(stk.peek());
                        stk.pop();
                    }
                }
                res.add(arr);
                arr = new ArrayList<>();
                if (q.isEmpty())
                    break;
                q.add(null);
                level++;
            } else {
                if (level % 2 == 0) {
                    stk.push(temp.data);
                } else {
                    arr.add(temp.data);
                }
                if (temp.left != null)
                    q.add(temp.left);
                if (temp.right != null)
                    q.add(temp.right);
            }
        }

        return res;
    }

    public static void main(String[] args) {
        BinaryTree tree = new BinaryTree();
        tree.add(4);
        tree.add(2);
        tree.add(7);
        tree.add(9);
        tree.add(8);
        tree.add(5);
        tree.add(1);
        tree.add(3);
        tree.add(6);
        tree.printLevel();
        ArrayList<ArrayList<Integer>> res = zigzag(tree.root);
        System.out.println(res.toString());
    }
}