public class Driver {
    public static void main(String[] args){
        goRams grams = new goRams();
        grams.createRams("input.txt");
        // initially csuRam list
        System.out.println("initially csuRam list:");
        System.out.println(grams.listFormat());

        // sorting csuRam list with name
        grams.sortList("name");
        System.out.println("After sorting by name: ");
        System.out.println(grams.listFormat());

        // find tony frank
        System.out.println("find Tony Frank: ");
        System.out.println(grams.findTonyFrank());
    }
}
