import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class Employee {
    int empid;
    String name;
    double salary;

    public Employee(int id, String name, double salary) {
        this.empid = id;
        this.name = name;
        this.salary = salary;
    }

    public String toString() {
        return "ID: " + this.empid + "\nName: " + this.name + "\nSalary: " + this.salary;
    }

    public static void main(String[] args) {
        Employee[] arr = new Employee[3];
        arr[0] = new Employee(1, "Saurabh", 5464);
        arr[1] = new Employee(2, "John", 43785);
        arr[2] = new Employee(3, "Dan", 3434);
        System.out.println(Arrays.toString(arr));
        Arrays.sort(arr, new CompareSalary());
        // System.out.println(Arrays.toString(arr));
        System.out.println(Arrays.toString(arr));
    }
}

class CompareName implements Comparator<Employee> {
    public int compare(Employee e1, Employee e2) {
        return e1.name.compareTo(e2.name);
    }
}

class CompareId implements Comparator<Employee> {
    public int compare(Employee e1, Employee e2) {
        if (e1.empid == e2.empid)
            return 0;
        else if (e1.empid > e2.empid)
            return 1;
        else
            return -1;
    }
}

class CompareSalary implements Comparator<Employee> {
    public int compare(Employee e1, Employee e2) {
        if (e1.salary == e2.salary)
            return 0;
        else if (e1.salary > e2.salary)
            return 1;
        else
            return -1;
    }
}