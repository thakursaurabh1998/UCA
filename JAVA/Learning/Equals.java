public class Equals {
    int x;
    int y;

    Equals(int x, int y) {
        this.x = x;
        this.y = y;
    }

    public boolean equals(Object o) {
        Equals a = (Equals) o;
        return this.x == a.x && this.y == a.y;
    }

    public int hashCode(){
        
    }

    public static void main(String[] args) {
        Equals eq = new Equals(2, 3);
        Equals eq2 = new Equals(2, 4);
        Equals eq3 = new Equals(2, 3);
        System.out.println(eq.equals(eq2));
        System.out.println(eq.equals(eq3));
    }
}