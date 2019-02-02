import java.math.BigInteger;

public class SchnorrKey {

    private BigInteger privateKey;
    private BigInteger publicKey;
    private BigInteger q;
    private BigInteger p;
    private BigInteger g;
	
    public SchnorrKey(BigInteger privateKey, BigInteger publicKey, 
		      BigInteger q, BigInteger p, BigInteger g) {
	this.privateKey = privateKey;
	this.publicKey = publicKey;
	this.q = q;
	this.p = p;
	this.g = g;
    }
	
    public BigInteger getPrivateKey() {
	return this.privateKey;
    }
	
    public BigInteger getPublicKey() {
	return this.publicKey;
    }
	
    public BigInteger getQ() {
	return this.q;
    }
	
    public BigInteger getP() {
	return this.p;
    }
	
    public BigInteger getG() {
	return this.g;
    }
	
    public String toString() {
	return "<#Schnorr Key" + 
	    ", private key:" + this.privateKey + 
	    ", public key:" + this.publicKey + 
	    ", q:" + this.q + 
	    ", p:" + this.p + 
	    ", g:" + this.g + 
	    ">";
    }
	
}
