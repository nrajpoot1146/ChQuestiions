class OrderMain {

    public static void main(String[] args) {
        Order o = new Order();
        o.readOrder("order1.txt");
        System.out.println("for order1.txt");
        System.out.println(o.orderInfo());

        Order o2 = new Order();
        o2.readOrder("order2.txt");
        System.out.println();
        System.out.println("for order2.txt");
        System.out.println(o2.orderInfo());
    }

}