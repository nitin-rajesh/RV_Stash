public class Main {
    public static void main(String[] args){
        int height, length;
        if (args.length == 0){
            System.out.println("Console args: radius (volume)");
        }
        if(args.length >= 2){
            Cylinder thing = new Cylinder(Integer.valueOf(args[0]), Integer.valueOf(args[1]));
            System.out.println("Volume: " + thing.getVolume());
            System.out.println("Area: " + thing.getArea());
        }
        else{
            Circle obj = new Circle(Integer.valueOf(args[0]), "Yellow" );
            System.out.println("Area: " + obj.getArea());
        }
    }
}
