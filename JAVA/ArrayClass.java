import java.util.Arrays;
import java.util.Scanner;

public class ArrayClass {
    public static void main(String[] args) {
        int[] arr = { 4, 3, 5, 1, 2, 6, 10, 7, 9, 8 };
        System.out.println(arr.length);
        System.out.println(Arrays.toString(arr));
        Arrays.sort(arr, 1, 5);
        System.out.println(Arrays.toString(arr));
        Arrays.sort(arr);
        System.out.println(Arrays.toString(arr));
        System.out.println(Arrays.binarySearch(arr, 3));
        int[] newarr = Arrays.copyOf(arr, 4);
        System.out.println(Arrays.toString(newarr));
        newarr = Arrays.copyOfRange(arr, 4, 8);
        System.out.println(Arrays.toString(newarr));

        double x, y;
        Scanner reader = new Scanner(System.in);
        x = reader.nextDouble();
        y = reader.nextDouble();
        System.out.println(Math.abs(x));
        System.out.println(Math.floor(x));
        System.out.println(Math.ceil(x));
        System.out.println(Math.pow(x, 2) + Math.pow(y, 2));
        System.out.println(Math.max(x, y));
        System.out.println(Math.min(x, y));
        System.out.println(Math.random());
    }
}
