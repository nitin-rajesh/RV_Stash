public class Main{
    public static void main(String[] args){
        Product fruit = new Product();
        Producer[] p = new Producer[5];
        Consumer[] c = new Consumer[5];
        for(int i = 0; i < 5; i++){
            p[i] = new Producer(fruit,i);
            c[i] = new Consumer(fruit,i);
            p[i].start();
            c[i].start();
        }

    }
}