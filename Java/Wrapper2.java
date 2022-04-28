//primitive data types to Wrapper Object

public class Wrapper2{  
   public static void main(String args[]){  
	//Creating Wrapper class object 
	Integer obj = new Integer(400);  
		
	//Converting the wrapper object to primitive
	int num = obj.intValue();

	System.out.println(num);  
	//Data type
	System.out.println(obj);  
   }
}