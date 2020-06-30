public class Main {
    public static void main(String[] args){
        Administer administer = new Administer(1,"Demo");

        Subject subject1 = new Subject(1,"subject1");
        Subject subject2 = new Subject(2,"subject2");
        Subject subject3 = new Subject(3,"subject3");

        Student student1 = new Student(1,"student 1", new Semester(Semester.SEMESTER_SEVEN,'A'),1234);
        Student student2 = new Student(2,"student 2", new Semester(Semester.SEMESTER_SEVEN,'B'),1235);

        student1.addSubject(subject1);
        student1.addSubject(subject2);

        student2.addSubject(subject2);
        student2.addSubject(subject3);

        administer.addStudent(student1);
        administer.addStudent(student2);

        administer.getStudent(1).print();
        administer.getStudent(2).print();

        subject1.print();
        subject2.print();
        subject3.print();

        administer.print();
    }
}
