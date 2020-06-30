public class Fahrenheit extends Temperature {

    Fahrenheit(double value){
        super(value);
    }

    public Kelvin toKelvin(){
        double res = this.toCelsius().getValue() + 273.15;
        return new Kelvin(res);
    }

    public Celsius toCelsius(){
        double res = (this.value - 32) * 5/9;
        return new Celsius(res);
    }


    @Override
    public Temperature add(Temperature temperature) {
        double res = 0;
        if(temperature instanceof Fahrenheit)
            res = this.value + temperature.value;
        else if (temperature.getClass().getName().equals("Kelvin"))
            res = this.value + ((Kelvin) temperature).toFahrenheit().value;
        else
            res = this.value + ((Celsius)temperature).toFahrenheit().value;
        return new Fahrenheit(res);
    }

    @Override
    public Temperature subtract(Temperature temperature) {
        double res = 0;
        if(temperature instanceof Fahrenheit)
            res = this.value - temperature.value;
        else if (temperature.getClass().getName().equals("Kelvin"))
            res = this.value - ((Kelvin) temperature).toFahrenheit().value;
        else
            res = this.value - ((Celsius)temperature).toFahrenheit().value;
        return new Fahrenheit(res);
    }

    @Override
    public Temperature divide(Temperature temperature) {
        double res = 0;
        if(temperature instanceof Fahrenheit)
            res = this.value / temperature.value;
        else if (temperature.getClass().getName().equals("Kelvin"))
            res = this.value / ((Kelvin) temperature).toFahrenheit().value;
        else
            res = this.value / ((Celsius)temperature).toFahrenheit().value;
        return new Fahrenheit(res);
    }
}
