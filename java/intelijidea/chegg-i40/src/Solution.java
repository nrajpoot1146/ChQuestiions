import java.util.Scanner;

/**
 * solution class
 * have two function
 * 1. main function
 *      get data from user
 *      fetch all character from password
 *      call getEncrypt function
 *      put output on console window
 * 2. getEncrypt function
 *      get character as parameter
 *      encrypt current character
 *      send encrypt string to collie function
 */
public class Solution {

    /**
     *
     * @param args
     */
    public static void main(String[] args){
        System.out.println("Enter your password: ");
        Scanner sc = new Scanner(System.in);
        // get value of password from user
        String password = sc.nextLine();

        // encrypt password
        StringBuilder passBuilder = new StringBuilder();
        for (int i = 0; i < password.length(); i++){
            String enc = getEncrypt(password.charAt(i));
            passBuilder.append(enc);
        }
        System.out.println("Encrypted password: "+passBuilder.toString());
        sc.close();
    }

    /**
     * all alphabetic character encrypted as their ascii value
     * all numeric character encrypted as:
     *      0   =>  a
     *      1   =>  b
     *      2   =>  c
     *      3   =>  d
     *      4   =>  e
     *      5   =>  f
     *      6   =>  g
     *      7   =>  h
     *      8   =>  i
     *      9   =>  j
     * @param c original character to be encrypted
     * @return encrypted string
     */
    private static String getEncrypt(char c){
        // if character is alphabetic then it replaced by its ascii value
        if (c >= 'a' && c <= 'z' || c >= 'A' && c <= 'Z'){
            return Integer.toString( (int) c);
        }else if(c >= '0' && c <= '9' ){ // character is numeric then it replaced start with a to j
            switch (c){
                case '0':
                    return "a";
                case '1':
                    return "b";
                case '2':
                    return "c";
                case '3':
                    return "d";
                case '4':
                    return "e";
                case '5':
                    return "f";
                case '6':
                    return "g";
                case '7':
                    return "h";
                case '8':
                    return "i";
                default:
                    return "j";
            }
        }else{ // if character is punctuation then it replaced by 0
            return "0";
        }
    }
}
