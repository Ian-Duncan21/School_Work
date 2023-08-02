import java.lang.Exception;
import java.util.Random;
import java.time.Instant;
import java.time.Clock;
import java.time.Duration;
import java.util.Arrays;

class Coordinator {
	public static void main(String[] args) {
		int seed = Integer.parseInt(args[0]);
		int primeSeed = Integer.parseInt(args[1]);
		Random rand = new Random(seed);
		int bufferSize = rand.nextInt(11-5) + 5;
        int numElements = rand.nextInt(31-10) + 10;
        int numConsumers = rand.nextInt(6-2) + 2;
        int numGenerators = rand.nextInt(6-2) + 2;
        int id = 0;
        System.out.println("[Coordinator] Buffer Size: " + bufferSize);
        System.out.println("[Coordinator] Total Items: " + numElements);
        System.out.println("[Coordinator] No. of Generators: " + numGenerators);
        System.out.println("[Coordinator] No. of Consumers: " + numConsumers);

        Generator[] generators = new Generator[numGenerators];
        Consumer[] consumers = new Consumer[numConsumers];
        
        Buffer b = new Buffer(bufferSize); // create buffer
        for(int i=0; i<numGenerators; i++){
            generators[i] = new Generator(b, numElements/numGenerators, i+1, seed, primeSeed);
            generators[i].start();
        }

        
        for(int i=0; i<numConsumers; i++){
            consumers[i] = new Consumer(b, numElements/numConsumers, i+1);
            consumers[i].start();
        }
        for(int i=0; i<numConsumers; i++){
            try {
                consumers[i].join();
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        
        int pSum = 0;
        int cSum = 0;
        for(int i=0; i<numConsumers; i++){
            cSum += consumers[i].getCheckSum();
        }
        for(int i=0; i<numGenerators; i++){
            pSum += generators[i].getCheckSum();
        }
        System.out.format("The generated & consumed sums of primes are the same as shown: %d\n", cSum);
    }
	

	//Call this function from your producer or your consumer to get the time stamp to be displayed
	public static String getTime() {
		Clock offsetClock = Clock.offset(Clock.systemUTC(), Duration.ofHours(-9));
		Instant time = Instant.now(offsetClock);
		String timeString = time.toString();
		timeString = timeString.replace('T', ' ');
		timeString = timeString.replace('Z', ' ');
		return(timeString);
	}
}
