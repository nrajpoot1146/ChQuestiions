public class Divider extends CalculateBase implements MathProcessing{
    public Divider() {
    }
    public Divider(double leftValue, double rightValue) {
        super(leftValue, rightValue);
    }
    @Override
    public void calculate() {
        if(getRightValue()==0){
            setResult(0);
            return;
        }
        double value=getLeftValue()/getRightValue();
        setResult(value);
    }

    @Override
    public String getKeyword() {
        return "divide";
    }

    @Override
    public char getSymbol() {
        return '/';
    }

    @Override
    public double doCalculation(double leftValue, double rightValue) {
        setLeftValue(leftValue);
        setRightValue(rightValue);
        calculate();
        return getResult();
    }
}