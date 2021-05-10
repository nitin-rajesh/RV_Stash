interface Animal{
    void eat();
    void sound();
}

interface TiredAnimal extends Animal{
    void sleep();
}

class Lion implements Animal{
    public void eat(){
        System.out.println("Lion - Hunting");
    }
    public void sound(){
        System.out.println("Lion - Roar");
    }
}

class Snake implements TiredAnimal{
    public void eat(){
        System.out.println("Snake - Swallow");
    }
    public void sound(){
        System.out.println("Snake - Hiss");
    }
    public void sleep(){
        System.out.println("Snake - Sleep");
    }
    int noOfLegs(){
        return 0;
    }
}

public class Main{
    public static void main(String[] args){
        Snake s1 = new Snake();
        Lion l1 = new Lion();
        s1.eat();
        s1.sleep();
        l1.eat();
        l1.sound();
        System.out.println(s1.noOfLegs());
    }
}

