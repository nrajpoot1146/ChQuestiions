import javafx.application.Application;
import javafx.event.ActionEvent;
import javafx.event.EventHandler;
import javafx.geometry.Pos;
import javafx.scene.Scene;
import javafx.scene.control.Button;
import javafx.scene.control.Label;
import javafx.scene.control.RadioButton;
import javafx.scene.control.TextField;
import javafx.scene.control.ToggleGroup;
import javafx.scene.layout.GridPane;
import javafx.scene.layout.VBox;
import javafx.stage.Stage;

public class Solution extends Application{
	private ToggleGroup group;
	private  RadioButton button1, button2;
	private Button calculate;
	private Label labelMajor, answer, labelRequired, labelEarnCredit;
	private TextField txtMajor, txtRequired, txtEarnCredit;
	private VBox root;
	private Scene scene;
	private GridPane grid;
	public static void main(String[] args) {
		launch(args);
	}

	@Override
	public void start(Stage primaryStage) throws Exception {
		group = new ToggleGroup();  
	    button1 = new RadioButton("Undergraduate");  
	    button1.setSelected(true);
	    button2 = new RadioButton("Graduate");
	    button1.setToggleGroup(group);
	    button2.setToggleGroup(group);
	    
	    calculate = new Button("Calculate Remaining Credit Hours");
	    answer = new Label("Answer");
	    answer.setAlignment(Pos.BASELINE_CENTER);
	    answer.setId("answer");
	    
		grid = new GridPane();
		grid.setAlignment(Pos.CENTER);
	   
		labelMajor = new Label("Enter Major");
		txtMajor = new TextField();
		grid.addRow(0, labelMajor, txtMajor);
		
		labelRequired = new Label("Enter total required credit: ");
		txtRequired = new TextField();
		grid.addRow(1, labelRequired, txtRequired);
		
		labelEarnCredit = new Label("Enter the earned credit:  ");
		txtEarnCredit = new TextField();
		grid.addRow(2, labelEarnCredit, txtEarnCredit);
		grid.setHgap(50);
		grid.setVgap(5);
		
		
        root = new VBox();
        scene = new Scene(root,600,300);
        root.getChildren().addAll(button1,button2,grid, calculate, answer);
        root.setId("root");
        root.getStylesheets().add("style.css");
        primaryStage.setScene(scene); 
        primaryStage.show();
        this.setListener();
	}
	
	private void setListener() {
		calculate.setOnAction(new EventHandler<ActionEvent>() {
			
			@Override
			public void handle(ActionEvent arg0) {
				String Deg = "";
				if(button1.isSelected()) {
					Deg = button1.getText().toString();
				}else {
					Deg = button2.getText().toString();
				}
				
				String major = txtMajor.getText().toString();
				int reqHour = Integer.parseInt(txtRequired.getText());
				int earnHour = Integer.parseInt(txtEarnCredit.getText().toString());
				
				int remainingHour = reqHour - earnHour;
				
				String res = "";
				res += "You are in the "
						+ Deg
						+ " program."
						+ "Your major is "
						+ major
						+ ". Your total remaining credits are: "
						+ remainingHour;
						
				answer.setText(res); // update answer
			}
		});
	}

}
