import java.awt.*;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.concurrent.TimeUnit;

public class nCanvas extends Canvas {

    private Rect rectGreen;
    private Rect rectRed;

    /**
     * constructor to initialize initial state of canvas
     * set background of canvas
     * set size of canvas
     * attach mouse click listener
     * put initial state of rectangles
     */
    nCanvas(){

        setSize(700,200);
        setBackground(Color.GRAY);

        this.rectGreen = new Rect(20, 50,100,100);
        this.rectGreen.setColor(Color.GREEN);

        this.rectRed = new Rect(435,65,70,70);
        this.rectRed.setColor(Color.RED);

        // listener to listen mouse click event on canvas window
        this.addMouseListener(new MouseListener() {
            @Override
            public void mouseClicked(MouseEvent e) {
                int x = e.getX();
                int diff = x - rectGreen.x;

                // thread to move green rect
                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        int temp = diff/100;
                        if (temp<0){
                            temp = temp * -1;
                            temp+=1;
                        }
                        for (int i = 0; i < temp; i++){
                            if (diff > 0) {
                                if (rectGreen.x < rectGreen.xO + 400)
                                    rectGreen.moveRight();
                                else
                                    break;
                            }
                            else {
                                if (rectGreen.x > rectGreen.xO)
                                    rectGreen.moveLeft();
                                else
                                    break;
                            }
                            ((nCanvas) e.getSource()).repaint();
                            try {
                                TimeUnit.SECONDS.sleep(1);
                            } catch (InterruptedException interruptedException) {
                                interruptedException.printStackTrace();
                            }
                        }
                    }
                }).start();

            }

            @Override
            public void mousePressed(MouseEvent e) {

            }

            @Override
            public void mouseReleased(MouseEvent e) {

            }

            @Override
            public void mouseEntered(MouseEvent e) {

            }

            @Override
            public void mouseExited(MouseEvent e) {

            }
        });
    }

    /**
     * paint green and red rect on canvas
     * if red rect inside green rect, change color of red rect to yellow rect;
     * @param g instance of graphics
     */
    @Override
    public void paint(Graphics g) {
        super.paint(g);

        if ( rectRed.isInside(rectGreen) ){
            rectRed.setColor(Color.YELLOW);
        }else{
            rectRed.setColor(Color.RED);
        }

        rectGreen.draw(g);
        rectRed.draw(g);

    }

    /**
     * get instance of red rect
     * @return Rect
     */
    public Rect getRectRed() {
        return rectRed;
    }

    /**
     * get instance of green rec
     * @return Rect
     */
    public Rect getRectGreen() {
        return rectGreen;
    }
}
