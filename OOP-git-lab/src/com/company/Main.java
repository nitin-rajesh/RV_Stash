package com.company;
import java.sql.Time;
import java.util.*;

public class Main {

    public static void main(String[] args) {

        System.out.println("Enter number: ");
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        /* TimeFormat t1 = new TimeFormat(n);
        t1.printTime();*/
        Combinations count = new Combinations(n);
        System.out.println("Combinations of sum: " + count.getNumberOfCombinations());

        Pattern.printSteps(n);

        int[] listOfNums = new int[]{1,12,7,42,31,17};
        SplitOdds splitMyOdds = new SplitOdds(listOfNums);
        splitMyOdds.printArray();
        int[] nums = new int[3];

        System.out.println("\nEnter 3 numbers ");
        for(int i = 0; i < 3; i++)
            nums[i] = s.nextInt();
        System.out.println(CheckIt.isSameDigit(nums[0],nums[1],nums[2])?"True":"False");

        int[][] array2d = new int[][]{{1,2,3},{4,6,5},{7,9,8}};
        System.out.println("Enter number to search ");
        int val = s.nextInt();
        int[] index = CheckIt.getIndex(array2d, val);
        if(index[0] != -1)
            System.out.println("Found at " + (index[0]+1) + ":" + (index[1]+1));
        else
            System.out.println("Not found");
    }
}
