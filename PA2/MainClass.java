
import java.io.IOException;
import org.apache.hadoop.mapreduce.Job;
import org.apache.hadoop.mapreduce.lib.input.FileInputFormat;
import org.apache.hadoop.mapreduce.lib.output.FileOutputFormat;
//import org.apache.hadoop.mapred.FileInputFormat;
import org.apache.hadoop.io.IntWritable;
import org.apache.hadoop.io.Text;
import org.apache.hadoop.fs.Path;
import org.apache.hadoop.conf.Configuration;


public class MainClass{
    public static void main(String[] args) throws IOException, ClassNotFoundException, InterruptedException {
        Path input_dir = new Path(args[0]);
        Path output_dir = new Path(args[1]);

        //Reads hadoop configuration file, and points to the hadoop cluster
        Configuration conf = new Configuration();

        //Create an object of Job by specifying conf object
        //Job job= new Job{conf, "MyWordCountJob"); //Deprecated
        Job job = Job.getInstance(conf, "MyWordCountJob");
        //Set your main class in the jar file that will be created in future
        job.setJarByClass(MainClass.class);

        job.setMapperClass(MyMapper.class);
        job.setReducerClass(MyReducer.class);

        //setting output key type
        job.setOutputKeyClass(Text.class);
        //if you don't provide this,it assumes Text ,and hence error
        job.setOutputValueClass(IntWritable.class);

        //Setting your input and output directory
        FileInputFormat.addInputPath(job, input_dir);
        FileOutputFormat.setOutputPath(job,output_dir);

        output_dir.getFileSystem(conf).delete(output_dir, true);
        //This piece of code will actually initiate the Job run
        System.exit(job.waitForCompletion(true) ? 0: 1);
    }
}


