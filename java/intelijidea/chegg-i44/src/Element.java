public class Element {
    private int key;
    private String info;
    public Element(int key, String info) {
        this.key=key;
        this.info=info;
    }

    public int getKeyValue() {
        return this.key;
    }

    public String getStringValue() {
        return this.info;
    }
}