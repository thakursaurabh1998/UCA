public class Swap {
    static int swapMethodNew(int x, int y) {
        return x;
    }

    public static void main(String[] args) {
        int x = 2;
        int y = 3;

        SwapObject s1 = new SwapObject(x,y);
        SwapObject s2 = new SwapObject(10, 20);

        s1.swap(s1, s2);
        System.out.println("S1: " + s1.a + " " + s1.b);
    }
}

class SwapObject {
    int a, b;

    SwapObject(int a, int b) {
        this.a = a;
        this.b = b;
    }

    void swap(SwapObject s1, SwapObject s2) {
        SwapObject temp = s1;
        s1 = s2;
        s2 = temp;
    }
}