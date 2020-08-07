public class Driver {
    public static void main(String[] args){
        IntList intList = new IntList();
        System.out.println("Empty list: " + intList.toString());

        intList.rand();
        // fill intList with random number
        System.out.println("List after filling random numbers: "+intList.toString());

    }
}
