public class GenericClass<T, U> {
    private T tv;
    private U uv;

    public GenericClass(T t, U u) {
        tv = t;
        uv = u;
    }

    public T getT() {
        return tv;
    }

    public U getU() {
        return uv;
    }

    public static void main(String[] args) {
        int t = 123;
        char u = 's';
        GenericClass<Integer, Character> obj = new GenericClass<>(t, u);
        System.out.println(obj.getT());
        System.out.println(obj.getU());
    }
}