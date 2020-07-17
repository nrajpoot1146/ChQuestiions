public class CondoTestYourname {
    public static void main(String[] args){
        Condo  condo = new Condo(
                "small town", "city", "state", "buildingname",
                "11/02/2020", 20, 80.12, 30, 12,
                10000, 100, 1200
        );

        System.out.println("Full address: "+condo.getFullAddress());
        System.out.println("Building name: "+condo.getBuildingName());
        System.out.println("Date of purchased: "+condo.getDatePurchased());
        System.out.println("Purchased amount: "+condo.getPurchasedAmount());
        System.out.println("Annual Tax: "+condo.getAnnualTaxAmount());
        System.out.println("Monthly income: "+condo.getMonthlyIncome());
    }
}
