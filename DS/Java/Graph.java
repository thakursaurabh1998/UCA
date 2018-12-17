// import java.util.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Iterator;

class Bag implements Iterable<Integer> {
    private Node first;
    private Node last;

    private class Node {
        int data;
        Node next;

        Node(int d) {
            this.data = d;
            this.next = null;
        }
    }

    Bag() {
        this.first = this.last = null;
    }

    public void enque(int i) {
        if (this.first == null) {
            this.first = new Node(i);
            this.last = this.first;
        } else {
            this.last.next = new Node(i);
            this.last = this.last.next;
        }
    }

    public int getFirstData() {
        return this.first.data;
    }

    public String toString() {
        return "Hello";
    }

    public Iterator<Integer> iterator() {
        return new Iterator<Integer>() {
            private Node current = first;

            @Override
            public boolean hasNext() {
                return current != null;
            }

            @Override
            public Integer next() {
                int temp = current.data;
                current = current.next;
                return temp;
            }

            @Override
            public void remove() {
                throw new UnsupportedOperationException("no changes allowed");
            }
        };
    }
}

public class Graph {
    int v;
    int e;
    private final int V;
    Bag[] adj;

    Graph(int v) {
        this.V = v;
        this.adj = new Bag[v];
        for (Bag i : this.adj) {
            i = new Bag();
        }
        this.v = v;
        this.e = 0;
    }

    public void addEdge(int v, int w) {
        if (this.adj[v] == null)
            this.adj[v] = new Bag();
        this.adj[v].enque(w);
        if (v != w) {
            if (this.adj[w] == null)
                this.adj[w] = new Bag();
            adj[w].enque(v);
        }
        this.e++;
    }

    public Iterable<Integer> adjacent(int v) {
        return this.adj[v];
    }

    public int degree(int v) {
        int count = 0;
        for (int w : this.adjacent(v))
            count++;
        return count;
    }

    public boolean hasSelfLoop() {
        for (int i = 0; i < this.V; i++) {
            for (int j : this.adjacent(i)) {
                if (j == i)
                    return true;
            }
        }
        return false;
    }

    private void dfsCycle(boolean[] visited, int v, int parent) {
        visited[v] = true;
        for (int i : this.adjacent(v)) {
            if (!visited[i])
                dfsCycle(visited, i, i);
            else if (visited[i] && i != parent)
                cycle = true;
        }
    }

    static boolean cycle = false;

    // NOTE: check if there is a single node 
    public boolean hasCycle() {
        boolean[] visited = new boolean[this.V];
        for (Bag i : this.adj) {
            dfsCycle(visited, i.getFirstData(), -1);
        }
        return cycle;
    }

    private void dfsForConnectedComponents(boolean[] visited, int v) {
        visited[v] = true;
        for (int i : this.adjacent(v)) {
            if (!visited[i])
                dfsForConnectedComponents(visited, i);
        }
    }

    public int connectedComponents() {
        int count = 0;
        boolean[] visited = new boolean[this.V];
        for (Bag i : this.adj) {
            if (!visited[i.getFirstData()]) {
                count++;
                dfsForConnectedComponents(visited, i.getFirstData());
            }
        }
        return count;
    }

    public void printGraph() {
        for (int i = 0; i < this.V; i++) {
            System.out.println("Adjacency list of vertex " + i);
            System.out.print("head");
            for (Integer j : this.adjacent(i)) {
                System.out.print(" -> " + j);
            }
            System.out.println("\n");
        }
    }

    public void bfs() {
        Queue<Integer> q = new LinkedList<>();
        boolean[] visited = new boolean[this.v];
        q.add(0);
        visited[0] = true;
        while (!q.isEmpty()) {
            int top = q.remove();
            System.out.println(top);
            for (int i : this.adjacent(top)) {
                if (!visited[i]) {
                    visited[i] = true;
                    q.add(i);
                }
            }
        }
    }

    public static void main(String[] args) {
        Graph g = new Graph(4);
        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        // g.addEdge(0, 0);
        // g.addEdge(0, 1);
        // g.addEdge(0, 2);
        // g.addEdge(0, 5);
        // g.addEdge(0, 6);
        // g.addEdge(5, 3);
        // g.addEdge(5, 4);
        // g.addEdge(3, 4);
        // g.addEdge(4, 6);
        // g.addEdge(7, 8);
        // g.addEdge(9, 10);
        // g.addEdge(9, 11);
        // g.addEdge(11, 12);
        // g.addEdge(9, 12);
        // System.out.println(g.hasSelfLoop());
        // System.out.println(g.connectedComponents());
        // System.out.println(g.hasCycle());
        g.bfs();
        // g.printGraph();
    }
}