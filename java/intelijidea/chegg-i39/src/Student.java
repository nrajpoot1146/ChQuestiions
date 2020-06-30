public class Student {
    private int id;
    private int age;
    private char gender;
    private String nationality;
    private String phoneNo;

    /**
     *
     * @param id student number
     * @param age age of student
     * @param gender gender of student
     * @param nationality nationality of student
     * @param phoneNo phone number of student
     */
    Student(int id, int age, char gender, String nationality, String phoneNo){
        this.id = id;
        this.setAge(age);
        this.setGender(gender);
        this.setNationality(nationality);
        this.setPhoneNo(phoneNo);
    }

    /**
     *
     * @param id student number
     */
    Student(int id){
        this.id = id;
    }

    /**
     * getter method for student id
     * @return student id
     */
    public int getId() {
        return id;
    }

    /**
     * getter method for student gender
     * @return gender of student
     */
    public char getGender() {
        return gender;
    }

    /**
     * getter methood for student age
     * @return age of student
     */
    public int getAge() {
        return age;
    }

    /**
     * getter method for nationality
     * @return nationality of student
     */
    public String getNationality() {
        return nationality;
    }

    /**
     * getter method for student phone number
     * @return student phone number
     */
    public String getPhoneNo() {
        return phoneNo;
    }

    /**
     * setter method for student age
     * @param age of student
     */
    public void setAge(int age) {
        this.age = age;
    }

    /**
     * setter method for student gender
     * @param gender gender of student
     */
    public void setGender(char gender) {
        this.gender = gender;
    }

    /**
     * setter method for nationality of student
     * @param nationality of student
     */
    public void setNationality(String nationality) {
        this.nationality = nationality;
    }

    /**
     * setter method for phone number of student
     * @param phoneNo of student
     */
    public void setPhoneNo(String phoneNo) {
        this.phoneNo = phoneNo;
    }

    /**
     * print all details of student on console window
     */
    public void print(){
        System.out.println("Student Id: "+this.getId());
        System.out.println("Student age: "+this.getId());
        System.out.println("Student gender: "+this.getGender());
        System.out.println("Student nationality: "+this.getNationality());
        System.out.println("Student phone number: "+this.getPhoneNo());
    }
}
