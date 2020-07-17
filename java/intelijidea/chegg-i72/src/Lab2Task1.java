public class Lab2Task1 {
    public static void main(String... args){
        /*
        create object of different classed that implements Common interface
        initialize objects
         */
        Horse horse = new Horse("Clydesdale");
        Bicycle bicycle = new Bicycle(16, false, true);
        Freezer freezer = new Freezer(Freezer.Size.UPRIGHT, true, true);
        Chair chair = new Chair(true);

        /*
         * print details of different classes using same function
         * this shows polymorphism techniques
         */
        printDetails(horse);
        System.out.println();
        printDetails(bicycle);
        System.out.println();
        printDetails(freezer);
        System.out.println();
        printDetails(chair);
    }

    public static void printDetails(Common ob){
        System.out.println("Name : " + ob.getClass().getSimpleName());
        System.out.println("Needs electricity: " + ob.needsElectricity());
        System.out.println("Needs Water: " + ob.needsWater());
        System.out.println("Size: " + ob.size());
    }
}
