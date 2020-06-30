public class Celsius extends Temperature {

    Celsius(double value){
        super(value);
    }
    public Kelvin toKelvin(){
        double res = this.value + 273.15;
        return new Kelvin(res);
    }

    public Fahrenheit toFahrenheit(){
        double res = (this.value * 9/5) + 32;
        return new Fahrenheit(res);
    }

    public double getValue() {
        return value;
    }


    @Override
    public Temperature add(Temperature temperature) {
        double res = 0;
        if(temperature instanceof Celsius)
            res = this.value + temperature.value;
        else if (temperature.getClass().getName().equals("Fahrenheit"))
            res = this.value + ((Fahrenheit) temperature).toCelsius().value;
        else
            res = this.value + ((Kelvin)temperature).toCelsius().value;
        return new Fahrenheit(res);
    }

    @Override
    public Temperature subtract(Temperature temperature) {
        double res = 0;
        if(temperature instanceof Celsius)
            res = this.value - temperature.value;
        else if (temperature.getClass().getName().equals("Fahrenheit"))
            res = this.value - ((Fahrenheit) temperature).toCelsius().value;
        else
            res = this.value - ((Kelvin)temperature).toCelsius().value;
        return new Fahrenheit(res);
    }

    @Override
    public Temperature divide(Temperature temperature) {
        double res = 0;
        if(temperature instanceof Celsius)
            res = this.value / temperature.value;
        else if (temperature.getClass().getName().equals("Fahrenheit"))
            res = this.value / ((Fahrenheit) temperature).toCelsius().value;
        else
            res = this.value / ((Kelvin)temperature).toCelsius().value;
        return new Fahrenheit(res);
    }
}