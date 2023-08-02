
import java.io.IOException;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Reducer;

public class MyReducer extends Reducer<Text, IntWritable, Text, IntWritable>{
    public MyReducer(){
        System.out.println("MyReducer().hashCode=" + hashCode());
    }

    public void reduce(Text key, Iterable<IntWritable> values, Context context)
            throws IOException, InterruptedException{
        int sum = 0;
        for(IntWritable value:values){
            System.out.print(" " + value.get());
            sum += value.get();
        }
        System.out.println();
        context.write(key, new IntWritable(sum));
    }
}

