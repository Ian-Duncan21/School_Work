import java.io.IOException;
import java.util.StringTokenizer;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.mapreduce.Mapper;

public class MyMapper extends Mapper<Object, Text, Text, IntWritable>{
    public MyMapper(){
        System.out.println ("MyMapper():" + hashCode());
    }
//Sample data

    private final static IntWritable one = new IntWritable(1);
    private Text word = new Text();
//Will be called when map slot executes the program

    public void map(Object key, Text value, Context  context) throws IOException,  InterruptedException
    {

        StringTokenizer itr = new StringTokenizer(value.toString());
        while(itr.hasMoreTokens()){
            word.set(itr.nextToken());
            context.write(word, one);
        }
    }

}
