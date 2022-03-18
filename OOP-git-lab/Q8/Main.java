import java.util.Scanner;


interface PerformOperation{
    boolean check(int value);
}
public class Main{
    static boolean check(PerformOperation op, int value){
        return op.check(value);
    }
    public static void main(String[] args){
        System.out.println("1. isOdd   2. isPrime   3. isPalindrome");
        Scanner input = new Scanner(System.in);
        int ip;
        String operation = "";
        PerformOperation function;
        
        do{
            System.out.println("Enter num: ");
            ip = input.nextInt();
            int value = input.nextInt();
            switch(ip){
                case 1:
                    operation = " is odd? ";
                    function = (int val)->{
                        return !(val%2==0);
                    };
                    break;
                case 2:
                    operation = " is prime? ";
                    function = (int n)->{
                        if (n <= 1)
                            return false;
                
                        for (int i = 2; i < n/2; i++)
                            if (n % i == 0)
                                return false;
                
                        return true;
                    };
                    break;
                default:
                operation = " is palindrome? ";
                    function = (int val)->{
                    int n = val;
                    int sum = 0;
                    while(n>0){    
                        int r=n%10;  //getting remainder  
                        sum=(sum*10)+r;    
                        n=n/10;    
                    }   
                    if(val==sum)    
                        return true;    
                    else    
                        return false;    
                      
                };
            }
            System.out.println(value + "" + operation + "" + function.check(value));
            input.close();
        
        }while( ip > 0);
    }
}