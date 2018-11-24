import java.util.LinkedList;

class Graph {
    LinkedList<Integer>[] vertices;
    boolean[] visited;
    int v;

    Graph(int v) {
        this.vertices = new LinkedList[v];
        this.v = v;
        for (int i = 0; i < v; i++)
            this.vertices[i] = new LinkedList<>();
        this.visited = new boolean[v];
    }

    public void addEdge(int v1, int v2) {
        this.vertices[v1].add(v2);
        this.vertices[v2].add(v1);
    }

    public void printGraph() {
        for (int i = 0; i < this.v; i++) {
            System.out.println("Adjacency list of vertex " + i);
            System.out.print("head");
            for (Integer j : this.vertices[i]) {
                System.out.print(" -> " + j);
            }
            System.out.println("\n");
        }
    }

    private void dfsRecursive(int vertex) {
        // System.out.println(vertex);
        this.visited[vertex] = true;
        if(this.vertices[vertex].size()==1)
            System.out.println(vertex);
        for (int i = 0; i < this.vertices[vertex].size(); i++) {
            int v = this.vertices[vertex].get(i);
            if (!this.visited[v])
                dfsRecursive(v);
        }
    }

    public void leaves(int subtreeNode) {
        dfsRecursive(subtreeNode);
    }
}

public class LeavesOfSubtree {
    public static void main(String[] args) {
        Graph obj = new Graph(10);
        obj.addEdge(0, 1);
        obj.addEdge(0, 6);
        obj.addEdge(1, 2);
        obj.addEdge(1, 3);
        obj.addEdge(1, 4);
        obj.addEdge(3, 5);
        obj.addEdge(6, 7);
        obj.addEdge(6, 8);
        obj.addEdge(6, 9);

        obj.leaves(1);

        // obj.printGraph();
    }
}