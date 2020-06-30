import java.time.Month;
import java.time.Year;

/**
 *
 * Date class with nextDate function
 * validate date if date is invalid throws IllegalArgumentException
 */
public class Date {
    private int year;
    private int month;
    private int day;
    private int[] monthLengths = new int[] {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    /**
     * create new date instance
     * @param year year
     * @param month month of year
     * @param day day of month
     */
    public Date(int year, int month, int day) {
        this.year = year;
        this.month = month;
        this.day = day;

        /*
        if year is leap year then update day in second month
         */
        if (Year.isLeap(this.year)){
            this.monthLengths[1] = 29;
        }else{
            this.monthLengths[1] = 28;
        }

        validate();
    }

    /**
     * calculate next date
     * @return new Date
     */
    public Date nextDate(){
        int day = 0;
        int month = 0;
        int year = 0;

        /*
        calculate next date
         */
        if(this.day >= this.monthLengths[this.month-1]){ //day is last day of month
            day = 1;
            month = this.month + 1;
            if(this.month > 12){ // if month is last month of year
                month = 1;
                year = this.year + 1;
            }else {
                year = this.year;
            }
        }else{ // if day is less than last day of month
            day = this.day+1;
            month = this.month;
            year = this.year;
        }

        return new Date(year, month, day); // create new Date and return it;
    }

    /**
     *
     * @return date month and year in Month day, year format;
     */
    @Override
    public String toString() {
        return Month.of(this.month).name().substring(0,1).toUpperCase()
                + Month.of(this.month).name().substring(1).toLowerCase()
                + " "
                + this.day
                + ", "
                + this.year;
    }

    /**
     * validate date
     * @throws IllegalArgumentException if date is invalid date
     */
    private void validate() {
        // throw an exception if the current values of year, month and day do not
        if(this.month > 12 || this.day > this.monthLengths[this.month-1]){ //date validation whether date is valid date or not
            throw new IllegalArgumentException(); // if date is invalid date then throw a IllegalArgumentException
        }
    }

}