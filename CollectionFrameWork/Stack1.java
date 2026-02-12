import java.util.*;
public class Stack1{
    public static void main(String[] args){
        Stack<Integer> stack = new Stack<>();

        stack.push(1);

        while(!stack.empty()){
            int val = stack.peek();
            System.out.printf("%d",val);
            stack.pop();
        }

    }
}