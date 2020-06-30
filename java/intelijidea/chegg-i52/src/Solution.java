import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.WindowAdapter;
import java.awt.event.WindowEvent;
import java.util.concurrent.TimeUnit;

/**
 * class with main function
 */
public class Solution
{
    private nCanvas canvas;
    private Frame f;
    private Button btnStart;
    private Button btnReset;

    /**
     * constructor initialize initial state
     */
    public Solution()
    {
        f= new Frame("Chegg");
        canvas = new nCanvas();

        f.add(this.canvas);

        btnStart = new Button("Start");
        btnStart.setBounds(240,210,80,30);
        btnReset = new Button("Reset");
        btnReset.setBounds(360,210,80,30);
        f.add(btnStart);
        f.add(btnReset);

        f.setBackground(Color.black);
        f.setLayout(null);
        f.setSize(700, 250);
        f.setVisible(true);

        f.addWindowListener(new WindowAdapter() {
            @Override
            public void windowClosing(WindowEvent e) {
                super.windowClosing(e);
                System.exit(0);
            }
        });

        /**
         * attach listener for start button
         */
        btnStart.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {

                // thread to move red rectangle
                new Thread(new Runnable() {
                    @Override
                    public void run() {
                        int i = 0;
                        while (i < 4) {
                            canvas.getRectRed().moveLeft();
                            canvas.repaint();
                            i++;
                            try {
                                TimeUnit.SECONDS.sleep(1);
                            } catch (InterruptedException interruptedException) {
                                interruptedException.printStackTrace();
                            }
                        }
                    }
                }).start();
            }
        });

        /**
         * attach click listener for reset button
         *
         */
        btnReset.addActionListener(new ActionListener() {
            @Override
            public void actionPerformed(ActionEvent e) {
                canvas.getRectRed().reset();
                canvas.getRectGreen().reset();
                canvas.repaint();
            }
        });
    }

    public static void main(String args[])
    {
        Solution solution = new Solution();
        solution.canvas.repaint();
    }
}
