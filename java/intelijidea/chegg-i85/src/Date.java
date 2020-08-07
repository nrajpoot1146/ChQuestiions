import java.time.Year;

public class Date {
    private int month; // 1-12
    private int day; // 1-31 based on mmonth
    private int year; // any year

    private static final int[] daysPerMonth =
            {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    // constructor: confirm propper value for month
    public Date (int month, int day, int year){
        if (month <= 0 || month > 12){
            throw new IllegalArgumentException("Month( "+month+" ) must be in 1-12");
        }
        // check is day in range for month
        if (day <= 0 || (day>daysPerMonth[month]) && !Year.isLeap(year)){
            throw new IllegalArgumentException("day ");
        }

        this.month = month;
        this.day = day;
        this.year = year;
    }

    /**
     * find next date
     * @return new Date
     */
    public Date nextDate(){
        int day = 0;
        int month = 0;
        int year = 0;

        /*
        calculate next date
         */
        if(this.day >= daysPerMonth[this.month]){ // if day is last day of month
            day = 1; month = this.month + 1;
            if(this.month > 12){ // if month is last month of year
                month = 1; year = this.year + 1;
            }else {
                year = this.year;
            }
        }else{ // if day is less than last day of month
            day = this.day+1; month = this.month; year = this.year;
        }

        return new Date(month, day, year); // return object of next date
    }

    @Override
    public String toString() {
        return String.format("%02d/%02d/%d", month, day, year);
    }
}
