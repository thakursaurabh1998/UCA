import java.util.LinkedList;
import java.util.Queue;

// RED BLACK Tree

public class BalancedBST<K extends Comparable<K>, V> {
    private Node root = null;
    private final boolean RED = false;
    private final boolean BLACK = true;

    public void add(K key, V val) {
        root = add(root, key, val);
        root.color = BLACK;
    }

    public V get(K key) {
        Node n = get(root, key);
        return n == null ? null : n.val;
    }

    public int height() {
        return height(root);
    }

    private boolean getColor(Node n) {
        if (n == null)
            return BLACK;
        return n.color;
    }

    private Node add(Node n, K key, V val) {
        if (n == null)
            return new Node(key, val);
        int cmp = key.compareTo(n.key);
        if (cmp == 0)
            n.val = val;
        else if (cmp > 0)
            n.right = add(n.right, key, val);
        else
            n.left = add(n.left, key, val);
        if (getColor(n.left) == BLACK && getColor(n.right) == RED)
            n = leftRotate(n);
        if (getColor(n.left) == RED && getColor(n.left.left) == RED)
            n = rightRotate(n);
        if (getColor(n.left) == RED && getColor(n.right) == RED)
            n = swapColor(n);
        return n;
    }

    private Node leftRotate(Node n) {
        System.out.println("Left Rotating on " + n.key);
        Node t = n.right;
        n.right = t.left;
        t.left = n;
        t.color = n.color;
        n.color = RED;
        return t;
    }

    private Node rightRotate(Node n) {
        System.out.println("Right Rotating on " + n.key);
        Node t = n.left;
        n.left = t.right;
        t.right = n;
        t.color = n.color;
        n.color = RED;
        return t;
    }

    private Node swapColor(Node n) {
        System.out.println("Swapping Colors for " + n.key);
        n.left.color = n.color;
        n.right.color = n.color;
        n.color = RED;
        return n;
    }

    private Node get(Node n, K key) {
        if (n == null)
            return null;
        int cmp = key.compareTo(n.key);
        if (cmp == 0)
            return n;
        return cmp > 0 ? get(n.right, key) : get(n.left, key);
    }

    private int height(Node n) {
        if (n == null)
            return 0;
        return 1 + Math.max(height(n.left), height(n.right));
    }

    private class Node {
        private K key;
        private V val;
        private Node left;
        private Node right;
        private boolean color;

        public Node(K key, V val) {
            this.key = key;
            this.val = val;
            this.right = null;
            this.left = null;
            this.color = RED;
        }
    }

    private void print(Node r) {
        if (r == null)
            return;
        System.out.println(r.key + " " + ((r.color) ? "Black" : "Red"));
        print(r.left);
        print(r.right);
    }

    public void print() {
        print(this.root);
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
                System.out.println("-------------");
                if (q.isEmpty())
                    break;
                q.add(null);
            } else {
                System.out.println(temp.key + "\t" + (temp.color ? "Black" : "-Red-"));
                if (temp.left != null)
                    q.add(temp.left);
                if (temp.right != null)
                    q.add(temp.right);
            }
        }
    }

    public static void main(String[] args) {
        BalancedBST<Integer, String> rbt = new BalancedBST<>();
        rbt.add(4, "one");
        rbt.add(7, "two");
        rbt.add(12, "three");
        rbt.add(15, "four");
        rbt.add(3, "five");
        rbt.add(5, "six");
        rbt.add(14, "seven");
        rbt.add(18, "eight");
        rbt.add(16, "nine");
        rbt.add(17, "ten");
        rbt.printLevel();
        // rbt.print();
    }
}