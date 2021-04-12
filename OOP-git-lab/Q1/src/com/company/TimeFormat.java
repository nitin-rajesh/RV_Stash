package com.company;

import java.sql.Time;

public class TimeFormat {
    private int minutes;
    private int hours;
    private int seconds;
    TimeFormat(int seconds){
        if(seconds < 0) {
            seconds *= -1;
        }
        this.seconds = seconds;
        convertToMinutes();
        convertToHours();
    }
    public void convertToMinutes(){
        minutes = seconds/60;
        seconds = seconds%60;
    }
    public void convertToHours(){
        hours = minutes/60;
        minutes = minutes%60;
    }
    public void printTime(){
        System.out.println(hours + ":" + minutes + ":" + seconds);
    }
}
