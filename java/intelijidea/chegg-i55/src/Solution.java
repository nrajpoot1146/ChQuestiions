public class Solution {
    public static void main(String[] args){
        Date date = new Date(2020, 6, 3);

        System.out.println("Previous Date: " + date.toString());

        System.out.println("Next Date: " + date.nextDate().toString());
    }
}
