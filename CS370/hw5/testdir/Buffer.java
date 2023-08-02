public class Buffer {

    public int[] buffer; 
    private int size; 
    private int totalSize; 
    private int start; 
    private int end; 

    public Buffer(int size){ // ctor
        this.buffer = new int[size];
        this.size = 0;
        this.totalSize = size;
        this.start=0;
        this.end=0;
    }

    public synchronized int insert(int val) { // insert value at end of queue, returns index it was added to
        while (this.isFull()) {
            try {
                wait(); // wait if full
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        int index = this.end; // store add index
        this.buffer[this.end] = val; // add at end index
        this.end += 1;
        if (this.end == this.totalSize) { // increase end and loop to zero if it goes to the end of the array
            this.end = 0;
        }
        this.size += 1; 
        notify(); 
        return index;
    }

    public synchronized int[] remove() { // remove from front of queue, returns value and index it was at
        while (this.isEmpty()) {
            try {
                wait(); 
            } catch (InterruptedException e) {
                e.printStackTrace();
            }
        }
        int val = this.buffer[this.start];
        int index = this.start; // index it was at
        this.start += 1; // increase index where the next will pop from
        if (this.start == this.totalSize) { // loop back to zero if it reaches the end of the array
            this.start = 0;
        }
        this.size -= 1; 
        notify(); // notify that the array is no longer full
        return new int[] {val, index};

    }

    public synchronized boolean isFull(){ // check if array is full
        return this.totalSize == this.size;
    }

    public synchronized boolean isEmpty(){ // check if array is empty
        synchronized (this){
            return this.size==0;
        }
    }

}

