//Conversion of primitive data types to objects of their corresponding wrapper class

public class Wrapper1{  
   public static void main(String args[]){  
       
	//Converting int primitive into Integer object  
	int num=100;  
	Integer obj=Integer.valueOf(num);  

	System.out.println(num+ " "+ obj);  
   }
}