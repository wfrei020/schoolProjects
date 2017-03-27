import java.util.concurrent.Semaphore;
public class Pool {
	
		   private static final int MAX_AVAILABLE = 1;
		   private final Semaphore available = new Semaphore(MAX_AVAILABLE, true);
public Pool(){

}
		   public void take()throws InterruptedException{
		     available.acquire();
		   }

		   public void release() {
	
		       available.release();
		   }
	
	
	
	
	
}
