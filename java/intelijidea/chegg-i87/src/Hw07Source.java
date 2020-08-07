public class Hw07Source {
    public static void main(String... args) {
        // array of Statement string
        String[] statements= {
                "divide 100.0 50.0",
                "add 25.0 92.0",
                "subtract 225.0 17.0",
                "multiply 11.0 3.0"
        };

        // create a DynamicHelper object
        DynamicHelper dynamicHelper = new DynamicHelper(
                new Adder(),
                new Subtractor(),
                new Multiplier(),
                new Divider()
        );

        // solve all statements
        // display result
        for (String statement : statements){
            String result = null;
            try {
                result = dynamicHelper.process(statement);
                System.out.println(result);
            } catch (InvalidStatementException e) {
                System.out.println(e.getMessage());;
            }
        }

    }
}
