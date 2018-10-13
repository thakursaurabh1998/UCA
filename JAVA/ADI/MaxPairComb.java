import java.util.Arrays;
import java.util.LinkedList;
import java.util.PriorityQueue;

class Solution {
    private int a[];
    private int b[];
    private int N;
    int pp;

    Solution(int[] ac, int[] bc, int n) {
        this.N = n;
        Arrays.sort(ac);
        Arrays.sort(bc);
        this.a = ac;
        this.b = bc;
        pp = 1;
    }

    public void solution() {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        int j = a.length - 1;
        boolean flag = true;
        while (flag) {
            for (int i = b.length - 1; i >= 0; i--) {
                int sum = a[j] + b[i];
                if (pq.size() < N ) {
                    pq.add(sum);
                } else if(pq.size() == N && sum >= pq.peek()) {
                    pq.add(sum);
                    pq.remove();
                } else {
                    flag = false;
                    break;
                }
                System.out.println("Runcheck: "+ pp++);
            }
            j--;
        }
        System.out.println(pq.toString());
    }
}

public class MaxPairComb {
    public static void main(String[] args) {
        int N = 4;
        int[] a = new int[] { 1, 4, 2, 3, 5, 6, 7 };
        int[] b = new int[] { 2, 5, 1, 6 };
        Solution obj = new Solution(a, b, N);
        obj.solution();
    }
}