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

public class FlattenBTtoLL {
    static void flatten(BinaryTree.Node root) {
        while (root.right != null) {
            if (root.left != null || root.right != null) {
                BinaryTree.Node temp = root.right;
                root.right = root.left;
                root.left = null;
                BinaryTree.Node temp1 = root.right;
                while (temp1.right != null) {
                    temp1 = temp1.right;
                }
                temp1.right = temp;
            }
            root = root.right;
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
        flatten(tree.root);
        tree.printLevel();
    }
}