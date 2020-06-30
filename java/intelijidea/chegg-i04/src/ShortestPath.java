import java.util.Scanner;

public class ShortestPath {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String line1 = sc.nextLine();
        String line2 = sc.nextLine();

        Path firstPath = new Path(line1);
        Path secondPath = new Path(line2);

        double pathLength = getPathLength(firstPath);
        firstPath.setPathLength(pathLength);

        pathLength = getPathLength(secondPath);
        secondPath.setPathLength(pathLength);

        Path sortestPath = null;
        if(firstPath.getPathLength() < secondPath.getPathLength()){
            sortestPath = firstPath;
        }else{
            sortestPath = secondPath;
        }

        System.out.println(firstPath.getName() +": "+firstPath.getPathLength());
        System.out.println(secondPath.getName() +": "+secondPath.getPathLength());
        System.out.println(sortestPath.getName()+": "+sortestPath.getPathLength());

        sc.close();
    }

    public static double getPathLength(Path path){
        double pathLenngth = distance2p(path.getP1(), path.getP2()) + distance2p(path.getP2(), path.getP3());
        return pathLenngth;
    }

    public static double sqr(double num){
        return num * num;
    }

    public static double distance2p(Pair p1, Pair p2){
        double res = sqr(p1.x - p2.x) + sqr(p1.y - p2.y);
        res = Math.sqrt(res);
        return res;
    }
}

class Path{
    private String name;
    private Pair p1;
    private Pair p2;
    private Pair p3;
    private double pathLength;

    Path(String str){
        String[] data = str.split(" ");
        this.name = data[0];
        this.p1 = new Pair(data[1],data[2]);
        this.p2 = new Pair(data[3],data[4]);
        this.p3 = new Pair(data[5],data[6]);
    }

    public Pair getP1(){
        return this.p1;
    }

    public Pair getP2() {
        return p2;
    }

    public Pair getP3() {
        return p3;
    }

    public String getName() {
        return name;
    }

    public void setPathLength(double pathLength){
        this.pathLength = pathLength;
    }

    public double getPathLength() {
        return pathLength;
    }

}

class Pair{
    double x;
    double y;

    Pair(double x, double y){
        this.x = x;
        this.y = y;
    }

    Pair(String x, String y){
        this.x = Double.parseDouble(x);
        this.y = Double.parseDouble(y);
    }

}
