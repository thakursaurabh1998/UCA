import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;

// graph created with adjacency list
public class Graph {
    ArrayList<LinkedList<Integer>> vertices;
    int v;

    Graph(int v) {
        this.vertices = new ArrayList<>();
        this.v = v;
        for (int i = 0; i < v; i++)
            this.vertices.add(new LinkedList<>());
    }

    public void addEdge(int v1, int v2) {
        this.vertices.get(v1).add(v2);
        this.vertices.get(v2).add(v1);
    }

    public void printGraph() {
        for (int i = 0; i < this.v; i++) {
            System.out.println("Adjacency list of vertex " + i);
            System.out.print("head");
            for (Integer j : this.vertices.get(i)) {
                System.out.print(" -> " + j);
            }
            System.out.println("\n");
        }
    }

    private void dfsRecursive(int vertex, boolean[] visited) {
        System.out.println(vertex);
        visited[vertex] = true;
        for (int i = 0; i < this.vertices.get(vertex).size(); i++) {
            int v = this.vertices.get(vertex).get(i);
            if (!visited[v])
                dfsRecursive(v, visited);
        }
    }

    public void dfs() {
        boolean[] visited = new boolean[this.v];
        dfsRecursive(0, visited);
    }

    public void bfs() {
        Queue<Integer> q = new LinkedList<>();
        boolean[] visited = new boolean[this.v];
        q.add(0);
        visited[0] = true;
        while (!q.isEmpty()) {
            int top = q.remove();
            System.out.println(top);
            for (Integer i : vertices.get(top)) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.add(i);
                }
            }
        }
    }

    public static void main(String[] args) {
        Graph obj = new Graph(6);
        // obj.addEdge(0, 1);
        // obj.addEdge(0, 4);
        // obj.addEdge(1, 2);
        // obj.addEdge(1, 3);
        // obj.addEdge(1, 4);
        // obj.addEdge(2, 3);
        // obj.addEdge(3, 4);

        obj.addEdge(0, 1);
        obj.addEdge(0, 2);
        obj.addEdge(1, 3);
        obj.addEdge(1, 4);
        obj.addEdge(2, 4);
        obj.addEdge(3, 4);
        obj.addEdge(3, 5);
        obj.addEdge(4, 5);

        obj.bfs();

        // obj.dfs();

        // obj.printGraph();
    }
}