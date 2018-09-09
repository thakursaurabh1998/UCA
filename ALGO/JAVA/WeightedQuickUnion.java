public class WeightedQuickUnion {
    private int[] id;
    private int[] size;
    private int N;

    int findSuperRoot(int p) {
        while (this.id[p] != p)
            p = this.id[p];
        return p;
    }

    WeightedQuickUnion(int N) {
        this.N = N;
        this.id = new int[N];
        this.size = new int[N];

        for (int i = 0; i < this.N; i++) {
            this.id[i] = i;
            this.size[i] = 1;
        }
    }

    WeightedQuickUnion union(int p, int q) {
        int rootp = this.findSuperRoot(p);
        int rootq = this.findSuperRoot(q);
        if (this.size[rootp] > this.size[rootq]) {
            this.id[rootq] = rootp;
            this.size[rootp] += this.size[rootq];
        } else {
            this.id[rootp] = rootq;
            this.size[rootq] += this.size[rootp];
        }

        return this;
    }

    boolean isConnected(int p, int q) {
        return this.findSuperRoot(p) == this.findSuperRoot(q);
    }

    void printGraph() {
        System.out.print("Graph:\t");
        for (int i : this.id)
            System.out.print(i + " ");
        System.out.print("\nSize:\t");
        for (int i : this.size)
            System.out.print(i + " ");
        System.out.println();
    }

    public static void main(String[] args) {
        WeightedQuickUnion a = new WeightedQuickUnion(10);
        a.union(2, 0).printGraph();
        a.union(2, 1).printGraph();
        a.union(3, 2).printGraph();
        a.union(4, 5).printGraph();
        a.union(4, 6).printGraph();
        a.union(4, 0).printGraph();
        System.out.println(a.isConnected(2, 9));
    }
}