import java.util.*;
public class TraversalJava
{
    public static  class Node
    {
        int val;
        Node left;
        Node right;

        Node(int val)
        {
            this.val = val;
            left = null;
            right =  null;
        }
    }

    public static Node createNode(int val)
    {
        Node node  = new Node(val);
        return node;
    }

    public static Node createTree()
    {
        Node root = createNode(1);

        root.left = createNode(2);

        root.right = createNode(3);

        return root;
    }

    public static void inorderTraversal(Node root)
    {
        Stack<Node>stack = new Stack<>();

        while(!stack.isEmpty() || root != null)
        {
            while(root!=null)
            {
                stack.push(root);
                root = root.left;
            }

            root = stack.peek();
            stack.pop();
            System.out.printf("%d",root.val);
            root = root.right;
        }
    }

    public static void preorderTravesal(Node root)
    {
        Stack<Node>stack = new Stack<>();

        while(!stack.isEmpty() || root !=null)
        {
            while(root != null)
            {
                System.out.printf("%d\t",root.val);
                stack.push(root);
                root = root.left;
            }

            root = stack.peek();
            stack.pop();
            root = root.right;
        }
    }

    public static void postOrderTraversal1(Node root)
    {
        Stack<Node>stack1 = new Stack<>();
        Stack<Node>stack2 = new Stack<>();

        stack1.push(root);
        while(!stack1.isEmpty())
        {
            root = stack1.peek();
            stack1.pop();

            if(root.left != null)
            {
                stack1.push(root.left);
            }

            if(root.right != null)
            {
                stack1.push(root.right);
            }

            stack2.push(root);
        }

        while(!stack2.isEmpty())
        {
            root = stack2.peek();
            stack2.pop();
            System.out.printf("%d\t",root.val);
        }

    }

    public static void postOrderTraversal2(Node root)
    {
        Stack<Node>stack1 = new Stack<>();
        Node lastvisited = null;
        while(!stack1.isEmpty() || root != null)
        {
            while(root != null)
            {
                stack1.push(root);
                root = root.left;
            }

            root = stack1.peek();
            if(root.right != null && root.right!=lastvisited)
            {
                root = root.right;
            }
            else
            {
                stack1.pop();
                lastvisited = root;
                System.out.printf("%d\t",root.val);
                root = null;
            }
        }
    }


    public static void main(String[] args)
    {
        Node root = createTree();
        // inorderTraversal(root);
        // preorderTravesal(root);
        // postOrderTraversal1(root);
        postOrderTraversal2(root);
    }

}