import java.util.ArrayList;
import java.util.Scanner;


public class Main{
    static String spacePrint(String Word){
        int len = Word.length();
        String spaceStr = new String(" ");
        for(int i = 0; i < 10 - len; i++){
            spaceStr = spaceStr + " ";
        }
        return spaceStr;
    }
    public static void main(String[] args){
        ArrayList<Student> students = new ArrayList<Student>();
        ArrayList<Employee> employees = new ArrayList<Employee>();
        ArrayList<College> colleges = new ArrayList<College>();
        Student temp1;
        College temp2;
        Employee temp3;
        System.out.println("1. Add student   2. Add college   3. Add employee");
        System.out.println("4. Print students   5. Print colleges   6. Print employees");
        int c;
        Scanner input = new Scanner(System.in);
        do {
            c = input.nextInt();
            switch (c) {
                case 1:
                    temp1 = new Student();
                    System.out.println("Enter name: ");
                    temp1.setName(System.console().readLine());
                    System.out.println("Enter address: ");
                    temp1.Addr.getAddress();
                    System.out.println("Enter USN");
                    temp1.setUSN(System.console().readLine());
                    students.add(temp1);
                    break;
                case 2:
                    temp2 = new College();
                    System.out.println("Enter name: ");
                    temp2.setName(System.console().readLine());
                    System.out.println("Enter address: ");
                    temp2.Addr.getAddress();
                    colleges.add(temp2);
                    break;
                case 3:
                    temp3 = new Employee();
                    System.out.println("Enter name: ");
                    temp3.setName(System.console().readLine());
                    System.out.println("Enter address: ");
                    temp3.Addr.getAddress();
                    System.out.println("Enter USN");
                    temp3.setName(System.console().readLine());
                    employees.add(temp3);
                case 4:
                    System.out.println("*Students*\n Name \t USN \t Address");
                    for(int i = 0; i < students.size(); i++){
                        temp1 = students.get(i);
                        System.out.println(temp1.getName() + Main.spacePrint(temp1.getName()) + temp1.getUSN() + Main.spacePrint(temp1.getUSN()) + temp1.Addr.fullAddress());
                    }
                    System.out.println();
                    break;
                case 5:
                    System.out.println("College  \t Address");
                    for(int i = 0; i < colleges.size(); i++){
                        temp2 = colleges.get(i);
                        System.out.println(temp2.getName() + Main.spacePrint(temp2.getName()) + temp2.Addr.fullAddress());
                    }
                    System.out.println();
                    break;
                case 6:
                    System.out.println("Name \t USN \t Address");
                    for(int i = 0; i < employees.size(); i++){
                        temp3 = employees.get(i);
                        System.out.println(temp3.getName() + Main.spacePrint(temp3.getName()) + temp3.getEmpID() + Main.spacePrint(temp3.getEmpID()) + temp3.Addr.fullAddress());
                    }
                    System.out.println();
                    break;
            }
        }while(c > 0);
    }
};