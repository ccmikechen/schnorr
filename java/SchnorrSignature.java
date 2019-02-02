import java.math.BigInteger;

public class SchnorrSignature {

	private BigInteger r;
	private BigInteger e;
	
	public SchnorrSignature(BigInteger r, BigInteger e) {
		this.r = r;
		this.e = e;
	}
	
	public void setR(BigInteger r) {
		this.r = r;
	}
	
	public BigInteger getR() {
		return this.r;
	}
	
	public void setE(BigInteger e) {
		this.e = e;
	}
	
	public BigInteger getE() {
		return this.e;
	}
	
	public String toString() {
		return "<#Schnorr Signature, r:" + this.r + ", e:" + this.e + ">";
	}
	
}
