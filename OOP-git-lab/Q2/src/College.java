public class College {
    String Name;
    public Address Addr;

    public Address getAddr() {
        return Addr;
    }

    public String getName() {
        return Name;
    }

    public void setAddr(Address addr) {
        Addr = addr;
    }

    public void setName(String name) {
        Name = name;
    }
    College(){
        Addr = new Address();
    }
}
