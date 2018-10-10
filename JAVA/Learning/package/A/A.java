package A;

interface I1 {
    public void foo4();
}

interface I2 extends I1 {
    public void foo5();
}

public class A implements I2 {
    protected void foo() {
        System.out.println("In A");
    }

    public void foo1() {
        System.out.println("In A");
    }

    private void foo2() {
        System.out.println("In A");
    }

    void foo3() {
        System.out.println("In A");
    }

    public void foo4() {
        System.out.println("In A");
    }

    public void foo5() {
        System.out.println("In A");
    }
}