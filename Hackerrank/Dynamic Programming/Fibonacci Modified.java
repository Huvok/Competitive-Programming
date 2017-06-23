import java.util.*;
import java.math.*;

//                                                          //AUTHOR: Hugo Garcia
//                                                          //PURPOSE: Competitive programming template

//======================================================================================================================
public class Solution 
{
    public static void main(String[] args) 
    {
        Scanner scan = new Scanner(System.in);
        BigInteger first = new BigInteger(scan.next());
        BigInteger second = new BigInteger(scan.next());
        int n = scan.nextInt();
        BigInteger third = new BigInteger("0");
        
        for(int i = 2; i < n; i++) 
        {
            third = first.add(second.multiply(second));
            first = second;
            second = third;
        }
        scan.close();
        System.out.println(third);
    }
}
//======================================================================================================================