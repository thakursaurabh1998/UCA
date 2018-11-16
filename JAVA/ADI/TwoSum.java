import java.util.*;

public class TwoSum {
    public static ArrayList<Integer> solution(List<Integer> arr, int n) {
        HashMap<Integer, ArrayList<Integer>> ss = new HashMap<>();
        for (int i = 0; i < arr.size(); i++) {
            if (ss.get(arr.get(i)) == null) {
                ss.put(arr.get(i), new ArrayList<>());
                ss.get(arr.get(i)).add(i);
            } else {
                ss.get(arr.get(i)).add(i);
            }
        }
        Set<Integer> a = ss.keySet();
        ArrayList<ArrayList<Integer>> r = new ArrayList<>();
        for (int i = 0; i < arr.size(); i++) {
            ArrayList<Integer> res = new ArrayList<>();
            int p = arr.get(i);
            int q = n - p;
            if (p == q && ss.get(p).size() > 1) {
                res.add(ss.get(p).get(0) + 1);
                res.add(ss.get(q).get(1) + 1);
                Collections.sort(res);
                r.add(res);
            } else if (ss.get(q) != null && p != q ) {
                res.add(ss.get(p).get(0) + 1);
                res.add(ss.get(q).get(0) + 1);
                Collections.sort(res);
                System.out.println("ok" + res.toString() + " " + arr.get(res.get(0) - 1) + " " + arr.get(res.get(1) - 1));
                r.add(res);
                // ss.get(p)
            }
        }
        Collections.sort(r, new Comparator<ArrayList<Integer>>() {
            @Override
            public int compare(ArrayList<Integer> o1, ArrayList<Integer> o2) {
                return o1.get(1).compareTo(o2.get(1));
            }
        });
        // System.out.println(r.toString());
        if (r.isEmpty())
            return new ArrayList<>();
        return r.get(0);
    }

    public static void main(String[] args) {
        Integer[] arr = new Integer[] {-7, -6, 7, 10, -1, -9, -8, 7, -5, -4, -4, 1, 6, 5, 7, 1, 3, -2, 9, -8, -6, -9, -4, -5};
        // Integer[] arr = new Integer[] { 1, 2, 7, 8};
        List<Integer> a = Arrays.asList(arr);
        for (Integer i : solution(a, -2)) {
            System.out.println(i);
        }
    }
}