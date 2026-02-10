import java.util.*;
public class TreeJava7
{
    public static class Node
    {
        int value;

        Node left;

        Node right;

        Node(int value)
        {
            this.value = value;
            left = null;
            right = null;
        }
    }

    public static Node createNode(int value)
    {
        return new Node(value);
    }

//    public static Node createTree()
//    {
//        Node root = createNode(1);
//
//        root.left = createNode(3);
//
//        root.right = createNode(2);
//
//        return root;
//    }
//    public static List<Node> list;
//
//    public static void displayList(List<Node> list)
//    {
//        for(var item : list)
//        {
//            if(item == null)
//            {
//                System.out.printf("Null\t");
//                continue;
//            }
//            System.out.printf("%d\t",item.value);
//        }
//    }
//    public static void serializeBT(Node root)
//    {
//        Queue<Node> queue = new LinkedList<Node>();
//
//        queue.add(root);
//
//        while(!queue.isEmpty())
//        {
//            var node = queue.peek();
//            list.add(node);
//            queue.poll();
//            if(node != null)
//            {
//                queue.add(node.left);
//                queue.add(node.right);
//            }
//        }
//
//        return;
//    }
//
//    public static Node createBinaryTree(int index)
//    {
//        if(index>list.size()) return null;
//
//        if(list.get(index) == null) return null;
//        Node node = createNode(list.get(index).value);
//
//        if(node!=null)
//        {
//            node.left = createBinaryTree(2*index+1);
//
//            node.right = createBinaryTree(2*index+2);
//        }
//
//        return node;
//
//    }
//
    public static void inorderTraversal(Node root)
    {
        if(root == null) return;
        System.out.printf("%d\t",root.value);
        inorderTraversal(root.left);
        inorderTraversal(root.right);
    }

    public static List<Integer> preorder = new ArrayList<>(List.of(1, 2, 3));
    public static List<Integer> inorder  = new ArrayList<>(List.of(1, 2, 3));
    public static List<Integer> postroder = new ArrayList<>(List.of(1,3,2));
    public static Integer preIndex = 0;

    public static Node buildTree(int startIndex,int endIndex)
    {
        if(startIndex > endIndex) return null;

        int rootval = preorder.get(preIndex);
        preIndex++;

        var root = createNode(rootval);

        if(startIndex == endIndex) return  root;

        var rootIndex = findIndex(rootval);

        root.left = buildTree(startIndex,rootIndex-1);
        root.right = buildTree(rootIndex+1,endIndex);

        return root;

    }

    public static Integer postIndex = postroder.size()-1;

    public static Node buildTree1(int startIndex,int endIndex)
    {
        if(startIndex > endIndex) return null;

        int rootval = postroder.get(postIndex);
        postIndex--;

        var root = createNode(rootval);

        if(startIndex == endIndex) return root;

        var rootIndex = findIndex(rootval);

        root.right = buildTree(rootIndex+1,endIndex);
        root.left = buildTree(startIndex,rootIndex-1);

        return root;
    }

    public static int findIndex(int val)
    {
        for(int i=0;i<inorder.size();i++)
        {
            if(inorder.get(i) == val) return i;
        }
        return -1;
    }

    List<Integer> preorderBST = new ArrayList<>(List.of(1,2,3));
    int preIndex = 0;
    public static Node buildBst(int min,int max)
    {
        if(preIndex == preorderBST.size()-1) return null;

        var rootValue = preorderBST.get(preIndex);
        preIndex++;
        var root = createNode(rootValue);

        if(rootValue < min || rootValue > max) return null;

        root.left = buildBst(min,rootValue);
        root.right = buildBst(rootValue,max);
        return root;
    }
    public static void main(String[] args)
    {
//        Node root = createTree();
//        list = new ArrayList<Node>();
//        displayList(list);
//        serializeBT(root);
//
//        root = createBinaryTree(0);
//
//        inorderTraversal(root);

//        Node root = buildTree1(0,inorder.size()-1);
        inorderTraversal(root);
    }
}