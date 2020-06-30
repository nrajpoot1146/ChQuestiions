import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.Arrays;
import java.util.TimeZone;


public class TestPet {
    public static void main(String[] args) throws ParseException {
        SimpleDateFormat format = new SimpleDateFormat("yyyy/MM/dd HH:mm:ss");
        format.setTimeZone(TimeZone.getTimeZone("US/Eastern"));

        Reptile reptile = new Reptile("Slinky", 'M', format.parse("2017/02/03 17:06:54"), "rock python");

        System.out.println("Reptile name = "+reptile.toString());
        System.out.println(reptile.move());
        System.out.println(reptile.sound()+", "+reptile.getAcquired());

        Dog[] dogs = new Dog[4];
        dogs[0] = new Dog("Pedro", 'M',format.parse("2017/02/03 17:06:54"),"chihuahua",14);
        dogs[1] = new Dog("Butch", 'M',format.parse("2017/02/03 17:06:54"),"Alsatian",90);
        dogs[2] = new Dog("Sacha", 'F',format.parse("2017/02/03 17:06:54"),"beagle",25);
        dogs[3] = new Dog("Marley", 'M',format.parse("2017/02/03 17:06:54"),"pug",20);

        Arrays.sort(dogs,Dog::compareTo);
        System.out.println("All dogs sorted by weight");
        for(Dog dog: dogs){
            System.out.println("Dog name = "+dog.toString());
            System.out.println(dog.move()+", weight "+dog.getWeight());
            System.out.println(dog.sound()+", "+dog.getAcquired());
        }
    }
}
