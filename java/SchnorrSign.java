import java.math.BigInteger;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.util.Random;

public class SchnorrSign {

	private BigInteger q;
	private BigInteger p;
	private BigInteger g;
	
	public SchnorrSign(BigInteger q, BigInteger p, BigInteger g) {
		this.q = q;
		this.p = p;
		this.g = g;
	}
	
	public SchnorrSignature sign(String msg, BigInteger key) throws NoSuchAlgorithmException {
		BigInteger k = new BigInteger(
				String.valueOf(new Random().nextInt(Integer.MAX_VALUE)));
		
		BigInteger r = g.modPow(k, p);
		MessageDigest sha = MessageDigest.getInstance("SHA-1");
		sha.update(msg.getBytes());
		sha.update(r.toString().getBytes());
		byte[] digest = sha.digest();
		BigInteger h = new BigInteger(1, digest);
		
		BigInteger s = (k.add(key.multiply(h))).mod(q);
		BigInteger e = g.modPow(s, p);
		
		return new SchnorrSignature(r, e);
	}
	
}
