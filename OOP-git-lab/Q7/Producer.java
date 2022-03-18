public class Producer extends Thread implements Runnable {
    private Product data;
    private int number;
    public Producer(Product data, int number){
        this.data = data;
        this.number = number;
    }
    public void run() {
        String[] fruits = {"Apple","Orange","Grape","Watermelon"};
        while (true) {
            int i;
           data.put(i = (int)Math.floor(Math.random()*4));
           System.out.println("Producer #" + this.number + " put: " + fruits[i]);
           try {
              java.lang.Thread.sleep(500);
           } catch (InterruptedException e) { }
        } 
     }
}
