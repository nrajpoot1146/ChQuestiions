import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;
import java.util.Set;

public class Solution {

    /**
     * main function
     * @param args command line argument
     */
    public static void main(String[] args){
        // list of map
        ArrayList<HashMap<String, Integer>> mapList = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);
        String line = scanner.nextLine();
        // split line with regex "}, "
        String[] lines = line.split("}, ");

        // generate map and add into arraylist
        for (String str : lines){
            // new hash map
            HashMap<String, Integer> map = new HashMap<>();

            // remove unwanted [{ or } from line
            if (!str.contains("}"))
                str = str.substring(str.indexOf("{")+1);
            else
                str = str.substring(str.indexOf("{")+1, str.indexOf("}"));

            // array of string of keyValue pair
            // format key=value;
            String[] keyValuePairs = str.split(", ");

            for (String keyValuePair : keyValuePairs){
                // get key from keyValuePair String
                String key = keyValuePair.substring(0,keyValuePair.indexOf("="));
                // get value from keyValuePair String
                Integer value = Integer.parseInt(keyValuePair.substring(keyValuePair.indexOf("=")+1));
                // put key and value pair in map
                map.put(key, value);
            }

            // put map into mapList
            mapList.add(map);
        }

        // concatenate all map into a single map
        HashMap<String, Integer> resMap = concatenate(mapList);
        System.out.println(resMap.toString());

        scanner.close();
    }

    /**
     * required function
     * function to concatenate list of maps into a single map
     * @param mapList list of maps
     * @return single map generated after concatenation of maps of mapList
     */
    public static HashMap<String, Integer> concatenate(ArrayList<HashMap<String, Integer>> mapList){
        // new map to store final result
        HashMap<String, Integer> res = new HashMap<>();
        for (HashMap<String, Integer> map : mapList){
            // get set of all key of map
            Set<String> keys = map.keySet();

            for (String key : keys){
                // if key is not present in resultant map
                // then put key value in result map
                if (!res.containsKey(key)){
                    res.put(key, map.get(key));
                }
            }
        }
        // return final map
        return res;
    }
}