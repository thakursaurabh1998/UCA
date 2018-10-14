import java.util.ArrayList;
import java.util.Queue;

class Solution {
    int[] a;
    int K;

    Solution(int[] arr, int k) {
        this.a = arr;
        this.K = k;
    }

    public int[] solution() {
        int[] res = new int[a.length - K + 1];
        
        return res;
    }
}

public class DistinctNumbersWindow {
    public static void main(String[] args) {
        int[] arr = new int[] { 1, 2, 1, 3, 4, 3 };
        int k = 3;
        System.out.println(new Solution(arr, k).solution().toString());
    }
}