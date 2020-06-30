public class Semester {

    public static int SEMESTER_ONE = 1;
    public static int SEMESTER_TWO = 1;
    public static int SEMESTER_THREE = 1;
    public static int SEMESTER_FOUR = 1;
    public static int SEMESTER_FIVE = 1;
    public static int SEMESTER_SIX = 1;
    public static int SEMESTER_SEVEN = 1;
    public static int SEMESTER_EIGHT = 1;

    private int id;
    private Character grade;

    Semester(int id, char grade){
        this.id = id;
        this.grade = grade;
    }

    Semester(int id){
        this.id = id;
        this.grade = null;
    }

    public int getId() {
        return id;
    }

    public char getGrade() {
        return grade;
    }

    public void setGrade(char grade) {
        this.grade = grade;
    }

    public void print(){
        System.out.println("id: "+this.id);
        System.out.println("Grade: "+this.grade);
        System.out.println();
        System.out.println();
    }
}
