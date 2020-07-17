public class StudentListTest {
    public static void main(String[] args){
        StudentArrayList<String> studentArrayList = new StudentArrayList<>();

        studentArrayList.add("Ramesh");
        studentArrayList.add("Suresh");
        studentArrayList.add("Mahesh");
        studentArrayList.add("Gopal");

        System.out.println("Initial list: ");
        System.out.println(studentArrayList.toString());
        System.out.println();

        // remove from index 2
        studentArrayList.remove(2);

        System.out.println("After removing form index 2: ");
        System.out.println(studentArrayList.toString());
        System.out.println();

        // replace from index 2
        studentArrayList.replace(2, "Mahesh");

        System.out.println("after replacing student from index 2: ");
        System.out.println(studentArrayList.toString());
        System.out.println();

        // student at index 1
        System.out.println("student at index 1: ");
        System.out.println(studentArrayList.get(1));
    }
}
