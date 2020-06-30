public abstract class Animal {
   private String name;
   private int age;
   private double healthRating;
   private static int numAnimals = 0;

   public Animal(String name, int age, double healthRating) {
      this.name = name;
      this.age = age;
      this.healthRating = healthRating;
      ++numAnimals;
   }

   public String getName() { return this.name; }
   public int getAge() { return this.age; }
   public double getHealthRating() { return this.healthRating; }
   public static int getNumAnimals() { return numAnimals; }

   /** START: BLOCK #1
     * Create a method that will enforce all classes that inherit from the Animal class
     * will need to implement a getNoise() method
     */
     
   abstract public String getNoise();
     
     /** END: BLOCK #1 **/

   public String toString() {
      return "Name: " + this.name + "\n"
      + "Age: " + this.age + "\n"
      + "Health Rating: " + this.healthRating;
   }
}