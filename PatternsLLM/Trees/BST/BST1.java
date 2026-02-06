public class BST1
{
    public static class Node
    {
        int val;
        Node left;
        Node right;

        Node(int val)
        {
            this.val = val;
            left = null;
            right = null;
        }
    }
    public static Node insertNode(int value,Node root)
    {
        if(root == null)
        {
            root = Node(val);
            return root;
        }

        if(root.val > value)
        {
            if(root.right != null)
                insertNode(value,root.right);
            else
                root.right = new Node(val);
        }
        else if(root.val < value)
        {
            if(root.left != null)
                insertNode(value,root.left);
            else
                root.left = new Node(val);
        }
        return root;

    }
    public static void main(String[] args)
    {

        Node root = insertNode(1,null);
        return;
    }

}