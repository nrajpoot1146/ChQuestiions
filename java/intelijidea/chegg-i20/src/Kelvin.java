public class Kelvin extends Temperature {

    Kelvin(double value){
        super(value);
    }

    public Celsius toCelsius(){
        double res = this.value - 273.15;
        return new Celsius(res);
    }

    public Fahrenheit toFahrenheit(){
        double res = (this.toCelsius().getValue() * 9/5) + 32;
        return new Fahrenheit(res);
    }


    @Override
    public Temperature add(Temperature temperature) {
        double res = 0;
        if(temperature instanceof Kelvin)
            res = this.value + temperature.value;
        else if (temperature.getClass().getName().equals("Fahrenheit"))
            res = this.value + ((Fahrenheit) temperature).toKelvin().value;
        else
            res = this.value + ((Celsius)temperature).toKelvin().value;
        return new Fahrenheit(res);
    }

    @Override
    public Temperature subtract(Temperature temperature) {
        double res = 0;
        if(temperature instanceof Kelvin)
            res = this.value - temperature.value;
        else if (temperature.getClass().getName().equals("Fahrenheit"))
            res = this.value - ((Fahrenheit) temperature).toKelvin().value;
        else
            res = this.value - ((Celsius)temperature).toKelvin().value;
        return new Fahrenheit(res);
    }

    @Override
    public Temperature divide(Temperature temperature) {
        double res = 0;
        if(temperature instanceof Kelvin)
            res = this.value / temperature.value;
        else if (temperature.getClass().getName().equals("Fahrenheit"))
            res = this.value / ((Fahrenheit) temperature).toKelvin().value;
        else
            res = this.value / ((Celsius)temperature).toKelvin().value;
        return new Fahrenheit(res);
    }
}