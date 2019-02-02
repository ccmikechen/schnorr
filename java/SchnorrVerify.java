import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;

public class SchnorrVerify {

    private BigInteger p;
	
    public SchnorrVerify(BigInteger p) {
	this.p = p;
    }
	
    public boolean verify(String msg, SchnorrSignature signature, BigInteger key) 
	throws NoSuchAlgorithmException {
	MessageDigest sha = MessageDigest.getInstance("SHA-1");
        sha.update(msg.getBytes());
        sha.update(signature.getR().toString().getBytes());
        byte[] digest = sha.digest();
        BigInteger h = new BigInteger(1, digest);
	System.out.println("H = " + h);
	System.out.println("P = " + p);
	System.out.printf("key.modPow(%s, %s) = %s\n", h.toString(), p.toString(), key.modPow(h, p).toString());
        BigInteger e = (key.modPow(h, p).multiply(signature.getR())).mod(p);
        System.out.printf("e = %s\n", e.toString());
        return e.equals(signature.getE());
    }
}
