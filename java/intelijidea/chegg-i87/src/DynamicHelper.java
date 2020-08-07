public class DynamicHelper {
    private MathProcessing[] handlers;

    private double leftValue;
    private double rightValue;

    DynamicHelper(MathProcessing... handlers){
        this.handlers = handlers;
    }

    /**
     * split statement by MathProcessing.SEPARATOR
     * @param statement to be solve
     * @return result string
     * @throws InvalidStatementException
     */
    public String process(String statement) throws InvalidStatementException {
        String[] tokens = statement.split(MathProcessing.SEPARATOR);
        StringBuilder stringBuilder = new StringBuilder();
        if (tokens.length != 3){
            throw new InvalidStatementException("Incorrect number of values",statement);
        }

        try{
            leftValue= Double.parseDouble(tokens[1]);
            rightValue=Double.parseDouble(tokens[2]);
        }catch (NumberFormatException oNumberFormatException){
            throw new InvalidStatementException("Non-numeric data",statement,oNumberFormatException);
        }

        String command = tokens[0];

        // find Math operation and perform it
        for (int i=0; i<handlers.length; i++){
            if (command.equals(handlers[i].getKeyword())){
                double result = handlers[i].doCalculation(leftValue, rightValue);
                stringBuilder.append(leftValue);
                stringBuilder.append(" ");
                stringBuilder.append(handlers[i].getSymbol());
                stringBuilder.append(" ");
                stringBuilder.append(rightValue);
                stringBuilder.append(" = ");
                stringBuilder.append(result);
                return stringBuilder.toString();
            }
        }
        return stringBuilder.toString();
    }
}
