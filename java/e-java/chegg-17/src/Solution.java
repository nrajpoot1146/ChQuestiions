import java.util.Scanner;

public class Solution {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		while(true) {
			System.out.println("Please choose one option : ");
			System.out.println("1. Factorial");
			System.out.println("2. Reverse Digit");
			System.out.println("3. Find e power x");
			System.out.println("4. Common Count");
			System.out.println("5. Exit");
			int op = sc.nextInt();
			sc.nextLine();
			
			if(op==1) {
				System.out.println("Enter an integer : ");
				int num = sc.nextInt();
				sc.nextLine();
				int fact = factorial(num);
				System.out.println("The factorial of "+num+" is "+fact);
			}else if(op==2) {
				System.out.println("Enter an integer : ");
				int num = sc.nextInt();
				sc.nextLine();
				int reverse = reverseDigits(num);
				System.out.println(num+" after digits reversed = "+reverse);
			}else if(op == 3) {
				System.out.println("Enter value of x : ");
				int x = sc.nextInt();
				System.out.println("Enter value of n : ");
				int n = sc.nextInt();
				sc.nextLine();
				double res = findEpowX(x, n);
				System.out.println("e power "+x+" is "+res);
			}else if(op == 4) {
				System.out.println("Enter first sentence : ");
				String sent1 = sc.nextLine();
				System.out.println("Enter second sentence : ");
				String sent2 = sc.nextLine();
				int count = countCommon(sent1, sent2);
				System.out.println("common count is : "+count);
			}else if(op == 5) {
				break;
			}
		}
	}

	/**
	 * 
	 * @param num
	 * @return
	 */
	private static int factorial(int num) {
		int fact = 1;
		if(num == 0)
			return 1;
		while(num>0) {
			fact *= num--;
		}
		return fact;
	}
	
	/**
	 * 
	 * @param num
	 * @return
	 */
	private static int reverseDigits(int num) {
		int reverseDigit = 0;
		boolean flag = false;
		if(num < 0) {
			num = num * -1;
			flag = true;
		}
		while(num>0) {
			int mod = num % 10;
			reverseDigit = reverseDigit *10 +mod;
			num /= 10;
		}
		if(flag == true) {
			reverseDigit *= -1;
		}
		return reverseDigit;
	}
	
	/**
	 * 
	 * @param x
	 * @param n
	 * @return
	 */
	private static double findEpowX(int x, int n) {
		double res = 1;
		int i = 1;
		while(i <= n) {
			res += Math.pow(x, i)/factorial(i);
			i++;
		}
		return res;
	}
	
	/**
	 * 
	 * @param sent1
	 * @param sent2
	 * @return
	 */
	private static int countCommon(String sent1, String sent2) {
		int count = 0;
		sent1 = sent1.toLowerCase();
		sent2 = sent2.toLowerCase();
		for(int i = 0 ; i<sent1.length(); i++) {
			char c = sent1.charAt(i);
			if(sent2.contains(Character.toString(c))){
				count++;
			}
		}
		
		return count;
	}
}
