import java.util.Scanner;

public class Exp {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		System.out.print("Enter the value for a ");
		int a = sc.nextInt();
		
		System.out.print("Enter the value for b ");
		int b = sc.nextInt();
		
		System.out.print("Enter the value for c ");
		int c = sc.nextInt();
		
		//expression 1
		double z1 = a + ( b * c) % 33;
		//expression 2
		double z2 = a + Math.pow(b, 3) + (double)8 / (double)( 2 * c);
		//expression 3
		boolean z3 = !(a<c) || (a<b) && (a<c);
		//expression 3
		boolean z4 = (z1>z2) && (z1>9);
		
		System.out.println(" The result of z1 is : "+String.format("%1.1f", z1));
		System.out.println(" The result of z2 is : "+z2);
		System.out.println(" The result of z3 is : "+z3);
		System.out.println(" The result of z4 is : "+z4);

		sc.close();
	}

}
