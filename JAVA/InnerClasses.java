class Outer {
    static int x1;
    int x2;
    private int x3;

    class Inner {
        int y;

        void display() {
            System.out.println(x1 + " " + y);
        }
    }

    void print() {
        System.out.println(x1 + " " + x2 + " " + x3);
    }
}

public class InnerClasses {
    public static void main(String[] args) {
        Outer obj = new Outer();
        obj.x1 = 1;
        obj.x2 = 2;
        // obj.x3 = 3;
        obj.print();
        Outer.Inner in = new Outer().new Inner();
        // in.x2 = 5;
        in.y = 4;
        in.display();
    }
}
