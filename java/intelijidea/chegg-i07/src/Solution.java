import kotlin.collections.UCollectionsKt;

import javax.swing.*;
import java.awt.*;
import java.sql.Array;
import java.util.ArrayDeque;

public class Solution {
    private static ArrayDeque<Element> arrayDeque = new ArrayDeque<Element>();
    private static JFrame jFrame = new JFrame("new");
    private static JPanel jPanel = new JPanel();
    private static JLabel[][] jLabel = new JLabel[20][50];
    private static int M = 20;
    private static int N = 50;
    private static Element[] element;
    public static void main(String[] args){

        jPanel.setLayout(new FlowLayout());

        for(int i = 0; i< (20*50); i++){
            double d = Math.random();
            Element element = new Element();
            if(d<0.3){
                element.setCharacter('.');
                element.setColor(Color.white);
            }else if(d<0.6){
                element.setCharacter('A');
                element.setColor(Color.WHITE);
            }else {
                element.setCharacter('B');
                element.setColor(Color.BLUE);
            }
            arrayDeque.push(element);
        }


        for (int i=0; i<20; i++){
            for (int j=0; j<50; j++){
                jLabel[i][j] = new JLabel();
                Solution.jPanel.add(jLabel[i][j]);
            }
        }
        update();

        jFrame.add(jPanel);
        jFrame.setLocationRelativeTo(null);
        jFrame.setSize(550,500);
        jFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        jFrame.setVisible(true);
        element = ((Element[]) (arrayDeque.toArray()));
        floodFill(0,0);

    }

    public static void update(){

        for(int i=0; i<20; i++){
            for (int j=0; j<50; j++){
                jLabel[i][j].setOpaque(true);
                jLabel[i][j].setBackground(((Element)(arrayDeque.toArray()[(i*20+j)])).getColor());
                jLabel[i][j].setText(((Element)(arrayDeque.toArray()[(i*20+j)])).getCharacter().toString());
            }
        }
    }

    static void floodFillUtil(int x, int y,
                              Color prevC, Color newC)
    {
        // Base cases
        if (x < 0 || x >= M || y < 0 || y >= N)
            return;
//        if (getElement(x,y).getCharacter() != '.')
//            return;

        if (getElement(x,y).getColor() == prevC && getElement(x,y).getCharacter() == '.') {
            System.out.println(getElement(x, y).getCharacter());
            // Replace the color at (x, y)
            getElement(x, y).setColor(newC);
        }

        // Recur for north, east, south and west
        floodFillUtil(x+1, y, prevC, newC);
        floodFillUtil(x-1, y, prevC, newC);
        floodFillUtil(x, y+1, prevC, newC);
        floodFillUtil(x, y-1, prevC, newC);
    }

    // It mainly finds the previous color on (x, y) and
    // calls floodFillUtil()
    static void floodFill(int x, int y)
    {
        floodFillUtil(x, y, Color.white, Color.cyan);
    }

    static Element getElement(int x,int y){

        return element[x*N+y];
    }
}
