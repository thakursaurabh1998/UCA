import java.util.ArrayList;

public class UnionFind {
    private int[] id;
    private int N;

    public UnionFind(int N) {
        this.N = N;
        this.id = new int[N];

        for (int i = 0; i < N; i++)
            this.id[i] = i;
    }

    public boolean isConnected(int p, int q) {
        return this.id[p] == this.id[q];
    }

    public UnionFind union(int p, int q) {
        for (int i = 0; i < this.N; i++)
            if (this.id[i] == p)
                this.id[i] = this.id[q];

        return this;
    }

    public void printArr() {
        for (int i = 0; i < this.N; i++)
            System.out.print(this.id[i] + " ");
        System.out.println();
    }

    public static void main(String[] args) {
        UnionFind a = new UnionFind(10);
        a.union(2, 1).printArr();
        a.union(4, 3).printArr();
        a.union(8, 4).printArr();
        a.union(9, 3).printArr();
        a.union(6, 5).printArr();
        a.union(5, 2).printArr();
        System.out.println(a.isConnected(8, 9));
    }
}