import java.util.Collections;
import java.util.PriorityQueue;

public class MedianRunArray {
    PriorityQueue<Integer> min;
    PriorityQueue<Integer> max;

    MedianRunArray() {
        min = new PriorityQueue<>();
        max = new PriorityQueue<>(Collections.reverseOrder());
    }

    void insert(int key) {
        min.add(key);
        int diff = min.size() - max.size();
        if (diff > 1)
            max.add(min.remove());
    }

    Integer median() {
        if (max.size() == min.size())
            return (max.peek() + min.peek()) / 2;

        return max.size() > min.size() ? max.peek() : min.peek();
    }

    public static void main(String[] args) {
        MedianRunArray m = new MedianRunArray();
        m.insert(10);
        System.out.println(m.median());
        m.insert(7);
        System.out.println(m.median());
        m.insert(4);
        System.out.println(m.median());
        m.insert(9);
        System.out.println(m.median());
        m.insert(2);
        System.out.println(m.median());
        m.insert(3);
        System.out.println(m.median());
        m.insert(11);
        System.out.println(m.median());
        m.insert(17);
        System.out.println(m.median());
        m.insert(14);
        System.out.println(m.median());
    }
}