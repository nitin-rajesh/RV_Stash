class Consumer extends Thread implements Runnable {
    private Product data;
    private int number;
    
    public Consumer(Product c, int number) {
       data = c;
       this.number = number;
    }
    public void run() {
        String[] fruits = {"Apple","Orange","Grape","Watermelon"};
        
        int value;
       while(true){
         try{
            sleep(2021);
         }catch(InterruptedException e){}
          value = data.get();
          System.out.println("Consumer #" + this.number + " got: " + fruits[value]);
          
       }
    }
 }