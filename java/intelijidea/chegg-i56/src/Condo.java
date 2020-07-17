public class Condo {
    private String address, city, state, buildingName, datePurchased;
    private int unitNumber;
    private double purchasedAmt, annualTaxRatePerc, annualInsuranceAmt, monthlyRent;
    private double managementAnnualFees, currentPrice;

    Condo(String address, String city, String state, String buildingName,
          String datePurchased, int unitNumber, double purchasedAmt,double annualTaxRatePerc,
          double annualInsuranceAmt,
          double monthlyRent, double managementAnnualFees, double currentPrice){
        this.address = address;
        this.city = city;
        this.state = state;
        this.buildingName = buildingName;
        this.datePurchased = datePurchased;
        this.unitNumber = unitNumber;
        this.purchasedAmt = purchasedAmt;
        this.annualTaxRatePerc = annualTaxRatePerc;
        this.annualInsuranceAmt = annualInsuranceAmt;
        this.monthlyRent = monthlyRent;
        this.managementAnnualFees = managementAnnualFees;
        this.currentPrice = currentPrice;
    }

    // return full address
    public String getFullAddress(){
        return this.buildingName+", "+this.address+", "+this.city+", "+this.state;
    }

    // return building name
    public String getBuildingName(){
        return this.buildingName;
    }

    // return the date purchased
    public String getDatePurchased(){
        return this.datePurchased;
    }

    // return the purchased amount
    public double getPurchasedAmount(){
        return this.purchasedAmt;
    }

    // return the annual tax amount
    public double getAnnualTaxAmount(){
        return this.annualTaxRatePerc;
    }

    // return the monthly income,
    // which is the monthly rent minus taxes,
    // insurance and management fees
    public double getMonthlyIncome(){
        return this.monthlyRent - this.annualTaxRatePerc - annualInsuranceAmt - managementAnnualFees;
    }

}
