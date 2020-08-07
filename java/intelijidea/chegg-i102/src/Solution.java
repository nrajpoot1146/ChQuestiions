public class Solution {

    /**
     * required function
     * @param n integer value, n is non negative integer
     * @return value of f(n) = f(n - 1) * f(n-2) - f(n -3)
     */
    public static int f(int n){
        if (n < 0){
            return 0;
        }
        
        if (n>=0 && n < 3){
            return n;
        }

        return f(n-1) * f(n-2) - f(n-3);
    }

    /**
     * main driver function
     * @param args command line argument
     */
    public static void main(String[] args){
        // print f(n) for 0 <= n < 10
        for (int i=0; i<10; i++){
            System.out.println("f("+ i +") = "+ f(i));
        }
    }
}
