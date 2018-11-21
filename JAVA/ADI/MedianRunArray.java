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
        if (max.size() == 0 || max.peek() >= key) {
            max.add(key);
        } else {
            min.add(key);
        }
        int diff = min.size() - max.size();
        if (diff > 1)
            max.add(min.remove());
        if (Math.abs(min.size() - max.size()) > 1) {
            if (min.size() > max.size())
                max.add(min.remove());
            else
                min.add(max.remove());
        }
    }

    Double median() {
        if (max.size() == min.size())
            return (max.peek() + min.peek()) / 2.0;
        return max.size() > min.size() ? max.peek() / 1.0 : min.peek() / 1.0;
    }

    public static void main(String[] args) {
        MedianRunArray m = new MedianRunArray();
        m.insert(94455);
        System.out.println(m.median());
        m.insert(20555);
        System.out.println(m.median());
        m.insert(20535);
        System.out.println(m.median());
    }
}