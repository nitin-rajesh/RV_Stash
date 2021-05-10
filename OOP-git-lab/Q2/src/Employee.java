public class Employee {
    String EmpID;
    String Name;
    public Address Addr;

    public String getName() {
        return Name;
    }

    public Address getAddr() {
        return Addr;
    }

    public String getEmpID() {
        return EmpID;
    }

    public void setName(String name) {
        Name = name;
    }

    public void setAddr(Address addr) {
        Addr = addr;
    }

    public void setEmpID(String empID) {
        EmpID = empID;
    }

    Employee(){
        Addr = new Address();
    }
}
