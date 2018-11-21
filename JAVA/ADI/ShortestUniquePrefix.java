import java.util.Arrays;
import java.util.HashMap;

class TrieTree {
    HashMap<Character, TrieTree> next;
    HashMap<Character, Integer> count;
    boolean isEndOfWord;

    TrieTree() {
        this.next = new HashMap<>();
        this.count = new HashMap<>();
        this.isEndOfWord = false;
    }

    public void insert(String str) {
        TrieTree curr = this;
        for (int i = 0; i < str.length(); i++) {
            if (curr.next.get(str.charAt(i)) == null) {
                curr.next.put(str.charAt(i), new TrieTree());
                curr.count.put(str.charAt(i), 1);
            } else {
                curr.count.put(str.charAt(i), curr.count.get(str.charAt(i)) + 1);
            }
            curr = curr.next.get(str.charAt(i));
        }
        curr.isEndOfWord = true;
    }

    public int search(String str) {
        TrieTree curr = this;
        for (int i = 0; i < str.length(); i++) {
            if (curr.next.get(str.charAt(i)) == null) {
                return 0;
            }
            curr = curr.next.get(str.charAt(i));
        }
        if (curr.isEndOfWord)
            return 1;
        else
            return 0;
    }

    public String autofill(String str) {
        TrieTree curr = this;
        String temp = "";
        int prev = 0;
        for (int i = 0; i < str.length(); i++) {
            // System.out.println(curr.count.get(str.charAt(i)));
            if (curr.count.get(str.charAt(i)) == 1) {
                if (prev != 1)
                    temp += str.charAt(i);
                return temp;
            }
            temp += str.charAt(i);
            prev = curr.count.get(str.charAt(i));
            curr = curr.next.get(str.charAt(i));
        }
        return temp;
    }
}

public class ShortestUniquePrefix {
    public static void main(String[] args) {
        // String[] arr = new String[] { "zebra", "dog", "duck", "dot" };
        String[] arr = new String[] { "bearcat", "bert" };
        String[] fill = new String[arr.length];
        TrieTree t = new TrieTree();
        for (int i = 0; i < arr.length; i++) {
            t.insert(arr[i]);
        }
        for (int i = 0; i < arr.length; i++) {
            fill[i] = t.autofill(arr[i]);
        }
        System.out.println(Arrays.toString(fill));
    }
}