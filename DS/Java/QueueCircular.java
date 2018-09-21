public class QueueCircular implements QueueInterface {

    private int capacity;
    private int size;
    private int front;
    private int rear;
    private int[] a;

    QueueCircular(int c) {
        this.capacity = c;
        this.size = this.front = 0;
        this.rear = -1;
        this.a = new int[c];
    }

    @Override
    public void enqueue(int data) {
        if (this.isFull())
            throw new RuntimeException("Overflow");
        this.rear = (this.rear + 1) % this.capacity;
        this.a[this.rear] = data;
        this.size++;
        // System.out.println("Front: " + this.front + " Rear: " + this.rear + " Size: "
        // + this.size);
    }

    @Override
    public int dequeue() {
        if (isEmpty())
            throw new RuntimeException("Underflow");
        int data = this.a[this.front];
        this.front = (this.front + 1) % this.capacity;
        this.size--;
        return data;
    }

    @Override
    public boolean isEmpty() {
        if (this.size == 0)
            return true;
        return false;
    }

    @Override
    public boolean isFull() {
        if (this.size == this.capacity)
            return true;
        return false;
    }

    @Override
    public void printQueue() {
        System.out.println("Front: " + this.front + " Rear: " + this.rear + " Size: " + this.size);
        // for (int i = 0; i < this.capacity; i++)
        // System.out.println(this.a[i]);
        if (this.size == 0) {
            System.out.println("Queue is empty");
            return;
        }
        for(int i=0;i<this.capacity;i++)
            System.out.print(this.a[i] + " ");
        int i = this.front;
        int p = 0;
        // if (this.rear >= this.front) {
        while ((this.front + p++) % this.capacity <= this.rear) {
            System.out.println(this.a[i]);
            i = (i + 1) % this.capacity;
        }
        // }else

        // {
        // for (int i = this.front; i <= this.rear; i = (i + 1) % this.capacity)
        // System.out.println(this.a[i]);
        // }System.out.println();
    }

    public static void main(String[] args) {
        QueueCircular q = new QueueCircular(5);
        System.out.println(q.isEmpty());
        try {
            q.enqueue(1);
            q.enqueue(2);
            q.enqueue(3);
            // q.printQueue();
            // q.enqueue(4);
            // q.enqueue(5);
            // System.out.println(q.dequeue());
            // System.out.println(q.dequeue());
            // System.out.println(q.dequeue());
            q.dequeue();
            q.dequeue();
            q.dequeue();
            q.printQueue();
            q.enqueue(6);
            q.enqueue(7);
            q.enqueue(8);
            q.enqueue(9);
            q.enqueue(10);
            q.printQueue();
            // System.out.println(q.dequeue());
            // System.out.println(q.dequeue());
            // System.out.println(q.dequeue());
            // System.out.println(q.dequeue());
            // System.out.println(q.dequeue());

        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
        System.out.println(q.isFull());
    }
}