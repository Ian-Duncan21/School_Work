import java.util.Random;

public class Generator extends java.lang.Thread {
	//Necessary variables and object declaration
	Random randomWithSeed;
	private Buffer buffer;
    private int numElements;
    private int seed;
    private int primeSeed;
    private int sum;
    private int id;

	public Generator(Buffer buff, int count, int id, int seed, int primeSeed) {
		//Assign values to the variables
		randomWithSeed = new Random(primeSeed);
		this.buffer = buff;
        this.numElements = count;
        this.seed = seed;
        this.primeSeed = primeSeed;
        this.sum = 0;
        this.id = id;
	}
	
	public int getNum(){
        int randomN = randomWithSeed.nextInt(32-3) + 3;
        int num = 1;
        int count = 0;
        int i;
        while(count < randomN){
            num += 1;
            for(i = 2; i <= num; i++){
                if(num % i == 0){
                    break;
                }
            }
            if(i == num){
                count += 1;
            }
        }
        return num;
    }

	@Override
	public void run() {
		while (this.numElements>0){
            int c = getNum();
            int index = buffer.insert(c);
            this.sum += c;
            System.out.format("\033[0;4m[Generator%2d]: inserted %d%4s index %2d at time\033[0;0m %s\n",this.id, c, "at", index, Coordinator.getTime());
            this.numElements--;
        }
	}
	
	public int getCheckSum() {
        return this.sum;
    }
}
