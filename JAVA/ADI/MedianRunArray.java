import java.util.Arrays;
import java.util.Collections;
import java.util.PriorityQueue;

public class MedianRunArray {
    PriorityQueue<Integer> min;
    PriorityQueue<Integer> max;

    MedianRunArray() {
        min = new PriorityQueue<>();
        max = new PriorityQueue<>(Collections.reverseOrder());
    }

    public void insert(int key) {
        if (max.size() == 0 || max.peek() >= key) {
            max.add(key);
        } else {
            min.add(key);
        }
        int minsize = min.size();
        int maxsize = max.size();
        if (Math.abs(minsize - maxsize) > 1) {
            if (minsize > maxsize)
                max.add(min.remove());
            else
                min.add(max.remove());
        }
    }

    public Double median() {
        int minsize = min.size();
        int maxsize = max.size();
        if (minsize == maxsize)
            return (min.peek() + max.peek()) / 2.0;
        if (minsize > maxsize)
            return min.peek() / 1.0;
        return max.peek() / 1.0;
    }

    public double[] runningMedian(int[] a) {
        double dbl[] = new double[a.length];
        int p = 0;
        for (int i = 0; i < a.length; i++) {
            this.insert(a[i]);
            dbl[p++] = this.median();
        }
        return dbl;
    }

    public static void main(String[] args) {
        MedianRunArray m = new MedianRunArray();
        int[] array = new int[] { 94455, 20555, 20535, 53125, 73634, 148, 63772, 17738, 62995 };
        double[] answer = new double[] { 94455.0, 57505.0, 20555.0, 36840.0, 53125.0, 36840.0, 53125.0, 36840.0, 53125.0 };
        System.out.println(Arrays.toString(m.runningMedian(array)));
        System.out.println(Arrays.toString(answer));
    }
}