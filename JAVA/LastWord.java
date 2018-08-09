public class LastWord {
    public static void main(String[] args) {
        String str = "Hello this is Saurabh";
        String wordsArr[] = str.split(" ");
        System.out.println(wordsArr[wordsArr.length-1].length());
    }
}
