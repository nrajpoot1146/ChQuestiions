import java.util.Scanner;

class Mainprogram {
    // Declare a Main Function to get inputs and call fraction class methods
    public static void main(String args[])
    {
        Scanner scn=new Scanner(System.in);
        // Code 1 to check repeated character in string
        // Take String From User
        System.out.println ( "Enter the String");
        String str = scn.next();
        // Flg is variable that will change if any same character
        boolean flag=true;
        for (int i = 0; i < str.length(); i++)
            for (int j = i + 1; j < str.length(); j++)
                if (str.charAt(i) == str.charAt(j))
                    flag=false;
        // if flag = false then string has repeated characters
        if (!flag)
            System.out.println("The String " + str + " has repeated characters");
        else
            System.out.println("The String " + str + " has no repeated characters");
        // Now from here we Code 2 of fraction class has started i.e FractionFDemo .java
        // make a object of Fraction Class
        Fraction obj = new Fraction();
        Fraction obj2 = new Fraction();
        int n,d;
        // Repeat the loop until numerator is negative
        do
        {
            // Take numerator and denominator from user
            System.out.println ( "Enter the numerator and denominator ");
            n = scn.nextInt();
            d = scn.nextInt();
            // If numerator>0 then only call class methods
            obj.get_input(n,d);
            if(n>0)
            {
                // Call methods to print the Fraction
                obj.printOutput();

                System.out.println ( "Enter the numerator and denominator ");
                n = scn.nextInt();
                d = scn.nextInt();

                obj2.get_input(n, d);
                Fraction sum = obj.add(obj2);
                // question 3
                // check equality
                System.out.println("isEqual: "+ obj.equals(obj2));
                // calculate sum
                System.out.println("Sum = ");
                sum.printOutput();
            }

        } while(!obj.isZero()); // question 2


    }
}