public class Applicant extends Person implements Comparable{
    private int applicantId;
    private double ALESScore;
    private double GPA;
    private double eScore;
    private double interviewScore;
    private double weight;

    /**
     * constructor to create a instance of Applicant
     * @param name of applicant
     */
    Applicant(String name){
        super(name);
        Person.nPerson++;
        this.applicantId = Person.nPerson;
    }

    /**
     * connstructor to create a instance of Applicant
     * @param name of applicant
     * @param lastName of applicant
     */
    Applicant(String name, String lastName){
        super(name, lastName);
        Person.nPerson++;
        this.applicantId = Person.nPerson;
    }

    /**
     * set gpa  of applicant
     * @param GPA of applicant
     */
    public void setGPA(double GPA) {
        if (GPA < 0 || GPA > 4){
            throw new IllegalArgumentException();
        }
        this.GPA = GPA;
    }

    /**
     * set escore of applicant
     * @param eScore of applicant
     */
    public void seteScore(double eScore) {
        if (eScore < 0 || eScore > 100){
            throw new IllegalArgumentException();
        }
        this.eScore = eScore;
    }

    /**
     * set ales scores
     * @param ALESScore score to be set
     */
    public void setALESScore(double ALESScore) {
        if (ALESScore < 0 || ALESScore > 100){
            throw new IllegalArgumentException();
        }
        this.ALESScore = ALESScore;
    }

    /**
     * get applicant id
     * @return applicant id
     */
    public int getApplicantId() {
        return applicantId;
    }

    /**
     * get Ales score
     * @return ales score
     */
    public double getALESScore() {
        return ALESScore;
    }

    /**
     * get escore
     * @return escore of applicant
     */
    public double geteScore() {
        return eScore;
    }

    /**
     * get gpa of applicant
     * @return gpa of current applicant
     */
    public double getGPA() {
        return GPA;
    }

    /**
     * get interview score of current applicant
     * @return interview score of applicant
     */
    public double getInterviewScore() {
        return interviewScore;
    }

    /**
     * set interview score of applicant
     * @param interviewScore of applicant
     */
    public void setInterviewScore(double interviewScore) {
        if (interviewScore < 0 || interviewScore >10){
            throw new IllegalArgumentException();
        }
        this.interviewScore = interviewScore;
    }

    /**
     * calculate weight and store into weight attribute
     * map gpa and interview score to 0 - 100
     * use formula
     * weight = 0.35 * ALESScore + 0.2 * gpa + 0.3 * eScore + 0.15 * interviewScore;
     * @return calculated weight
     */
    public double calWeight(){
        double gpa = (this.GPA / 4) * 100;
        double interviewScore = (this.interviewScore / 10) * 100;

        this.weight = 0.35 * this.ALESScore + 0.2 * gpa + 0.3 * eScore + 0.15 * interviewScore;
        //this.weight +=1;
        return this.weight;
    }

    /**
     * compare two Applicant
     * on the basis of weight
     * if equal return 0, if current is less than other return -1, if current is greater than other retrun 1
     * @param o
     * @return
     */
    @Override
    public int compareTo(Object o) {
        this.calWeight();
        if (this.weight < ((Applicant)o).weight){
            return -1;
        }else if(this.weight > ((Applicant)o).weight){
            return 1;
        }
        return 0;
    }

    @Override
    public String toString() {
        return  "id: "+this.applicantId+" "+super.toString();
    }
}
