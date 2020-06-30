import java.util.ArrayList;

public class Colour {
    private final int r;
    private final int g;
    private final int b;
    private static ArrayList<Colour> arrayList = new ArrayList<Colour>();
    private Colour(int r, int g, int b){
        this.r = r;
        this.g = g;
        this.b = b;
    }

    public static Colour fromRGB(int r, int g, int b){
        if(r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255){
            throw new IllegalArgumentException("invalid arg message");
        }

        Colour res = find(r, g, b);
        if(res == null){
            res = new Colour(r, g, b);
        }
        return res;
    }

    private static Colour find(int r, int g, int b){
        if(Colour.arrayList.size() <= 0){
            return null;
        }
        for(Colour c : arrayList){
            if(c.getR() == r && c.getG() == g && c.getB() == b){
                return c;
            }
        }

        return null;
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
