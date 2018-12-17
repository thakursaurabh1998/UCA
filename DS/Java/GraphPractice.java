import java.util.*;

public class GraphPractice {
  ArrayList<LinkedList<Integer>> arrlist;
  int v;

  GraphPractice(int v) {
    this.v = v;
    this.arrlist = new ArrayList<LinkedList<Integer>>();
    for (int i = 0; i < v; i++)
      this.arrlist.add(new LinkedList<>());
  }

  public void connect(int p, int q) {
    this.arrlist.get(p).add(q);
    if (p != q) {
      this.arrlist.get(q).add(p);
    }
  }

  public void bfs(int from) {
    Queue<Integer> q = new LinkedList<>();
    boolean[] visited = new boolean[this.v];
    q.add(from);
    visited[from] = true;
    q.add(-1);
    while (!q.isEmpty()) {
      int temp = q.remove();
      if (temp == -1 && !q.isEmpty()) {
        q.add(-1);
        System.out.println();
      } else if (temp != -1) {
        System.out.print(temp + " ");
        for (int i : this.arrlist.get(temp)) {
          if (!visited[i]) {
            q.add(i);
            visited[i] = true;
          }
        }
      }
    }
  }

  private void dfsR(int from, boolean[] v) {
    v[from] = true;
    System.out.print(from + " ");
    for (int i : this.arrlist.get(from)) {
      if (!v[i]) {
        dfsR(i, v);
      }
    }
  }

  public void dfs(int from) {
    boolean[] visited = new boolean[this.v];
    dfsR(from, visited);
  }

  public int componentsCount() {
    boolean[] visited = new boolean[this.v];
    int count = 0;
    for (int i = 0; i < this.v; i++) {
      if (!visited[i]) {
        dfsR(i, visited);
        count++;
      }
    }
    return count;
  }

  private boolean dfsCycle(int from, int parent, boolean[] v) {
    v[from] = true;
    boolean flag = false;
    for (int i : this.arrlist.get(from)) {
      if (!v[i]) {
        flag |= dfsCycle(i, from, v);
      } else if (v[i] && i != parent) {
        return true;
      }
    }
    return flag;
  }

  public boolean isCycle() {
    boolean[] visited = new boolean[this.v];
    return dfsCycle(0, -1, visited);
  }

  public static void main(String[] args) {
    GraphPractice g = new GraphPractice(7);
    // g.connect(0, 1);
    // g.connect(1, 2);
    // g.connect(1, 3);
    // g.connect(3, 0);
    // g.connect(4, 5);
    g.connect(0, 1);
    g.connect(0, 2);
    g.connect(1, 3);
    g.connect(1, 4);
    g.connect(2, 4);
    g.connect(3, 4);
    g.connect(3, 5);
    g.connect(4, 5);
    // g.bfs(3);
    // g.dfs(0);
    // System.out.print("\n" + g.componentsCount());
    System.out.println(g.isCycle());
  }
}