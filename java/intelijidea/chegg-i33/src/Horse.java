public class Horse extends Pet{
    private String color;

    /**
     * set color of horse
     * @param color of horse
     */
    public void setColor(String color) {
        this.color = color;
    }

    /**
     *
     * @return color of horse
     */
    public String getColor() {
        return color;
    }

    /**
     *
     * @return sound of horse
     */
    public String speak(){
        return "Neigh! neigh! neigh!";
    }
}
