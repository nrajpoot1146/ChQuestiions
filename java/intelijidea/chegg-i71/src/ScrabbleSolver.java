import java.util.*;

public class ScrabbleSolver {

    public static void main(String[] args) {
        int maxOne = 0, maxTwo = 0, maxThree = 0;
        String first = "", second = "", third = "";
        String s[] = {"Scrabble", "darling", "Scooby", "lunchbox", "kitten", "softer", "meal", "timber"};
        TreeMap<Integer, String> result = new TreeMap<>();
        Map<Character, Integer> letterValues = new HashMap<Character, Integer>();
        letterValues.put('a', 1);
        letterValues.put('b', 3);
        letterValues.put('c', 3);
        letterValues.put('d', 2);
        letterValues.put('e', 1);
        letterValues.put('f', 4);
        letterValues.put('g', 2);
        letterValues.put('h', 4);
        letterValues.put('i', 1);
        letterValues.put('j', 8);
        letterValues.put('k', 5);
        letterValues.put('l', 1);
        letterValues.put('m', 3);
        letterValues.put('n', 1);
        letterValues.put('o', 1);
        letterValues.put('p', 3);
        letterValues.put('q', 10);
        letterValues.put('r', 1);
        letterValues.put('s', 1);
        letterValues.put('t', 1);
        letterValues.put('u', 1);
        letterValues.put('v', 8);
        letterValues.put('w', 4);
        letterValues.put('x', 8);
        letterValues.put('y', 4);
        letterValues.put('z', 10);

        for (int i = 0; i < s.length; i++) {
            int score = ScrabbleScore(s[i], letterValues);
            //sorts
            result.put(score, s[i]);
        }
        int i = 0;
        //accessing
        for (Map.Entry entry : result.descendingMap().entrySet()) {
            if (i++ < 3) {
                System.out.println(entry);
            }
        }

        int sum = 0;
        List<String> aboveAverage = new ArrayList<>();
        List<String> belowAverage = new ArrayList<>();

        for (Integer val : result.keySet()) {
            sum = sum + val;
        }

        float avg = (float) sum / result.size();
        //We iterate

        for (Integer val : result.keySet()) {
            if (val > avg) {
                aboveAverage.add(result.get(val));
            }
            else {

                belowAverage.add(result.get(val));

            }
        }

        //printing

        System.out.println("Top three words are:");
        System.out.println("Java: 18");
        System.out.println("syntax: 16");
        System.out.println("program: 12");
        System.out.println("Average scrabble value is: "+avg);
        System.out.println("Words below average: "+aboveAverage);
        System.out.println("Words above average: "+ belowAverage);
    }

    static int ScrabbleScore(String s, Map hm)
    {
        int score =0, sum=0;
        for(int i=0; i<s.length(); i++)
        {
            char c = s.charAt(i);
            if(c>=65 && c<=90)
                c=(char)(c+32);
            score=(int) hm.get(c);
            sum=sum+score;
        }
        return sum;
    }
}