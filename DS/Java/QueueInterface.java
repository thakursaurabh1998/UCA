public interface QueueInterface {
    public void enqueue(int e);

    public int dequeue();

    public boolean isEmpty();

    public boolean isFull();

    public void printQueue();
}