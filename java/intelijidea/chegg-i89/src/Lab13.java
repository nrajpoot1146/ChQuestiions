import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class Lab13 {
    // main function
   public static void main(String[] args){
       // declare and initialize name
       ArrayList<Character> name = new ArrayList<Character>();
       // add character of first name
       name.add('b');
       name.add('o');
       name.add('b');

       RedundantCharacterMatch(name);

       // declare and initialize name1
       ArrayList<Character> name1 = new ArrayList<Character>();
       // add twice character of name
       name1.add('b');
       name1.add('o');
       name1.add('b');
       name1.add('b');
       name1.add('o');
       name1.add('b');
       RedundantCharacterMatch(name1);
   }

   public static void RedundantCharacterMatch(ArrayList<Character> name){
       // declare a hash map
       Map<Character, String> map = new HashMap<>();
       for(int i = 0; i<name.size();i++){ // retrieve all arrayList name
           if (!map.containsKey(name.get(i))){ // check map has current character as key or not
               map.put(name.get(i), Integer.toString(i)); // if key is not present then add it
           } else{
               String str = map.get(name.get(i));
               str = str + ", " + i;
               map.replace(name.get(i), str); // if present then update index
           }
       }
       for(Character x : map.keySet())
           System.out.println(x +": " +map.get(x)); // print output
   }
}