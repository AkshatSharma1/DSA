//String to integer

public class Wrapper4{
 
  public static void main(String[] args) {
     
    //1.Construct Integer using constructor.
    Integer intObject1 = new Integer("500");
    System.out.println(intObject1);
    
    //2.Use valueOf method of Integer class
    String str = "500";
    Integer intObject2 = Integer.valueOf(str);
    System.out.println(intObject2);
    
  }
}