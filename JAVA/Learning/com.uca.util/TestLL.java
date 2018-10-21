interface Collection<T> extends Iterable<T> {
    public void add(T t);

    public void remove(T t);

    public int size();

    public boolean isEmpty();

    public void clear();
}

interface Iterable<T> {

}

interface Iterator<T> {
    public boolean hasNext();

    public T next();
}

interface List<T> extends Collection<T> {
    // public void add(T t, int index);

    // public void remove(int index);

    public T get(int index);
}

class LinkedList<T> implements List<T> {
    private Node<T> head;
    private int size;

    private class Node<T> {
        T data;
        Node<T> next;

        Node(T d) {
            this.data = d;
            this.next = null;
        }
    }

    LinkedList() {
        this.head = null;
        this.size = 0;
    }

    public int size() {
        return this.size;
    }

    @Override
    public T get(int index) {
        Node<T> root = this.head;
        for (int i = 0; i <= index; i++) {
            root = root.next;
        }
        T temp = root.data;
        return temp;
    }

    @Override
    public void clear(){

    }

    @Override
    public boolean isEmpty() {
        return false;
    }

    @Override
    public void add(T v) {
        if (this.head == null) {
            this.head = new Node(v);
            return;
        }
        Node root = this.head;
        while (root.next != null) {
            root = root.next;
        }
        root.next = new Node<T>(v);
    }

    @Override
    public void remove(T v) {
        Node root = this.head;
        while (root != null && root.next != null) {
            if (root.data.equals(v))
                break;
            root = root.next;
        }
    }

    // @Override
    public Iterator<T> iterator() {
        return new Iterator<T>() {
            private Node<T> n = head;

            @Override
            public boolean hasNext() {
                return n != null;
            }

            @Override
            public T next() {
                T t = n.data;
                n = n.next;
                return t;
            }
        };
    }

    public String toString() {
        String res = "HEAD -> ";
        Node root = this.head;
        while (root != null) {
            res = res + root.data.toString() + " -> ";
            root = root.next;
        }
        return res;
    }
}

public class TestLL {
    public static void main(String[] args) {
        List<Integer> list = new LinkedList<>();
        list.add(1);
        list.add(2);
        list.add(3);
        assert list.size() == 2;
    }
}