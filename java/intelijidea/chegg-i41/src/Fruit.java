/**
 * class to store a single fruits information
 * attribute
 *      name : name of fruits
 *      color:  color of fruits
 */
public class Fruit {
    private String name;
    private String color;

    /**
     * set name = null
     * set color = null
     */
    Fruit(){
        this.name = null;
        this.color = null;
    }

    /**
     * set name = name of fruits
     * set color  = null
     * @param name of fruits
     */
    Fruit(String name){
        this.name = name;
        this.color = null;
    }

    /**
     *
     * @param name of fruits
     * @param color of fruits
     */
    Fruit(String name, String color){
        this.name = name;
        this.color = color;
    }

    /**
     * setter method to set name of fruits
     * @param name of fruits
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * settter method to set color of fruits
     * @param color of fruits
     */
    public void setColor(String color) {
        this.color = color;
    }

    /**
     * getter method for color
     * @return color of fruits
     */
    public String getColor() {
        return color;
    }

    /**
     * getter method for name
     * @return name of fruits
     */
    public String getName() {
        return name;
    }

    /**
     * return an string
     * @return string of current fruit name and color
     */
    @Override
    public String toString() {
        return "name: '" + this.name + "', " +
                "color: '" + this.color+"'";
    }
}
