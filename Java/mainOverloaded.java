class methodOverloading1
{
    void area(float x)
    {
        System.out.println("The area of the square is "+ Math.pow(x, 2)+ " sq. units");
    }

    void area(double x)
    {
        double z = 3.14 * x * x;
        System.out.println("The area of the circle is " +z+ " sq. units");
    }

    void area(float x, float y)
    {
        System.out.println("The area of the rectangle is "+ x*y +" sq. units");
    }
}

class mainOverloaded 
{
     public static void main(String args[]) 
	{
	   methodOverloading1 Obj = new methodOverloading1();
	   Obj.area(8);
	   Obj.area(10,19);
	   Obj.area(9.8);
    }
}