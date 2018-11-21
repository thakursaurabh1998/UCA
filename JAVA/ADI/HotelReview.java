import java.util.Arrays;
import java.util.Comparator;

// package ADI;

class struct {
    int count;
    int index;

    struct(int i) {
        count = 0;
        index = i;
    }

    public String toString() {
        return "\ncount: " + count + "index: " + index;
    }
}

class CompareCount implements Comparator<struct> {
    public int compare(struct a, struct b) {
        if (a.count == b.count)
            return 0;
        else if (a.count > b.count)
            return -1;
        else
            return 1;
    }
}

public class HotelReview {
    HotelReview[] arr;
    boolean isEndOfWord;

    HotelReview() {
        this.arr = new HotelReview[26];
        for (int i = 0; i < 26; i++)
            this.arr[i] = null;
        this.isEndOfWord = false;
    }

    void insert(String str) {
        HotelReview root = this;
        for (int i = 0; i < str.length(); i++) {
            int j = str.charAt(i) - 'a';
            if (root.arr[j] == null)
                root.arr[j] = new HotelReview();
            root = root.arr[j];
        }
        root.isEndOfWord = true;
    }

    boolean search(String str, int index) {
        if (index == str.length())
            return this.isEndOfWord;
        int j = str.charAt(index) - 'a';
        if (this.arr[j] == null)
            return false;
        return this.arr[j].search(str, index + 1);
    }

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

    static void solution(String a, String[] b) {
        String[] res = a.split("_");
        HotelReview o = new HotelReview();
        for (String i : res)
            o.insert(i);
        struct[] st = new struct[b.length];
        for (int j = 0; j < b.length; j++) {
            String sp[] = b[j].split("_");
            st[j] = new struct(j);
            for (String p : sp) {
                if (o.search(p, 0))
                    st[j].count++;
            }
        }

        Arrays.sort(st, new CompareCount());

        for (struct i : st)
            System.out.println(i.count + " " + i.index);
        // System.out.println(st[2].count);
    }

    public static void main(String[] args) {
        String a = "cool_ice_wifi";
        String[] b = new String[] { "water_is_cool", "wifi", "cold_ice_drink", "cool_wifi_speed", "cool_ice_wifi_jaihind_cool" };
        solution(a, b);
        // HotelReview o = new HotelReview();
        // o.insert("hello");
        // o.insert("hell");
        // System.out.println(o.search("hell", 0));
    }
}