 #include<iostream>
 #include<queue>
 #include<climits>
 #include<stack>
 #include<algorithm>
 using namespace std;
 struct node 
 {
    int value;
    struct node *left;
    struct node *right;
 };
 struct node* createNode(int val)
{
    struct node* newnode = new node();  
    newnode->value = val;              
    newnode->left = nullptr;            
    newnode->right = nullptr;           
    return newnode;                     
}
struct node * CreateTree(vector<int>arr)
{
    struct node *root = nullptr;
    int i=0;
    queue<struct node *>s;
    root = createNode(arr[i]);
    struct node *root_main = root;
    s.push(root);
    while(!s.empty())
    {
        root = s.front();
        s.pop();
        if(2*i+1 < arr.size() && arr[2*i+1] !=INT_MIN)
        {
            root->left = createNode(arr[2*i+1]);
            s.push(root->left);
        }
        else
        {
            root->left = nullptr;
        }
        if( 2*i+2 < arr.size() && arr[2*i+2] !=INT_MIN)
        {
            root->right = createNode(arr[2*i+2]);
            s.push(root->right);
        }
        else
        {
            root->right = nullptr; 
        }
        i = i + 1;
    }
    return root_main;
}
void InorderTraversal(struct node *root)
{
    if(root == nullptr)
    {
        return;
    }
    InorderTraversal(root->left);
    cout<<root->value<<"\t";
    InorderTraversal(root->right);
}
void InorderTraversalIterativeApproch(node* root) {
    if (root == nullptr) return;

    stack<node*> s;
    node* current = root;
    while(current!=nullptr || !s.empty())
    {
        while(current!=nullptr)
        {
            s.push(current);
            current = current->left;
        }
        current = s.top();
        s.pop();
        cout<<current->value<<"\t";
        current = current->right;
    }
}
void postTraversalIterativeApproch(node* root) {
    if (root == nullptr) return;

    stack<node*> st;
    node* current = root;
    node* lastVisited = nullptr;
     while (!st.empty() || current != nullptr) {
        if (current != nullptr) {
            st.push(current);
            current = current->left;
        } 
        else {
            node* peekNode = st.top();
            if (peekNode->right != nullptr && lastVisited != peekNode->right) {
                current = peekNode->right;
            } 
            else {
                cout << peekNode->value << "\t";
                lastVisited = peekNode;
                st.pop();
            }
        }
    }
}
void LevelOrderTraversal(struct node *root)
{
    struct node *currnetnode = root;
    queue<node*>q;
    q.push(currnetnode);
    struct node *temp = nullptr;
    while(!q.empty())
    {
        temp = q.front();
        q.pop();
        if(temp->left!=nullptr)
        {
            q.push(temp->left);
        }
        if(temp->right!=nullptr)
        {
            q.push(temp->right);
        }
        cout<<temp->value<<"\t";
    }
    cout<<"\n";
}
int MaxHeight(struct node *root)
{
    if(root == nullptr)
    {
        return -1;
    }
    int L = MaxHeight(root->left) + 1;
    int R = MaxHeight(root->right)+1;
    return max(L,R);
}


int Balanced(struct node *root) {
    if (root == nullptr) return 0;

    int left = Balanced(root->left);
    if (left == -1) return -1; // left subtree unbalanced

    int right = Balanced(root->right);
    if (right == -1) return -1; // right subtree unbalanced

    if (abs(left - right) > 1) return -1; // this node unbalanced

    return 1 + max(left, right);
}

bool CheckBalanced(struct node *root) {
    return Balanced(root) != -1;
}

pair<int,int> LeftRightHeight(struct node *root)
{
    if(root == nullptr)
    {
        return make_pair(0,0);
    }
    pair<int,int>left = LeftRightHeight(root->left);
    pair<int,int>right = LeftRightHeight(root->right);
    return make_pair(max(left.first,left.second)+1,max(right.first,right.second)+1);
}
int Diameter(struct node *root)
{
    pair<int,int>rootvalues = LeftRightHeight(root);
    return rootvalues.first+rootvalues.second-2;
}

int max_path_sum(struct node *root,int& maxvalue)
{
    if(root == nullptr)
    {
        return 0;
    }
    int value = root->value;
    int leftmax = max_path_sum(root->left,maxvalue);
    int rightmax = max_path_sum(root->right,maxvalue);
    maxvalue = max(maxvalue,value+max(leftmax,rightmax));
    return value + leftmax+rightmax;
}
int Findmax_path(struct node *root)
{
    int max_value = INT_MIN;
    max_path_sum(root,max_value);
    return max_value;
}
void ZigZagTraversal(struct node *root)
{
    vector<int>Traversal_array;
    queue<pair<node*,bool>>q;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        pair<node *,int> currentnode = q.front();
        q.pop();
        cout<<currentnode.first->value<<"\t";
        if(currentnode.second == 0)
        {
            if(currentnode.first->right!=nullptr)
            {
                q.push(make_pair(currentnode.first->right,1));
            }
            if(currentnode.first->left!=nullptr)
            {
                q.push(make_pair(currentnode.first->left,1));
            }
        }
        else
        {
            if(currentnode.first->left!=nullptr)
            {
                q.push(make_pair(currentnode.first->left,1));
            }
            if(currentnode.first->right!=nullptr)
            {
                q.push(make_pair(currentnode.first->right,1));
            }   
        }
    }
}
void LeftBoundaryTraversal(struct node *root)
{
    while(root->left!=nullptr || root->right!=nullptr)
    {
        cout<<root->value<<"\t";
        if(root->left!=nullptr)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
}
void LeafNodeTraversal(struct node *root)
{
    if(root == nullptr)
    {
        return;
    }
    if(root->left == nullptr && root->right == nullptr)
    {
        cout<<root->value<<"\t";
    }
    LeafNodeTraversal(root->left);
    LeafNodeTraversal(root->right);
}
void RightBoundaryTraversal(struct node *root)
{
    vector<int>arr;
    while(root->left!=nullptr && root->right!=nullptr)
    {
        arr.push_back(root->value);
        if(root->right!=nullptr)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    reverse(arr.begin(),arr.end());
    for(auto start = arr.begin();start!=arr.end();start++)
    {
        cout<<*start<<"\t";
    }
}
void BoundaryTranversal(struct node *root)
{
    cout<<"Boundary Traversal:"<<root->value<<"\t";
    LeftBoundaryTraversal(root->left);
    LeafNodeTraversal(root);
    RightBoundaryTraversal(root->right);
    cout<<"\n";
}
int Find(vector<pair<int,vector<int>>> Datastruct,int val)
{
    int count = 0;
    for(auto start = Datastruct.begin();start!=Datastruct.end();start++)
    {
        if(start->first == val)
        {
            return count;
        }
        count = count + 1;
    }
    return count;
}
// void Vertical_Traversal(struct node *root,vector<pair<int,vector<int>>>&Datastruct,int val)
// {
//    if(root == nullptr) return;
    
//    int index = Find(Datastruct,val);
//     // cout<<index<<"\t";
//     if(index == Datastruct.size())
//     {
//         // cout<<root->value<<endl;
//         Datastruct.push_back(make_pair(val,vector<int>(1,root->value)));
//     }
//     else
//     {
//         Datastruct[index].second.push_back(root->value);
//     }
//     Vertical_Traversal(root->left,Datastruct,val-1);
//     Vertical_Traversal(root->right,Datastruct,val+1);
// }
// void Display(vector<pair<int,vector<int>>>& Datastruct)
// {
//     for(auto start = Datastruct.begin(); start != Datastruct.end(); start++)
//     {
//         cout <<start->first<<":\t";   // use -> for iterator
//         for(int i = 0; i < start->second.size(); i++)
//         {
//             cout << start->second[i] << "\t";
//         }
//         cout << "\n";
//     }
// }
int Find(vector<pair<int,int>>Dst,int val)
{
    int count =0;
    for(auto start = Dst.begin();start!=Dst.end();start++)
    {
        if(start->first == val)
        {
            return count;
        }
        count = count + 1;
    }
    return count;
}
void TopViewLevelorderTraversal(struct node*root,vector<pair<int,int>>&Dst)
{
    queue<pair<node*,int>>q;
    q.push(make_pair(root,0));
    while(!q.empty())
    {
        pair<node*,int>temp = q.front();
        int index = Find(Dst,temp.second);
        if(index == Dst.size())
        {
            Dst.push_back(make_pair(temp.second,temp.first->value));
        }
        q.pop();
        if(temp.first->left)
            q.push(make_pair(temp.first->left, temp.second-1));

        if(temp.first->right)
            q.push(make_pair(temp.first->right, temp.second+1));
    }

}
void DisplayDst(vector<pair<int,int>>&Dst)
{
 for(auto start = Dst.begin();start!=Dst.end();start++)
 {
    cout<<start->first<<":"<<start->second<<"\t";
 }
 cout<<"\n";
}

 int main()
 {
    vector<int>arr = {2,1,3,4,3};
    struct node *root = CreateTree(arr);
    //InorderTraversal(root);
    //InorderTraversalIterativeApproch(root);
    // postTraversalIterativeApproch(root);
    //LevelOrderTraversal(root);
    // cout<<MaxHeight(root)<<endl;
    //cout<<CheckBalanced(root)<<endl;
    // cout<<Diameter(root)<<endl;
    // cout<<Findmax_path(root)<<endl;
    // ZigZagTraversal(root);
    // BoundaryTranversal(root);
    // vector<pair<int,vector<int>>> Datastruct;
    // Vertical_Traversal(root,Datastruct,0);
    // Display(Datastruct);
    vector<pair<int,int>> Dst;
    TopViewLevelorderTraversal(root,Dst);
    DisplayDst(Dst);
    return(0);
 }