import java.math.BigInteger;
import java.security.SecureRandom;

public class SchnorrKeyGenerator {

	public SchnorrKey generate() {
        int blq = 5;
        int blp = 50;

        BigInteger one = new BigInteger("1");
        BigInteger two = new BigInteger("2");
        BigInteger q, qp, p, a, g, xa, ya;
        int certainty = 16;
        SecureRandom sr = new SecureRandom();   
        q = new BigInteger(blq, certainty, sr);
        int i = 0;
        qp = new BigInteger(blp - blq, certainty, sr);
        do {
            p = q.multiply(qp).multiply(two).add(one);
            if (p.isProbablePrime(certainty)) {
                break;
            }
            qp = qp.nextProbablePrime();
            i++;
        } while (true);
        i = 0;
        a = new BigInteger(blp - 1, sr);
        do {
            g = a.modPow((p.subtract(one)).divide(q), p);
            if (g.modPow(q, p).equals(one)) {
                break;
            }
            a = a.add(one);
            i++;
        } while (true);
        xa = new BigInteger(blq, sr);
        ya = g.modPow(xa, p);
        
        return new SchnorrKey(xa, ya, q, p, g);
	}
	
}
