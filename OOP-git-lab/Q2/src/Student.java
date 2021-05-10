public class Student {
    String USN;
    String Name;
    public Address Addr;

    public Address getAddr() {
        return Addr;
    }

    public String getName() {
        return Name;
    }

    public String getUSN() {
        return USN;
    }

    public void setAddr(Address addr) {
        Addr = addr;
    }

    public void setName(String name) {
        Name = name;
    }

    public void setUSN(String USN) {
        this.USN = USN;
    }
    Student(){
        Addr = new Address();
    }
}
