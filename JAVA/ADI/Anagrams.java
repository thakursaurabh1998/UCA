import java.util.*;

public class Anagrams {
    static ArrayList<ArrayList<Integer>> solution(String[] arr) {
        ArrayList<ArrayList<Integer>> res = new ArrayList<>();
        HashSet<Character> charset = new HashSet<>();
        HashMap<HashSet<Character>, ArrayList<Integer>> m = new HashMap<>();
        ArrayList<Integer> temp;

        for (int i = 0; i < arr.length; i++) {
            charset = new HashSet<>();
            for (int j = 0; j < arr[i].length(); j++)
                charset.add(arr[i].charAt(j));
            if (m.get(charset) == null) {
                temp = new ArrayList<Integer>();
                temp.add(i + 1);
                m.put(charset, temp);
            } else {
                m.get(charset).add(i + 1);
            }
        }

        for (String i : arr) {
            for (int j = 0; j < i.length(); j++) {
                charset.add(i.charAt(j));
            }
            System.out.println(charset.toString());
        }

        // System.out.println(m.toString());

        for (ArrayList<Integer> i : m.values())
            res.add(i);
        return res;
    }

    public static void main(String[] args) {
        String arr[] = new String[] {
                "abbbaabbbabbbbabababbbbbbbaabaaabbaaababbabbabbaababbbaaabbabaabbaabbabbbbbababbbababbbbaabababba",
                "abaaabbbabaaabbbbabaabbabaaaababbbbabbbaaaabaababbbbaaaabbbaaaabaabbaaabbaabaaabbabbaaaababbabbaa",
                "babbabbaaabbbbabaaaabaabaabbbabaabaaabbbbbbabbabababbbabaabaabbaabaabaabbaabbbabaabbbabaaaabbbbab",
                "bbbabaaabaaaaabaabaaaaaaabbabaaaabbababbabbabbaabbabaaabaabbbabbaabaabaabaaaabbabbabaaababbaababb",
                "abbbbbbbbbbbbabaabbbbabababaabaabbbababbabbabaaaabaabbabbaaabbaaaabbaabbbbbaaaabaaaaababababaabab",
                "aabbbbaaabbaabbbbabbbbbaabbababbbbababbbabaabbbbbbababaaaabbbabaabbbbabbbababbbaaabbabaaaabaaaaba",
                "abbaaababbbabbbbabababbbababbbaaaaabbbbbbaaaabbaaabbbbbbabbabbabbaabbbbaabaabbababbbaabbbaababbaa",
                "aabaaabaaaaaabbbbaabbabaaaabbaababaaabbabbaaaaababaaabaabbbabbababaabababbaabaababbaabbabbbaaabbb" };
        // System.out.println(solution(arr).toString());
    //     char[] abc = new char[] { 'a', 'b', 'c' };
    //     char[] bca = new char[] { 'a', 'b', 'c' };
    //     System.out.println(Arrays.compare(abc, bca) == 0 ? "EQUAL" : "NOT EQUAL");
    // }
}