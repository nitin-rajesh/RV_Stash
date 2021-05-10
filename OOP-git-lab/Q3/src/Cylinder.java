public class Cylinder extends Circle{
    double height;
    double getHeight(){
        return height;
    }
    double getArea(){
        Circle baseref = new Circle(radius);
        return 2*baseref.getArea() + 2*3.141592*radius*height;
    }
    double getVolume(){
        Circle baseref = new Circle(radius);
        return baseref.getArea()*height;
    }
    String getColour(){
        return colour;
    }
    public Cylinder(double radius, double height){
        this.radius = radius;
        this.height = height;
    }
}
