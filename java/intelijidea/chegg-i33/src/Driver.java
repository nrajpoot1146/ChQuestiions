public class Driver {

    public static void main(String[] args){
        Pet pet = new Pet();

        Cat cat = new Cat();

        Dog dog = new Dog();

        Horse horse = new Horse();

        Cow cow = new Cow();

        System.out.println("Pet says: "+pet.speak());
        System.out.println("Cat says: "+cat.speak());
        System.out.println("Dog says: "+dog.speak());
        System.out.println("Horse says: "+horse.speak());
        System.out.println("Cow says: "+cow.speak());
    }
}
