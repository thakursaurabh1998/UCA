import java.util.HashMap;

class LinkedList {
    Node head;

    LinkedList() {
        this.head = null;
    }

    class Node {
        int data;
        Node next;

        Node(int d) {
            this.data = d;
            this.next = null;
        }
    }

    public void add(int d) {
        Node temp = this.head;
        this.head = new Node(d);
        this.head.next = temp;
    }

    public int removeLast() {
        Node root = this.head;
        if (root.next == null) {
            int temp = this.head.data;
            this.head = null;
            return temp;
        }
        while (root.next != null && root.next.next != null) {
            root = root.next;
        }
        int temp = root.next.data;
        root.next = root.next.next;
        return temp;
    }

    public void remove(int d) {
        Node root = this.head;
        if (root.data == d) {
            this.head = this.head.next;
            return;
        }
        while (root != null && root.next != null && d != root.next.data) {
            root = root.next;
        }
        if (root.next != null)
            root.next = root.next.next;
    }
}

class LRU {
    LinkedList ll;
    HashMap<Integer, Integer> map;
    int LRU_CAP;

    LRU(int cap) {
        this.ll = new LinkedList();
        this.map = new HashMap<>();
        this.LRU_CAP = cap;
    }

    void set(int key, int val) {
        if (this.map.get(key) != null) {
            this.ll.remove(key);
            this.map.remove(key);
        }
        if (this.LRU_CAP == this.map.size()) {
            int k = this.ll.removeLast();
            this.map.remove(k);
        }
        this.ll.add(key);
        this.map.put(key, val);
    }

    int get(int key) {
        if (this.map.get(key) == null)
            return -1;
        this.ll.remove(key);
        this.ll.add(key);
        return this.map.get(key);
    }

    void print() {
        LinkedList.Node root = this.ll.head;
        while (root != null) {
            System.out.println(root.data + " : " + this.map.get(root.data));
            root = root.next;
        }
        for(Integer i: this.map.keySet()) {
            System.out.println(i);
        }
    }
}

public class Rough {
    public static void solution() {
        String str = "71 8 G 6 G 7 G 3 G 10 S 3 11 G 6 S 15 1 G 3 S 7 12 G 1 S 9 12 G 2 G 14 S 12 6 S 3 12 S 8 15 G 6 S 1 9 S 13 3 G 3 S 8 4 G 8 G 11 S 3 7 G 2 G 2 G 11 G 10 S 2 2 G 7 S 1 10 S 12 2 G 2 G 11 S 7 12 S 6 15 S 10 11 G 2 G 10 S 14 15 G 14 G 8 S 15 2 G 2 G 9 S 6 10 S 5 8 S 6 14 S 9 8 G 2 S 8 2 S 8 3 G 2 G 6 G 4 S 13 5 G 13 G 9 S 14 5 G 3 G 15 G 12 G 11 G 6 G 14 S 4 7 G 5 S 9 15 G 8 G 12 S 10 5";
        // String str = "6 1 S 2 1 S 2 2 G 2 S 1 1 S 4 1 G 2";
        String[] arr = str.split(" ");
        LRU cache = new LRU(Integer.parseInt(arr[1]));
        for (int i = 2; i < arr.length; i++) {
            if (arr[i].compareTo("S") == 0) {
                cache.set(Integer.parseInt(arr[i + 1]), Integer.parseInt(arr[i + 2]));
                i = i + 2;
            } else if (arr[i].compareTo("G") == 0) {
                System.out.print(cache.get(Integer.parseInt(arr[i + 1])) + " ");
                i = i + 1;
            }
        }
    }

    public static void main(String[] args) {
        solution();
    }
}