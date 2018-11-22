import java.util.ArrayList;
import java.util.HashSet;

public class ColorfulNumber {
    static int solution(int num) {
        HashSet<Integer> s = new HashSet<>();
        ArrayList<Integer> arr = new ArrayList<>();
        int digitCount = 0;
        while (num != 0) {
            arr.add(num % 10);
            num /= 10;
            digitCount++;
        }
        // System.out.println(arr.toString());
        // int n = (digitCount * (digitCount + 1)) / 2;
        int combination = 1;
        for (int i = 0; i < digitCount; i++) {
            for (int k = 0; k < digitCount - combination + 1; k++) {
                int prod = 1;
                for (int j = k; j < k + combination; j++) {
                    prod *= arr.get(j);
                }
                if (s.contains(prod))
                    return 0;
                s.add(prod);
            }
            combination++;
        }
        return 1;
    }

    public static void main(String[] args) {
        System.out.println(solution(99));
    }
}