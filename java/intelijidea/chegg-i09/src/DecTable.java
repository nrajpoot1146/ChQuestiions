public class DecTable extends Table{
    DecTable(){
        super();
        fillData();
    }

    private void fillData(){
        this.map.put(' ','=');
        this.map.put('*','>');
        this.map.put('S','?');
        this.map.put('5','@');

        this.map.put('0','A');
        this.map.put('Y','B');
        this.map.put('r','C');
        this.map.put('@','D');
        this.map.put('.','E');
        this.map.put('`','F');
        this.map.put('x','G');
        this.map.put('s','H');
        this.map.put('6','I');
        this.map.put('a','J');
        this.map.put('7','K');
        this.map.put('"','L');
        this.map.put('i','M');
        this.map.put('v','N');
        this.map.put('4','O');
        this.map.put('^','P');
        this.map.put(',','Q');
        this.map.put('m','R');
        this.map.put('>','S');
        this.map.put('N','T');
        this.map.put('[','U');
        this.map.put('Z','V');
        this.map.put('L','W');
        this.map.put('2','Z');
        this.map.put('?','Y');
        this.map.put('C','Z');

        this.map.put(';','[');
        this.map.put('Q','\\');
        this.map.put('3',']');
        this.map.put('E','^');
        this.map.put('f','_');

        this.map.put('+','a');
        this.map.put('d','b');
        this.map.put('#','c');
        this.map.put('e','d');
        this.map.put('D','e');
        this.map.put('/','f');
        this.map.put('R','g');
        this.map.put('&','h');
        this.map.put('9','i');
        this.map.put('A','j');
        this.map.put('P','k');
        this.map.put('X','l');
        this.map.put('G','m');
        this.map.put('U','n');
        this.map.put('w','o');
        this.map.put('u','p');
        this.map.put(':','q');
        this.map.put('8','r');
        this.map.put('K','s');
        this.map.put('_','t');
        this.map.put('o','u');
        this.map.put('=','v');
        this.map.put('l','w');
        this.map.put('J','x');
        this.map.put('B','y');
        this.map.put('<','z');

        this.map.put('V','9');
        this.map.put('c','1');
        this.map.put('T','#');
        this.map.put('1',' ');
        this.map.put('j','7');
    }
}
