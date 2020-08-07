public class Main {
    public static void main(String[] args){
        // create new customer
        CustomerData customer = new CustomerData("John","Sharma", 30);

        // print customer details
        System.out.println("Customer id: "+customer.getCustomerNumber());
        System.out.println("Customer name: "+customer.getFirstname()+" "+customer.getLastname());
    }
}
