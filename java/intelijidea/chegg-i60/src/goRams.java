
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class goRams {
    static // Step 1 Part A
            ArrayList<csuRam> rams = new ArrayList<csuRam>();

    // Step 1 Part B
    public void createRams(String filename) {
        try {
            Scanner scnr = new Scanner(new File(filename));
            while(scnr.hasNextLine()) {
                String name = scnr.next() + " " + scnr.next();
                int id = scnr.nextInt();
                rams.add(new csuRam(name, id));
            }
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
    }

    public String listFormat() {
        StringBuilder s = new StringBuilder();
        for(csuRam c : rams) {
            s.append(c);
            s.append('\n');
        }
        return s.toString();

    }
    // Step 4
    public void sortList(String check) {
        csuRam.compareData = check.equals("name");
        Collections.sort(rams);
    }

    // Step 5
    public int findTonyFrank() {
        sortList("name");
        csuRam tony = new csuRam("Tony Frank", 888888888);
        return Collections.binarySearch(rams, tony);
    }

}