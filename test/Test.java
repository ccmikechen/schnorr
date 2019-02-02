import java.math.BigInteger;

public class Test {

    public static void main(String[] args) {

	BigInteger n = new BigInteger("17");
	BigInteger e = new BigInteger("99999999999999999999999999999999999999999999999");
	BigInteger m = new BigInteger("123456789");

	System.out.println(n.modPow(e, m));
	
    }
    
}
