package com.company;
import java.lang.reflect.Array;
import java.util.ArrayList;
import java.util.Collections;

public class SplitOdds {
    ArrayList<Integer> arr;
    public static void sortOut(ArrayList<Integer> arr){
        for(int i = 0; i < arr.size(); i++){
            for(int j = i; j < arr.size(); j++ ){
                if(arr.get(i) % 2 ==0 && arr.get(j) % 2 ==1){
                    Collections.swap(arr, i,j);
                }
            }
        }
    }
    public void fillArray(int[] numbers) {
        for (int i = 0; i < numbers.length; i++) {
            arr.add(numbers[i]);
        }
        sortOut(arr);
    }
    public void printArray(){
        for(int i = 0; i < arr.size(); i++){
            System.out.print(arr.get(i) + "  ");
        }
    }
    SplitOdds(){
        arr = new ArrayList<Integer>();
    }
    SplitOdds(int[] numbers){
        arr = new ArrayList<Integer>();
        fillArray(numbers);
        sortOut(arr);
    }

}
