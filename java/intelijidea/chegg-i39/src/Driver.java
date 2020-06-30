import java.util.Scanner;

public class Driver {
    public static void main(String[] args){
        StudentList studentList = new StudentList();

        Scanner scanner = new Scanner(System.in);
        int op;
        do{
            menu();
             op = scanner.nextInt();
             switch (op){
                 case 1:
                     System.out.println("Enter Student id: ");
                     Student student = new Student(scanner.nextInt());

                     System.out.println("Enter student age: ");
                     student.setAge(scanner.nextInt());
                     scanner.nextLine();

                     System.out.println("Enter student gender (M/F): ");
                     student.setGender(scanner.nextLine().charAt(0));

                     System.out.println("Enter student nationality: ");
                     student.setNationality(scanner.nextLine());

                     System.out.println("Enter student phone number: ");
                     student.setPhoneNo(scanner.nextLine());
                     studentList.add(student);
                     break;
                 case 2:
                     System.out.println("Enter student id: ");
                     studentList.delete(scanner.nextInt());
                     break;
                 case 3:
                     System.out.println("Enter student id: ");
                     studentList.update(scanner.nextInt());
                     break;
                 case 4:
                     studentList.display();
                     break;
                 case 5:
                     studentList.sortInAscending();
                     break;
                 case 6:
                     studentList.sortInDescending();
                     break;
                 case  7:
                     System.out.println("Enter Student id: ");
                     studentList.search(scanner.nextInt());
                     break;
             }
        }while (op != 8);

    }

    /**
     * show menu on console window
     */
    public static void menu(){
        System.out.println("Menu: ");
        System.out.println("1. Add Student");
        System.out.println("2. Delete Student");
        System.out.println("3. Update Student information");
        System.out.println("4. Display All Student");
        System.out.println("5. Arrange students in ascending order");
        System.out.println("6. Arrange students in descending order");
        System.out.println("7. Search by student number");
        System.out.println("8. Exit program");
    }
}
