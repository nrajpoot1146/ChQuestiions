public class Tett {

    /**
     * function to sort a array using Comparable interface
     * use bubble sort algorithm
     * @param data array to be sorted
     * @param flag boolean variable, true for ascending order and false for descending order
     * @param <T> type of array
     * @return sorted array
     */
    public static <T> T[] sort(T[] data, boolean flag){
        for (int i = 0; i < data.length-1; i++){
            for (int j = 0; j < data.length-i-1; j++){

                if ( ((Comparable) data[j]).compareTo(data[j+1]) > 0 && flag){
                    T temp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = temp;
                }else if(!flag){
                    T temp = data[j];
                    data[j] = data[j+1];
                    data[j+1] = temp;
                }
            }
        }
        return data;
    }

    /**
     * print array using to string method
     * @param data array to be print
     * @param <T> data type of array
     */
    public static <T> void print(T[] data){
        for (int i = 0; i < data.length; i++)
            System.out.println(data[i].toString());
    }

    /**
     * driver function
     * @param args
     */
    public static void main(String[] args){
        // generate an array of applicant
        Applicant[] applicants = new Applicant[4];

        // fill information
        applicants[0] = new Applicant("John", "Singh");
        applicants[0].setALESScore(80);
        applicants[0].seteScore(80);
        applicants[0].setGPA(4);
        applicants[0].setInterviewScore(8);
        applicants[0].calWeight();

        applicants[1] = new Applicant("Ram", "Prashad");
        applicants[1].setALESScore(50);
        applicants[1].seteScore(50);
        applicants[1].setGPA(4);
        applicants[1].setInterviewScore(8);
        applicants[1].calWeight();

        applicants[2] = new Applicant("Kalvin", "L");
        applicants[2].setALESScore(80);
        applicants[2].seteScore(70);
        applicants[2].setGPA(3);
        applicants[2].setInterviewScore(8);
        applicants[2].calWeight();

        applicants[3] = new Applicant("Ramesh", "Kumar");
        applicants[3].setALESScore(100);
        applicants[3].seteScore(100);
        applicants[3].setGPA(2.5);
        applicants[3].setInterviewScore(10);
        applicants[3].calWeight();

        System.out.println("Applicants list: ");
        print(applicants);

        // sort applicants array
        sort(applicants ,false);

        System.out.println("\nSorted Applicants list: ");
        // print sorted array
        print(applicants);

    }
}
