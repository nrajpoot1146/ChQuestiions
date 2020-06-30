import java.util.ArrayList;
import java.util.Collections;

public class TestAutos {

    public static void main(String[] args){
        ArrayList<Automobile> automobiles = new ArrayList<Automobile>();

        automobiles.add(new Automobile("first",2010,20000));
        automobiles.add(new Automobile("second",2019,20500));
        automobiles.add(new Automobile("third",2015,80000));
        automobiles.add(new Automobile("fourth",2011,90000));
        automobiles.add(new Automobile("fifth",2016,10000));

        for(int i = 0; i<automobiles.size(); i++){
            automobiles.get(i).display();
        }

        System.out.println();
        System.out.println();

        Collections.sort(automobiles,Automobile::compareTo);

        for(Automobile automobile : automobiles){
            automobile.display();
        }
    }
}
