/*
 * CSC110AA/CIS163AA
 * An Integer Array
 *
 * This is the starting code for the StatsArray Assignment
 * The display method and the sortArray methods have been implemented
 *
 *
 * All of the other methods are just returning some default value.  You will need to
 * implement these methods so that they return the appropriate value.
 *
 * Patricia Baker
 */

import java.awt.*;
import java.util.Random;  //for our random number generator

public class StatsArray {

    //instance variables
    private int size;  //how big is the array
    private int[] stats; // an array of integers

    //default constructor -overloaded method
    StatsArray() {
        size = 10;
        stats = new int[size] ;  //instantiate the array called stats
    }

    public void display(Graphics g)
    {
        int x = 50;  //coordinates for displaying
        int y = 40;

        //display the array with position number
        for(int i = 0; i < stats.length; i++)
        {
            g.drawString("Stats [" + i + "] = "+ stats[i],
                    x,     (y + 15 * i));
        }
    }

    /**
     * fill array with random number
     */
    public void fillArray()
    {
        /*fill the array with random numbers (int) in the range 0 - 100.*/
        Random random = new Random();
        for (int i = 0; i < this.size; i++){
            this.stats[i] = random.nextInt(100);
        }
    }

    /**
     * calculate sum of element of array stats
     * @return sum of elements of array stats
     */
    public int getSum()
    {
        //add up all the values in the array
        int sum = 0;
        for (int s : this.stats){
            sum += s;
        }
        return sum;
    }

    /**
     * get maximum number from array stats
     * @return max number
     */
    public int getMax()
    {
        //return the maximum value in the array
        int max = this.stats[0];
        for (int i = 1; i < this.size; i++){
            if (max < this.stats[i]){
                max = this.stats[i];
            }
        }
        return max;
    }

    /**
     * get minimum number from array stats
     * @return min number
     */
    public int getMin()
    {
        //return the minimum value in the array
        int min = this.stats[0];
        for (int i = 1; i < this.size; i++){
            if (min > this.stats[i]){
                min = this.stats[i];
            }
        }
        return min;
    }

    /**
     * calculate average of elements of array stats
     * @return average
     */
    public double getAverage()
    {
        //return the average
        double avg = this.getSum() / (double) this.size;
        return avg;
    }

    /**
     * counts value presents in array stats in given range
     * @param lowRange lower bound
     * @param highRange upper bound
     * @return counts variable
     */
    public int countValues(int lowRange, int highRange)
    {
        //count how many numbers are >= lowRange and <= highRange
        int count = 0;
        for (int s : this.stats){
            if (s >= lowRange && s <= highRange){
                count++;
            }
        }
        return count;
    }


    /**
     * find a given value in array stats
     * @param someNumber value to be found
     * @return true if value is exist otherwise return false
     */
    public boolean isValueFound(int someNumber)
    {
        //check to see if someNumber is in the array
        for (int s : this.stats){
            if (someNumber == s){
                return true;
            }
        }
        return false;
    }


    public void sortArray()
    {
        /*sort the array in ascending order - selection sort*/

        int tempValue;
        int min;

        for (int i = 0; i < (stats.length - 1); i++)
        {
            min = i;
            for (int j = (i + 1); j < (stats.length); j++)
            {
                if (stats[j] < stats[min])
                {
                    min = j;
                }
            }
            tempValue = stats[min];
            stats[min] = stats[i];
            stats[i] = tempValue;


        }

    }


    public void sortBArray() {
                /*Here is another common sort algorithm.
                  It sorts the array in ascending order.
                  This is called a bubble sort.  I have added it
                  so that you can take a look at it.*/

        int tempValue;

        for (int i = 0; i < (stats.length - 1); i++)
        {
            for (int j = (i + 1); j < (stats.length); j++)
            {
                if (stats[j] < stats[i])
                {
                    tempValue = stats[i];
                    stats[i] = stats[j];
                    stats[j] = tempValue;
                }
            }
        }
    }

}//end of StatsArray Class definition