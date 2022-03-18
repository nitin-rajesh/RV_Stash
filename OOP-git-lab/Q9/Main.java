import java.util.*;
import java.util.stream.Collectors;

class Temp{
    int a;
}

public class Main{
    
    ArrayList<String> strlist = new ArrayList<>();
    String[] strArr = new String[strlist.size()];
    ArrayList<String> reverselist = new ArrayList<>();

    static String[] copyToArray(ArrayList<String> listOfStr){
        String[] arrOfStr = new String[listOfStr.size()];
        int i = 0;
        for(String str: listOfStr){
            arrOfStr[i++] = str;
        }
        return arrOfStr;
    }

    static ArrayList<String> copyToArrayList(List<String> list){
        ArrayList<String> content = new ArrayList();
        for(String element: list){
            content.add(element);
        }
        return content;
    }

    static ArrayList<String> reverseList(ArrayList<String> list){
        ArrayList revlist = new ArrayList();
        for(String element: list){
            revlist.add(0,element);
        }
        return revlist;
    }

    static List<String> subList(ArrayList<String> fullList, int start, int end){
        return fullList.subList(start,end);
    }

    
    public static void main(String[] args) throws Exception{
        System.out.println("How many strings");
        int val = Integer.parseInt(System.console().readLine());
        ArrayList<String> list = new ArrayList<>();
        while(val-- > 0)
            list.add(System.console().readLine());
    
        System.out.println("1.Copy List to ArrayList  2.Copy ArrayList to array");
        System.out.println("3. Reverse an arrayList   4. Get a sublist");
        System.out.println("5. Sort an arrayList      6. Clone an arraylist");

        do{
            val = Integer.parseInt(System.console().readLine());

            switch(val){
                case 1 -> System.out.println(copyToArrayList(list));
                case 2 -> System.out.println(Arrays.toString(copyToArray(list)));
                case 3 -> System.out.println(reverseList(list));
                case 4 -> System.out.println(subList(list, new Scanner(System.in).nextInt(), new Scanner(System.in).nextInt()));
                case 5 -> System.out.println(list.stream().sorted().collect(Collectors.toList()));
                case 6 -> System.out.println(list.clone());
            }

        }while(val != 0);
        
    }
  
}