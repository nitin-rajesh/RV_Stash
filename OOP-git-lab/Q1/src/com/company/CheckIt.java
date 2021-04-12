package com.company;

public class CheckIt {
    public static boolean isSameDigit(int a, int b, int c){
        if(a % 10 == b % 10 || c % 10 == b % 10 || a % 10 == c % 10){
            return true;
        }
        return false;
    }
    public static int[] getIndex(int[][] array2d, int val){
        int[] indexVal;
        for(int i = 0; i < array2d.length; i++){
            for(int j = 0; j < array2d[0].length; j++){
                if(array2d[i][j] == val){
                    indexVal = new int[]{i,j};
                    return indexVal;
                }
            }
        }
        indexVal = new int[]{-1,-1};
        return indexVal;
    }
}
