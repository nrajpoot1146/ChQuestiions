import java.util.Scanner;

public class Main {
	static int i;
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter a number in base 10 : ");
		int num = sc.nextInt();
		i = num;
		System.out.println("Enter a base in which you want to convert given number : ");
		int tBase = sc.nextInt();
		if(tBase <= 16) {
			String res = convert(num, tBase);
			System.out.println("Result in base "+tBase+" : "+res);
		}else {
			System.out.println("Base must be lesser than or equal to 16");
		}
	}
	
	public static String convert(int num, int tBase) {
		String res = "";
		int mod = num % tBase;
		
		switch(mod) {
		case 10:
			res = res + "a";
			break;
		case 11:
			res = res + "b";
			break;
		case 12:
			res = res + "c";
			break;
		case 13:
			res = res + "d";
			break;
		case 14:
			res = res + "e";
			break;
		case 15:
			res = res + "f";
			break;
		default:
			res = res + Integer.toString(mod);
		}
		
		if(num / tBase == 0) {
			return res;
		}
		
		res = res + convert(num / tBase, tBase);
		if(i == num) {
			StringBuilder temp = new StringBuilder(res);
			temp = temp.reverse();
			res = temp.toString();
		}
		return res;
	}

}
