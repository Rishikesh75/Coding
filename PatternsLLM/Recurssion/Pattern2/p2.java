import java.util.ArrayList;
import java.util.List;

public class p2 {

    public static List<Integer> list;

    // Method 1 → Include / Exclude
    public static List<List<Integer>> subsets1 = new ArrayList<>();
    public static List<Integer> ans = new ArrayList<>();

    public static void allSubSetsRecurssion(int currIndex) {
        if (currIndex == list.size()) {
            subsets1.add(new ArrayList<>(ans)); // copy
            return;
        }

        // Exclude
        allSubSetsRecurssion(currIndex + 1);

        // Include
        ans.add(list.get(currIndex));
        allSubSetsRecurssion(currIndex + 1);

        // Backtrack
        ans.remove(ans.size() - 1);
    }

    // Method 2 → For-loop (ordered subsets)
    public static List<List<Integer>> subsets2 = new ArrayList<>();

    public static void helper(int index, List<Integer> current) {
        subsets2.add(new ArrayList<>(current)); // add current subset

        for (int i = index; i < list.size(); i++) {
            current.add(list.get(i));          // choose
            helper(i + 1, current);            // explore
            current.remove(current.size() - 1); // backtrack
        }
    }

    // Display function
    public static void display(String title, List<List<Integer>> subsets) {
        System.out.println(title);
        for (List<Integer> subset : subsets) {
            System.out.println(subset);
        }
        System.out.println();
    }

    public static void main(String[] args) {

        list = List.of(1, 2, 3);

        // Method 1
        allSubSetsRecurssion(0);
        display("Include/Exclude Method:", subsets1);

        // Method 2
        helper(0, new ArrayList<>());
        display("For-loop Method (Ordered):", subsets2);
    }
}