
import java.util.Collections;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class s1{

    public static void main(String[] args) {
     
    
        List<List<Integer>> arr = IntStream.range(0,5)
                            .mapToObj(i -> Collections.nCopies(1, 10))
                            .collect(Collectors.toList());
    }
}