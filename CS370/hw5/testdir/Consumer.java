public class Consumer extends Thread{

    private Buffer buffer;
    private int numElements;
    private int ID;
    private int sum;

    public Consumer(Buffer b, int numElements, int ID){
        this.buffer = b;
        this.numElements = numElements; // number elements to consume
        this.ID = ID; // consumer ID
        this.sum = 0;
    }

    public void run(){ // runs when .start() is called
        while(this.numElements>0){
            int[] removed = this.buffer.remove(); //removes from queue, gets value and index
            int val = removed[0];
            int index = removed[1];
            this.sum += val;
            System.out.format("[Consumer%3d]: consumed %d %4s index %d at time %s\n", this.ID, val, "from", index, Coordinator.getTime());
            this.numElements--;
        }
    }

    public int getCheckSum(){
        return this.sum;
    }



}
