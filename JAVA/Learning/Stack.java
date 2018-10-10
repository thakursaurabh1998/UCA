import java.util.Iterator;

public class Stack<T> implements Iterable<T> {
    private Node<T> first;
    private int n;

    private class StackIterator<T> implements Iterator<T> {
        private Node<T> temp;

        StackIterator(Node<T> f) {
            this.temp = f;
        }

        @Override
        public boolean hasNext() {
            return temp != null;
        }

        @Override
        public T next() {
            if (this.hasNext()) {
                Node<T> res = temp;
                temp = temp.next;
                return res.item;
            }
            return null;
        }

        @Override
        public void remove() {
            throw new UnsupportedOperationException();
        }
    }

    @Override
    public Iterator<T> iterator() {
        return new StackIterator<T>(first);
    }

    private static class Node<T> {
        private T item;
        private Node<T> next;
    }

    public Stack() {
        first = null;
        n = 0;
    }

    public void print() {
        Iterator<T> it = this.iterator();
        while (it.hasNext()) {
            T nextValue = it.next();
            System.out.println(nextValue);
        }
        System.out.println("FOREACH");
        for (T nextValue : this) {
            System.out.println(nextValue);
        }
    }

    public boolean isEmpty() {
        return first == null;
    }

    public void push(T item) {
        Node<T> temp = new Node<>();
        temp.item = item;
        temp.next = first;
        first = temp;
        n++;
    }

    public T pop() {
        Node<T> temp = first;
        first = first.next;
        n--;
        return temp.item;
    }

    public T peek() {
        if (isEmpty())
            return first.item;
        return first.item;
    }

    public static void main(String[] args) {
        Stack<Integer> stk = new Stack<>();
        stk.push(1);
        stk.push(2);
        stk.push(3);
        stk.push(4);
        stk.push(5);
        stk.push(6);
        stk.push(7);
        stk.print();
        // System.out.println(stk.pop());
        // System.out.println(stk.peek());
        // System.out.println(stk.pop());
        // System.out.println(stk.pop());
        // System.out.println(stk.pop());
        // System.out.println(stk.pop());
        // System.out.println(stk.pop());

    }
}