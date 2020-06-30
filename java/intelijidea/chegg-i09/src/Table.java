import java.util.HashMap;
import java.util.Map;

public class Table {
    protected Map<Character, Character> map;

    Table(){
        map = new HashMap<Character, Character>();
    }
    public Character getAt(Character character){
        return map.get(character);
    }

    public Character getAt(Character character, int n){
        int i=1;
        Character res = character;
        if(n == 0){
            return character;
        }
        while(i<=n){
            res = this.map.get(res);
            i++;
        }
        return res;
    }
}
