//Order Class starts here

package info.hccis.assignment.bo;

import java.text.NumberFormat;
import java.util.Locale;
import java.util.Scanner;

import javax.swing.text.DefaultEditorKit.CutAction;

public class Order {

    public static final String BUSINESS_NAME = "Bernadette's Flowers";
    public static final String BUSINESS_ADDRESS = "25 Hopeton Road\nStratford, PE\nC1B 1H6";
    public static final double TAX_RATE = 0.15;

    public static final int NUMBER_BOUQUET_TYPES = 4;
    public static final int BOUQUET_WELCOME_BABY_BOY = 0;
    public static final int BOUQUET_WELCOME_BABY_GIRL = 1;
    public static final int BOUQUET_VERY_SPECIAL_DELIVERY = 2;
    public static final int BOUQUET_BRIDAL_SHOWER = 3;
    public static final int[] BOUQUET_COSTS = { 90, 85, 100, 75 };
    public static final String[] BOUQUET_NAMES = { "Welcome Baby Boy", "Welcome Baby Girl", "Very Special Delivery",
            "Bridal Shower" };

    public static final double COST_LARGE = 500;
    public static final double COST_STUFFED_SMALL = 10;
    public static final double COST_STUFFED_MEDIUM = 20;
    public static final double COST_STUFFED_LARGE = 30;
    private int[] numberBouquets = new int[NUMBER_BOUQUET_TYPES];

    private int stuffedAnimalOption;

    private Customer customer;

    public Order(int numberWelcomeBabyBoy, int numberWelcomeBabyGirl, int numberVerySpecialDelivery,
            int numberBridalShower, int stuffedAnimalOption) {
        this.numberBouquets[BOUQUET_WELCOME_BABY_BOY] = numberWelcomeBabyBoy;
        this.numberBouquets[BOUQUET_WELCOME_BABY_GIRL] = numberWelcomeBabyGirl;
        this.numberBouquets[BOUQUET_VERY_SPECIAL_DELIVERY] = numberVerySpecialDelivery;
        this.numberBouquets[BOUQUET_BRIDAL_SHOWER] = numberBridalShower;
        this.stuffedAnimalOption = stuffedAnimalOption; // BJM 20190521 Added for assignment 4
    }

    public Order() {
        // Default constructor.
    }

    public static void showBusinessInformation() {
        // Show the business information
        System.out.println(BUSINESS_NAME);
        System.out.println(BUSINESS_ADDRESS);
        System.out.println(""); // Empty line after display

    }

    public void getInformation() {
    	System.out.println("are you Preferred Cutomer type (y/n):");
        Scanner input = new Scanner(System.in);
        if(input.equals("y") || input.equals("Y")) {
        	this.customer = new PrefferedCustomer();
        }else
        	customer = new Customer();
        customer.getInformation();
        boolean valid = true;

        for (int bouquetCount = 0; bouquetCount < NUMBER_BOUQUET_TYPES; ++bouquetCount) {

            valid = true; // Set to true. Will be false if invalid.
            System.out.println("\nHow many '" + BOUQUET_NAMES[bouquetCount] + "' bouquets?");
            numberBouquets[bouquetCount] = input.nextInt();
            input.nextLine();

            if (numberBouquets[bouquetCount] < 0 || numberBouquets[bouquetCount] > 20) {
                System.out.println("Invalid amount, please enter an amount between 0-20");
                valid = false;
            }

        }

        valid = true;
        System.out.println("Stuffed animal option (1=Small 2=Medium 3=Large 0=None):");
        stuffedAnimalOption = input.nextInt();
        input.nextLine(); // burn

        if (stuffedAnimalOption < 0 || stuffedAnimalOption > 3) {
            System.out.println("Invalid amount, please enter an amount between 0-3");
            valid = false;
        }
        System.out.println(""); // empty line after input gathered

    }

    public double getSubtotal() {

        double subtotal = 0;

        for (int bouquetCount = 0; bouquetCount < NUMBER_BOUQUET_TYPES; ++bouquetCount) {
            subtotal += BOUQUET_COSTS[bouquetCount] * numberBouquets[bouquetCount];
        }

        double stuffedAnimalCost = 0;
        switch (stuffedAnimalOption) {
            case 1:
                subtotal += COST_STUFFED_SMALL;
                break;
            case 2:
                subtotal += COST_STUFFED_MEDIUM;
                break;
            case 3:
                subtotal += COST_STUFFED_LARGE;
                break;
        }
        if(this.customer instanceof PrefferedCustomer) {
        	subtotal = subtotal - 0.15*subtotal;
        }
        return subtotal;
    }

    public double getTax() {
        return TAX_RATE * getSubtotal();
    }

    public double getTotal() {
        return getSubtotal() + getTax();
    }

    public int getStuffedAnimalOption() {
        return stuffedAnimalOption;
    }

    public void setStuffedAnimalOption(int stuffedAnimalOption) {
        this.stuffedAnimalOption = stuffedAnimalOption;
    }

    public Customer getCustomer() {
        return customer;
    }

    public void display() {
        System.out.println(toString());
    }

    public String toString() {
        double total = getTotal();
        String output = "Order Summary";
        if (total >= COST_LARGE) {
            output += " (Large Order!)";
        }

        String stuffedAnimalDescription = "";
        switch (stuffedAnimalOption) {
            case 1:
                stuffedAnimalDescription = "Small";
                break;
            case 2:
                stuffedAnimalDescription = "Medium";
                break;
            case 3:
                stuffedAnimalDescription = "Large";
                break;
            default:
                stuffedAnimalDescription = "None";
        }

        // Customer Details
        output += "\n\n" + customer.toString() + "\n";

        for (int bouquetCount = 0; bouquetCount < NUMBER_BOUQUET_TYPES; ++bouquetCount) {
            output += "\nNumber of " + BOUQUET_NAMES[bouquetCount] + " bouquets: " + numberBouquets[bouquetCount];
        }

        output += "\nStuffed Animal: " + stuffedAnimalDescription;

        NumberFormat format = NumberFormat.getCurrencyInstance(Locale.CANADA);
        String subtotalCurrency = format.format(getSubtotal());
        String taxCurrency = format.format(getTax());

        // Using String format method
        String totalCurrency = String.format("$%,.2f", getTotal());

        output += "\nSubtotal: " + subtotalCurrency;
        output += "\nTax: " + taxCurrency;
        output += "\nTotal Cost: " + totalCurrency;
        if(this.customer instanceof PrefferedCustomer) {
        	output +="\n Loyalty Card Number" + ((PrefferedCustomer) customer).loyaltyCardNumber;
        }
        return output;
    }
} // Order Class ends here