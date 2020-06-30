public class SalesTracker {
    public static void main(String[] args){
        Services services = new Services(500, 6); // create an service object

        Supplied supplied = new Supplied(8688, 6886, 6445); // create an supplied object

        Paper paper = new Paper(698, 6); // create a paper object

        System.out.println("Supplies = $"+supplied.getTotalSupplied());
        System.out.println("Services = $"+ services.getServices());
        System.out.println("Paper $= "+paper.getPaper());
    }
}
