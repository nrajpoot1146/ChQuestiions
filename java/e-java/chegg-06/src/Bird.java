public class Bird extends Animal {

   public Bird(String name, int age, double healthRating) {
      super(name, age, healthRating);
   }
   
   public String getNoise() {
      return "Chirp";
   }
}