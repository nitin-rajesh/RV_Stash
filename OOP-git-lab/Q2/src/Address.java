public class Address {
    String StreetNum;
    String CityName;
    String StateName;
    String CountryName;
    Address(String Streetnum, String CityName, String StateName, String CountryName){
        this.StreetNum = Streetnum;
        this.CityName = CityName;
        this.StateName = StateName;
        this.CountryName = CountryName;
    }
    Address(){
    }
    public void getAddress(){
        this.StreetNum = System.console().readLine();
        this.CityName = System.console().readLine();
        this.StateName = System.console().readLine();
        this.CountryName = System.console().readLine();
    }

    public String fullAddress(){
        String str = new String(StreetNum.toString() + " " + CityName + " " + StateName + " " + CountryName);
        return str;
    }
}
