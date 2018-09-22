public class MinPriorityQueue {
    private int[] arr;
    private int capacity;
    private int tail;

    MinPriorityQueue(int c) {
        this.capacity = c + 1;
        this.tail = 1;
        this.arr = new int[c + 1];
    }

    public int delete() {
        int min = arr[1];
        arr[1] = arr[tail-1];
        int k = 1;
        int large;
        while ((arr[k] > arr[2 * k] || arr[k] > arr[2 * (k + 1)]) && k <= 2 * (k + 1)) {
            if (arr[k] > arr[2 * k]) {
                large = arr[k];
                arr[k] = arr[2 * k];
                arr[2 * k] = large;
                k = 2 * k;
            } else if (arr[k] > arr[2 * (k + 1)]) {
                large = arr[k];
                arr[k] = arr[2 * (k + 1)];
                arr[2 * (k + 1)] = large;
                k = 2 * (k + 1);
            }
        }
        this.tail--;
        return min;
    }

    public void insert(int data) {
        this.arr[this.tail] = data;
        int k = this.tail;
        while (k > 1) {
            if (arr[k] < arr[k / 2]) {
                int temp = arr[k];
                arr[k] = arr[k / 2];
                arr[k / 2] = temp;
            }
            k = k / 2;
        }
        this.tail++;
    }

    public int peek() {
        return this.arr[1];
    }

    public boolean isEmpty() {
        if (1 == this.tail)
            return true;

        return false;
    }

    public boolean isFull() {
        if (this.tail == this.capacity)
            return true;

        return false;
    }

    public void print() {
        for (int i : arr)
            System.out.print(i + " ");
        System.out.println();
    }

    public static void main(String[] args) {
        MinPriorityQueue q = new MinPriorityQueue(7);
        q.insert(2);
        q.insert(5);
        q.insert(4);
        q.insert(1);
        q.insert(7);
        q.insert(6);
        q.insert(3);
        q.print();
        q.delete();
        q.print();
    }
}