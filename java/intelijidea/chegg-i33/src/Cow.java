public class Cow {
    String type;

    /**
     * set type of cow
     * @param type of cow
     */
    public void setType(String type) {
        this.type = type;
    }

    /**
     *
     * @return type of cow
     */
    public String getType() {
        return type;
    }

    /**
     *
     * @return sound of cow
     */
    public String speak(){
        return "Moo! moooo!";
    }
}
