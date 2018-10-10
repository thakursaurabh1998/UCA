class AVL {
    class Node {
        int data;
        Node left;
        Node right;

        Node(int d) {
            data = d;
            left = right = null;
        }
    }

    private Node root;

    AVL() {
        root = null;
    }

    void insert(int key) {
        root = insertRecursive(root, key);
    }

    private void inorder(Node r) {
        if (r == null)
            return;
        inorder(r.left);
        System.out.print(r.data + " ");
        inorder(r.right);
    }

    void inorderDisp() {
        inorder(root);
    }

    private int height(Node r) {
        if (r == null)
            return 0;
        return 1 + Math.max(height(r.left), height(r.right));
    }

    private int getBalance(Node r) {
        if (r == null)
            return 0;
        return height(r.right) - height(r.left);
    }

    private Node leftRotate(Node x) {
        Node temp = x.right;
        Node u = temp.left;
        temp.left = x;
        x.right = u;
        return temp;
    }

    private Node rightRotate(Node x) {
        Node temp = x.left;
        Node u = temp.right;
        temp.right = x;
        x.left = u;
        return temp;
    }

    private Node insertRecursive(Node r, int key) {
        if (r == null) {
            r = new Node(key);
            return r;
        }
        if (r.data > key)
            r.left = insertRecursive(r.left, key);
        else
            r.right = insertRecursive(r.right, key);
        int balance = getBalance(r);
        if (balance > 1) {
            int c = getBalance(r.right);
            if (c < 0)
                r.right = rightRotate(r.right);
            r = leftRotate(r);
        } else if (balance < -1) {
            int c = getBalance(r.left);
            if (c > 0)
                r.left = leftRotate(r.left);
            r = rightRotate(r);
        }
        return r;
    }
}

public class AVLTree {
    public static void main(String[] args) {
        AVL n = new AVL();
        n.insert(15);
        n.insert(20);
        n.insert(24);
        n.insert(10);
        n.insert(13);
        n.insert(7);
        n.insert(30);
        n.insert(36);
        n.insert(25);
        n.inorderDisp();
    }
}