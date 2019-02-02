import java.security.*;
import java.math.BigInteger;
public class Main {
   
    public static void main(String[] args) throws NoSuchAlgorithmException {

	//        SchnorrKeyGenerator generator = new SchnorrKeyGenerator();
	//        SchnorrKey key = generator.generate();
	BigInteger privateKey = new BigInteger("17");
	BigInteger publicKey = new BigInteger("258991358871459");
	BigInteger q = new BigInteger("31");
	BigInteger p = new BigInteger("1809223843192979");
	BigInteger g = new BigInteger("876990444539854");
	
	SchnorrKey key = new SchnorrKey(privateKey, publicKey, q, p, g);
        System.out.println(key);
        
        String msg = "Hello Man";
        
        SchnorrSign sign = new SchnorrSign(key.getQ(), key.getP(), key.getG());
        SchnorrSignature signature = sign.sign(msg, key.getPrivateKey());
        
        System.out.println(signature);
        
        SchnorrVerify verify = new SchnorrVerify(key.getP());
        boolean result = verify.verify(msg, signature, key.getPublicKey());
		if (result) {
			System.out.println("Schnorr signature is valid");
		} else {
			System.out.println("Schnorr signature is not valid");
		}
        
    }
}
