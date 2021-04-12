package com.company;

public class Pattern {
    public static void printSteps(int n){
        int k = 1;
        while(n >= k){
            for(int j = 0; j < k; j++){
                System.out.print("*");
                n--;
            }
            k++;
            System.out.print("\n");
        }
    }
}
