public class main {
    public static void main(String[] args){
        new sample();

    }
}

class sample{
    sample(){
        System.out.println("class name = "+getClass().getSimpleName());
//        new Thread(new Runnable() {
//            @Override
//            public void run() {
//                System.out.println("class name = "+getClass().getSimpleName());
//            }
//        }).start();

        new Thread(() -> {
            System.out.println("class name = "+getClass().getSimpleName());
        }).start();
    }
}
