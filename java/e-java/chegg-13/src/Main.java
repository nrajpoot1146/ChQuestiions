import java.awt.Color;
import java.awt.Component;
import java.awt.Container;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.Insets;
import java.awt.LayoutManager;

import javax.swing.Box;
import javax.swing.BoxLayout;
import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;
import javax.swing.JTextField;

public class Main {
	private static JFrame mainFrame;
	
	private static JPanel menuPanel;
	private static JPanel headerPanel;
	private static JPanel consolepanel;
	
	private static JTextField heading;
	private static JTextField sideHeading;
	private static JTextField editText;
	private static JTextArea console;
	
	private static JButton signUp;
	private static JButton reset;
	private static JButton showCustomerLine;
	private static JButton showFrontCustomer;
	private static JButton showlineSize;
	private static JButton serveNextCustomer;
	private static JButton clear;
	private static JButton exit;

	public static void main(String[] args) {
		createUi();
	}
	
	private static void createUi() {
		mainFrame = new JFrame();
		mainFrame.setSize(700, 500);
		mainFrame.setLocationRelativeTo(null);
		mainFrame.setLocale(null);
		mainFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		
		menuPanel = new JPanel();
		menuPanel.setSize(200, 370);
		menuPanel.setLocation(0, 130);
		
		
		editText = new JTextField(15);
		menuPanel.add(editText);
		menuPanel.add(Box.createRigidArea(new Dimension(200, 3)));
		signUp = new JButton("Sign Up");
		menuPanel.add(signUp);
		
		reset = new JButton("Reset");
		menuPanel.add(reset);
		menuPanel.add(Box.createRigidArea(new Dimension(200, 10)));
		
		showCustomerLine = new JButton("Output Customer Line");
		menuPanel.add(showCustomerLine);
		menuPanel.add(Box.createRigidArea(new Dimension(200, 2)));
		
		showFrontCustomer = new JButton("Check Front Customer");
		menuPanel.add(showFrontCustomer);
		menuPanel.add(Box.createRigidArea(new Dimension(200, 2)));
		
		showlineSize = new JButton("Check Line Size");
		menuPanel.add(showlineSize);
		menuPanel.add(Box.createRigidArea(new Dimension(200, 2)));
		
		serveNextCustomer = new JButton("Serve Next Customer");
		menuPanel.add(serveNextCustomer);
		menuPanel.add(Box.createRigidArea(new Dimension(200, 50)));
		
		clear = new JButton("Clear");
		menuPanel.add(clear);
		
		exit = new JButton("Exit");
		menuPanel.add(exit);
		
		headerPanel = new JPanel();
		headerPanel.setSize(700, 70);
		headerPanel.setLocation(0, 0);
		
		headerPanel.add(Box.createRigidArea(new Dimension(20, 60)));
		sideHeading = new JTextField("Customer Sign up");
		sideHeading.setEditable(false);
		Font f = new Font("Times New Roman", Font.BOLD, 15);
		sideHeading.setLocation(100, 100);
		sideHeading.setFont(f);
		headerPanel.add(sideHeading);
		
		headerPanel.add(Box.createRigidArea(new Dimension(100, 60)));
		heading = new JTextField("Welcome to DMV");
		heading.setEditable(false);
		heading.setBackground(new Color(196,38,12));
		Font font = new Font("Times New Roman", Font.BOLD, 50);
		heading.setFont(font);
		heading.setForeground(Color.white);
		heading.setBounds(300, 50, 10, 10);
		headerPanel.add(heading);
		
		consolepanel = new JPanel();
		consolepanel.setSize(500,370);
		consolepanel.setLocation(200, 130);
		consolepanel.setBackground(Color.yellow);
		
		console = new JTextArea(100, 300);
		console.setBackground(Color.white);
		console.setBounds(0, 0, 500, 300);
		consolepanel.add(console);
		
		mainFrame.add(headerPanel);
		mainFrame.add(menuPanel);
		mainFrame.add(consolepanel);
		mainFrame.add(new JPanel());
		mainFrame.setVisible(true);
	}

}
