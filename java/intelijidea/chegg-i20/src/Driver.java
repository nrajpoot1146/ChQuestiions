public class Driver {
    public static void main(String[] args){
        Kelvin kelvin = new Kelvin(0);
        Fahrenheit fahrenheit = kelvin.toFahrenheit();
        Celsius celsius = kelvin.toCelsius();

        System.out.println(kelvin.getValue());
        System.out.println(fahrenheit.getValue());
        System.out.println(celsius.getValue());

        System.out.println("addition : "+kelvin.add(new Celsius(23)).getValue());
    }
}
