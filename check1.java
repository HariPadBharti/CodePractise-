import java.util.Arrays;
public class check1 {
	  public static void main(String args[])
	  {
	  	int a=1;
	  	int p=0, q=0;
	  	int count=0;
	  	while(a!=100)
	  	{
	  		p=a/10;
	  		q=a%10;

	  		if((p==7))
	  		count++;
	  		if(q==7)
	  		count++;

	  		a++;
	  	}
	  	System.out.println(count);

	    }

}