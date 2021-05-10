public class Circle{
    double radius;
    String colour;

    public Circle(){
        radius = 0;
        colour = new String();
    }

    public Circle(double radius, String colour){
        this.radius = radius;
        this.colour = colour;
    }

    public Circle(double radius){
        this.radius = radius;
        this.colour = new String();
    }

    double getRadius(){
        return radius;
    }

    double getArea(){
        return 3.141592*radius*radius;
    }

    String getColour(){
        return colour;
    }


}