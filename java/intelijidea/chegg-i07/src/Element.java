import java.awt.*;

public class Element {
    private Character character;
    private Color color;

    Element(Character c, Color color){
        this.character = c;
        this.color = color;
    }

    Element(){

    }

    public Character getCharacter() {
        return character;
    }

    public Color getColor() {
        return color;
    }

    public void setCharacter(Character character) {
        this.character = character;
    }

    public void setColor(Color color) {
        this.color = color;
    }
}
