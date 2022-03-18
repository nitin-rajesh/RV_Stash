public class StringPgm {
    String opString;
    static String penultimateWord(String ipString){
        String[] bits = ipString.split(" ");
        if(bits.length > 1)
            return bits[bits.length - 2];
        else
            return "";
    }
    static String swapWords(String ipString){
        String opString = ipString.replace("Java", "Pytemp").replace("Python","Jartemp");
        //System.out.println(opString);
        opString = opString.replace("Jartemp", "Java").replace("Pytemp","Python");
        return opString;
    }
    interface Split{
        String[] subStrings(String temp);
    }

    static boolean checkForRepetitions(int value){
        while(value > 0){
            int digit = value % 10;
            int temp = value;
            while(temp > 0){
                if(digit == temp % 10){
                    return true;
                }
                temp /= 10;
            }
            value /= 10;
        }
        return false;
    }
    public static void main(String[] args){
        int option;
        do{
        option = Integer.valueOf(System.console().readLine());
        System.out.println("Enter string");
        String temp = System.console().readLine();
        switch(option){
            case 1:
                System.out.println(penultimateWord(temp));
                break;
            case 2:
                System.out.println(swapWords(temp));
                break;
            case 3:
                for(String i:temp.split(" "))
                    System.out.println(i);
                break;
        }
        //System.out.println(checkForRepetitions(1024));
        }while(option >= 0);
    }
}