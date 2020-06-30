

public class EncTable extends Table{

    EncTable(){
        super();
        this.fillData();
    }

    private void fillData(){
        this.map.put('=',' ');
        this.map.put('>','*');
        this.map.put('?','S');
        this.map.put('@','5');

        this.map.put('A','0');
        this.map.put('B','Y');
        this.map.put('C','r');
        this.map.put('D','@');
        this.map.put('E','.');
        this.map.put('F','`');
        this.map.put('G','x');
        this.map.put('H','s');
        this.map.put('I','6');
        this.map.put('J','a');
        this.map.put('K','7');
        this.map.put('L','"');
        this.map.put('M','i');
        this.map.put('N','v');
        this.map.put('O','4');
        this.map.put('P','^');
        this.map.put('Q',',');
        this.map.put('R','m');
        this.map.put('S','>');
        this.map.put('T','N');
        this.map.put('U','[');
        this.map.put('V','Z');
        this.map.put('W','L');
        this.map.put('X','2');
        this.map.put('Y','?');
        this.map.put('Z','C');

        this.map.put('[',';');
        this.map.put('\\','Q');
        this.map.put(']','3');
        this.map.put('^','E');
        this.map.put('_','f');

        this.map.put('a','+');
        this.map.put('b','d');
        this.map.put('c','#');
        this.map.put('d','e');
        this.map.put('e','D');
        this.map.put('f','/');
        this.map.put('g','R');
        this.map.put('h','&');
        this.map.put('i','9');
        this.map.put('j','A');
        this.map.put('k','P');
        this.map.put('l','X');
        this.map.put('m','G');
        this.map.put('n','U');
        this.map.put('o','w');
        this.map.put('p','u');
        this.map.put('q',':');
        this.map.put('r','8');
        this.map.put('s','K');
        this.map.put('t','_');
        this.map.put('u','o');
        this.map.put('v','=');
        this.map.put('w','l');
        this.map.put('x','J');
        this.map.put('y','B');
        this.map.put('z','<');

        this.map.put('9','V');
        this.map.put('1','c');
        this.map.put('#','T');
        this.map.put(' ','1');
        this.map.put('7','j');
    }

}
