class Static1 {
    static int count;
    int var;
    final int var_1 = 10;
    static void method1() {
        StringBuilder a = new StringBuilder();
        System.out.println(++count);
    }
    void method2() {
        System.out.println(count);
        System.out.println(var);
    }

}

public class Demo {
    public static void main(String[] args) {
        Static1.method1();
        Static1 s = new Static1();
        // s.method1();
        // Static1.method2();
        s.method2();
    }
}

final class FinalClass {
    int i;
    public int Ok() {
        
    }
}