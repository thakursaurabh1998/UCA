import java.util.PriorityQueue;
import java.util.ArrayList;
import java.util.LinkedList;

class Solution {
    ArrayList<LinkedList<Integer>> a;
    int K;

    Solution(ArrayList<LinkedList<Integer>> arr, int n) {
        a = arr;
        K = n;
    }

    public LinkedList<Integer> solution() {
        PriorityQueue<Integer> pq = new PriorityQueue<>();
        LinkedList<Integer> res = new LinkedList<>();

        for (LinkedList<Integer> p : a)
            for(Integer i: p)
                pq.add(i);
        
        while(!pq.isEmpty())
            res.add(pq.remove());
        
        return res;
    }
}

public class MergeKSortedLL {
    public static void main(String[] args) {
        LinkedList<Integer> a = new LinkedList<>();
        LinkedList<Integer> b = new LinkedList<>();
        LinkedList<Integer> c = new LinkedList<>();
        ArrayList<LinkedList<Integer>> arr = new ArrayList<>();
        a.add(1);
        a.add(10);
        a.add(20);
        b.add(4);
        b.add(11);
        b.add(13);
        c.add(3);
        c.add(8);
        c.add(9);
        arr.add(a);
        arr.add(b);
        arr.add(c);
        System.out.println(new Solution(arr, 3).solution().toString());
    }
}