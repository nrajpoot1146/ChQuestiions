import javax.swing.*;
import java.awt.*;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class PanelDemo extends JFrame implements ActionListener { // old : public class PanelDemo extends JFrame {

    public static void main (String[] args){
        PanelDemo guiWithPanel = new PanelDemo();
        guiWithPanel.setVisible(true);
    }

    public PanelDemo()
    {
        setSize(300, 300);
        setTitle("Panel Demonstration");
        Container contentPane = getContentPane();
        contentPane.setBackground(Color.BLUE);
        contentPane.setLayout(new BorderLayout());
        JButton stopButton = new JButton("Red");
        stopButton.setBackground(Color.RED);
        stopButton.addActionListener(this);
        contentPane.add(stopButton,BorderLayout.SOUTH);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        if (e.getActionCommand().equals("Red")) {
            // old : setBackground(Color.RED);
            Container contentPane = getContentPane();
            contentPane.setBackground(Color.RED);
        }
    }
}
