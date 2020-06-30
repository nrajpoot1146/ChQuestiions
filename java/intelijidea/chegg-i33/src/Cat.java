public class Cat extends Pet{
    private String coatColor;

    public void setCoatColor(String coatColor) {
        this.coatColor = coatColor;
    }

    public String getCoatColor() {
        return coatColor;
    }

    public String speak(){
        return "Meow Meow Meow\n" +
                "Meow Meow Meow.";
    }
}
