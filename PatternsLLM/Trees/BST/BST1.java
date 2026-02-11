public class BST1 {

    // Node definition
    static class Node {
        int val;
        Node left, right;

        Node(int val) {
            this.val = val;
            left = right = null;
        }
    }

    // Insert a node into BST
    public static Node insertNode(Node root, int value) {
        if (root == null) {
            return new Node(value);
        }

        if (value < root.val) {
            root.left = insertNode(root.left, value);
        } else if (value > root.val) {
            root.right = insertNode(root.right, value);
        }
        // duplicates are ignored
        return root;
    }

    // Search a value in BST
    public static boolean findNodeInBst(Node root, int value) {
        if (root == null) return false;

        if (root.val == value) return true;

        if (value < root.val)
            return findNodeInBst(root.left, value);
        else
            return findNodeInBst(root.right, value);
    }

    // Validate BST using min-max approach
    public static boolean validateBST(Node root, Integer min, Integer max) {
        if (root == null) return true;

        if ((min != null && root.val <= min) ||
                (max != null && root.val >= max)) {
            return false;
        }

        return validateBST(root.left, min, root.val) &&
                validateBST(root.right, root.val, max);
    }

    // Inorder traversal (BST gives sorted output)
    public static void inorder(Node root) {
        if (root == null) return;

        inorder(root.left);
        System.out.print(root.val + " ");
        inorder(root.right);
    }

    public static Node deleteNode(Node root,Integer key)
    {
        if(root == null) return null;

        if(key < root.val) root.left = deleteNode(root.left,key);

        else if(key > root.val) root.right = deleteNode(root.right,key);

        else
        {
            if(root.left == null) return root.right;

            else if(root.right == null) return root.left;

            else {
                var successor = findMin(root.right);
                root.val = successor.val;
                root.right = deleteNode(root.right, successor.val);
            }
        }

        return root;
    }
    public static Node findMin(Node node)
    {
        while(node.left != null)
        {
            node = node.left;
        }
        return node;
    }
    // Main method
    public static void main(String[] args) {

        Node root = null;

        root = insertNode(root, 10);
        insertNode(root, 5);
        insertNode(root, 15);
        insertNode(root, 2);
        insertNode(root, 7);
        insertNode(root, 12);
        insertNode(root, 20);

        System.out.print("Inorder Traversal: ");
        inorder(root); // sorted order
        System.out.println();

        System.out.println("Find 7: " + findNodeInBst(root, 7));
        System.out.println("Find 100: " + findNodeInBst(root, 100));

        System.out.println("Is valid BST: " + validateBST(root, null, null));
    }
}
