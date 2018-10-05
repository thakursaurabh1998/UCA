
/* Minimum Priority Queue
* It is a part of heap data structure
* A heap is a specific tree based data structure 
* in which all the nodes of tree are in a specific order. 
* that is the children are arranged in some
* respect of their parents, can either be greater
* or less than the parent. This makes it a min priority queue
* or max priority queue.
*/

// Functions: insert, delete, peek, isEmpty, print, heapSort, sink

public class MinPriorityQueue {
    private int[] heap;
    private int capacity;
    private int size;

    MinPriorityQueue(int c) {
        this.capacity = c;
        this.size = 0;
        this.heap = new int[c + 1];
    }

    public void insert(int key) {
        if (this.isFull())
            return;
        this.heap[this.size + 1] = key;
        int k = this.size + 1;
        while (k > 1) {
            if (this.heap[k] < this.heap[k / 2]) {
                int temp = this.heap[k];
                this.heap[k] = this.heap[k / 2];
                this.heap[k / 2] = temp;
            }
            k = k / 2;
        }
        this.size++;
    }

    public int peek() {
        return this.heap[1];
    }

    public boolean isEmpty() {
        if (0 == this.size)
            return true;
        return false;
    }

    public boolean isFull() {
        if (this.size == this.capacity)
            return true;
        return false;
    }

    public void print() {
        for (int i = 1; i <= this.capacity; i++)
            System.out.print(this.heap[i] + " ");
        System.out.println();
    }

    public void heapSort() {
        for (int i = 1; i < this.capacity; i++)
            this.delete();
    }

    private void sink() {
        int k = 1;
        while (2 * k <= this.size || 2 * k + 1 <= this.size) {
            int minIndex;
            if (this.heap[2 * k] >= this.heap[k]) {
                if (2 * k + 1 <= this.size && this.heap[2 * k + 1] >= this.heap[k]) {
                    break;
                } else if (2 * k + 1 > this.size) {
                    break;
                }
            }
            if (2 * k + 1 > this.size) {
                minIndex = this.heap[2 * k] < this.heap[k] ? 2 * k : k;
            } else {
                if (this.heap[k] > this.heap[2 * k] || this.heap[k] > this.heap[2 * k + 1]) {
                    minIndex = this.heap[2 * k] < this.heap[2 * k + 1] ? 2 * k : 2 * k + 1;
                } else {
                    minIndex = k;
                }
            }
            int temp = this.heap[k];
            this.heap[k] = this.heap[minIndex];
            this.heap[minIndex] = temp;
            k = minIndex;
        }
    }

    public int delete() {
        int min = this.heap[1];
        this.heap[1] = this.heap[this.size];
        this.heap[this.size] = min;
        this.size--;
        this.sink();
        return min;
    }

    public static void main(String[] args) {
        MinPriorityQueue q = new MinPriorityQueue(8);
        q.insert(5);
        q.insert(2);
        q.insert(4);
        q.insert(1);
        q.insert(7);
        q.insert(6);
        q.insert(3);
        q.insert(8);
        q.print(); // [ 1, 2, 3, 5, 7, 6, 4, 8 ]
        q.heapSort();
        q.print(); // [ 8, 7, 6, 5, 4, 3, 2, 1 ]
    }
}