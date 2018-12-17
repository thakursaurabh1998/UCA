import java.util.*;

public class AVL {
  Node root;

  private class Node {
    Node left;
    Node right;
    int data;

    Node(int d) {
      this.data = d;
      this.left = null;
      this.right = null;
    }
  }

  private int getHeight(Node head) {
    if (head == null)
      return 0;
    return 1 + Math.max(getHeight(head.left), getHeight(head.right));
  }

  private int getBalance(Node head) {
    return this.getHeight(head.left) - this.getHeight(head.right);
  }

  private Node rotateRight(Node head) {
    Node h = head.left;
    Node t = h.right;
    head.left = t;
    h.right = head;
    return h;
  }

  private Node rotateLeft(Node head) {
    Node h = head.right;
    Node t = h.left;
    head.right = t;
    h.left = head;
    return h;
  }

  private Node insertR(int k, Node head) {
    if (head == null)
      return new Node(k);
    if (head.data > k) {
      head.left = insertR(k, head.left);
    } else {
      head.right = insertR(k, head.right);
    }
    int b = this.getBalance(head);
    if (b > 1) {
      if (this.getBalance(head.left) < 0)
        head.left = this.rotateLeft(head.left);
      head = this.rotateRight(head);
    } else if (b < -1) {
      if (this.getBalance(head.right) > 0)
        head.right = this.rotateRight(head.right);
      head = this.rotateLeft(head);
    }
    return head;
  }

  public void insert(int k) {
    this.root = this.insertR(k, this.root);
  }

  public void levelOrder() {
    Queue<Node> q = new LinkedList<>();
    q.add(this.root);
    q.add(null);
    Node head;
    while (!q.isEmpty()) {
      Node temp = q.remove();
      if (temp == null && !q.isEmpty()) {
        q.add(null);
        System.out.println();
      } else if (temp != null) {
        if (temp.left != null)
          q.add(temp.left);
        if (temp.right != null)
          q.add(temp.right);
        System.out.print(temp.data + " ");
      }
    }
  }

  private void inorderR(Node head) {
    if (head == null)
      return;
    inorderR(head.left);
    System.out.print(head.data + " ");
    inorderR(head.right);
  }

  public void inorder() {
    this.inorderR(this.root);
    System.out.println();
  }

  public static void main(String[] args) {
    AVL t = new AVL();
    t.insert(5);
    t.insert(4);
    t.insert(3);
    t.insert(2);
    t.insert(1);
    t.inorder();
    t.levelOrder();
  }
}