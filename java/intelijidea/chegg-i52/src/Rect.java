import java.awt.*;

/**
 * class to represent a rectangle
 * store initial coordinates and current coordinates
 */
public class Rect {
    public int xO,yO,wO,hO;
    public int x,y;
    public int width,height;
    private Color color;

    /**
     *
     * @param x initial x coordinates
     * @param y initial y coordinates
     * @param width initial width
     * @param height initial height
     */
    Rect(int x, int y, int width, int height){
        this.x = this.xO = x;
        this.y = this.yO = y;
        this.width = this.wO = width;
        this.height = this.hO = height;
    }

    /**
     * draw current rect on given graphics panel
     * @param g instance of graphics
     */
    public void draw (Graphics g){
        g.setColor(this.color);
        g.fillRect(this.x, this.y, this.width, this.height);
    }

    /**
     * sets color of rect
     * @param color
     */
    public void setColor(Color color) {
        this.color = color;
    }

    /**
     * get color of rect
     * @return
     */
    public Color getColor() {
        return color;
    }

    /**
     * check current rect is inside other rect or not
     * @param r other rect
     * @return true if current rect is inside, other rect
     */
    public boolean isInside(Rect r){
        if (this.x > r.x && this.x < r.x + r.width && this.y > r.y && this.y < r.y + r.height){
            return true;
        }
        return false;
    }

    /**
     * move right current rect
     */
    public void moveRight(){
        this.x += 100;
    }

    /**
     * move left current rect
     */
    public void moveLeft(){
        this.x -= 100;
    }

    /**
     * reset rect to initial coordinates
     */
    public void reset(){
        this.x = this.xO;
        this.y = this.yO;
        this.width = this.wO;
        this.height = this.hO;
    }
}
