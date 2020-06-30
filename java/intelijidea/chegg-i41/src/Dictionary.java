import java.util.ArrayList;
import java.util.HashMap;

public class Dictionary {
    public static void main(String[] args){
        HashMap<String, ArrayList<String>> dict = new HashMap<String, ArrayList<String>>();

        ArrayList<String> defOfFix = new ArrayList<String>();
        defOfFix.add("Make something stay in place");
        defOfFix.add("Repair something");
        // add word Fix and its definition to dictionary
        dict.put("Fix", defOfFix);

        ArrayList<String> defOfRun = new ArrayList<String>();
        defOfRun.add("Move with an increased pace");
        // add word Run and its definition to dictionary
        dict.put("Run", defOfRun);

        // check word Build is present in dictionary or not
        if(dict.containsKey("Build")){
            System.out.println("Build is present");
        }else{
            System.out.println("Build is not present");
        }

        // get definition of word Fix
        ArrayList<String>  defOfFixGet = dict.get("Fix");
        System.out.println();
        System.out.println("Definition of word Fix: ");
        for (String def : defOfFixGet){
            System.out.println(def);
        }

        // get definition of word Run
        ArrayList<String>  defOfRunGet = dict.get("Run");
        defOfRunGet.add("Execute a program");

        // update definition of word Run using replace method
        dict.replace("Run", defOfRunGet);

        System.out.println();
        // print number of key value pair in dictionary
        System.out.println("key value pair in dictionary: "+ dict.size());
    }
}
