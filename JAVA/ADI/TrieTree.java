import java.util.HashMap;

public class TrieTree {
    HashMap<Character, TrieTree> next;
    boolean isEndOfWord;

    TrieTree() {
        this.next = new HashMap<>();
        this.isEndOfWord = false;
    }

    public void insert(String str) {
        TrieTree curr = this;
        for (int i = 0; i < str.length(); i++) {
            if (curr.next.get(str.charAt(i)) == null) {
                curr.next.put(str.charAt(i), new TrieTree());
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

    // Change this to map
    
    boolean delete(String str, int index) {
        if (index == str.length()) {
            if (!this.isEndOfWord)
                return false;
            this.isEndOfWord = true;
            for (int i = 0; i < 26; i++)
                if (this.arr[i] != null)
                    return false;
            return true;
        }
        int j = str.charAt(index) - 'a';
        if (this.arr[j] == null)
            return false;
        boolean var = this.arr[j].delete(str, index + 1);
        if (var) {
            this.arr[j] = null;
            if (this.isEndOfWord)
                return false;
            else {
                for (int i = 0; i < 26; i++)
                    if (this.arr[i] != null)
                        return false;
                return true;
            }
        }
        return true;
    }

    public static void main(String[] args) {
        TrieTree abc = new TrieTree();
        abc.insert("hello");
        abc.insert("hel");
        System.out.println(abc.search("hello"));
    }
}