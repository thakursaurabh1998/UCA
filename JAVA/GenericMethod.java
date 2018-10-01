public class GenericMethod {
    public static <T> void swap(T[] arr, Integer i, Integer j) {
        T temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    public static void main(String[] args) {
        Integer[] arr = {1,2,3,4,5,6,7};
        swap(arr, 3, 5);
        for(Integer i: arr)
            System.out.println(i);
    }
}