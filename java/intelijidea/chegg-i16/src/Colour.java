import java.util.ArrayList;

public class Colour {
    private final int r;
    private final int g;
    private final int b;
    private static ArrayList<Colour> colourList = new ArrayList<Colour>();
    private Colour(int r, int g, int b){
        this.r = r;
        this.g = g;
        this.b = b;
    }

    /**
     *
     * @param r integer value for red colour
     * @param g integer value for green colour
     * @param b integer value for blue colour
     * @return reference of instance of Colour
     */
    public static Colour fromRGB(int r, int g, int b){
        if(r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255){
            throw new IllegalArgumentException("Invalid RGB values specified");
        }

        Colour res = find(r, g, b); // check is colour available
        if(res == null){
            res = new Colour(r, g, b);
            colourList.add(res);
        }
        return res;
    }

    /**
     *
     * @param r integer value for red colour
     * @param g integer value for green colour
     * @param b integer value for blue colour
     * @return instance of Colour if instance with same colour value is exist in array list otherwise return null
     */
    private static Colour find(int r, int g, int b){
        if(Colour.colourList.size() <= 0){
            return null; // return null if colourList is empty
        }
        for(Colour c : colourList){
            if(c.getR() == r && c.getG() == g && c.getB() == b){
                return c; // return instance of Colour class with same colour value of r, g, b
            }
        }

        return null; // return null if no Colour reference with same r,g,b value found in colourList
    }

    public int getR() {
        return r;
    }

    public int getG() {
        return g;
    }

    public int getB() {
        return b;
    }
}
