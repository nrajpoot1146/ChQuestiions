public class Node {
    public Node next;
    public TrainCar car;
    public Node previous;

    /**
     *
     * @param previous node
     * @param next node
     * @param name car or engine
     * @param cargo cost
     */
    public Node(Node previous, Node next, String name, double cargo){
        this.car = new TrainCar();
        this.next = next;
        this.previous = previous;
        this.car.name = name;
        this.car.cargo = cargo;
    }

    /**
     *
     * @param name car or engine
     * @param cargo cost
     */
    public Node(String name, double cargo){
        this.car = new TrainCar();
        this.car.name = name;
        this.next = null;
        this.previous = null;
        this.car.cargo = cargo;
    }

    /**
     *
     * @param name engine
     */
    public Node (String name){
        this.car = new TrainCar();
        this.car.name = name;
    }
}
