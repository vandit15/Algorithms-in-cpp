#include<iostream>


using namespace std;


struct node
{
    int value;
    node* left;
    node* right;
};

node* root = NULL;

node* NewNode(int val)
{
    node* temp= new node();
    temp->left=NULL;
    temp->right=NULL;
    temp->value=val;

    return temp;
}

node* insert(node* root,int val)
{
    if(root==NULL){
        root=NewNode(val);
        return root;
    }
    node* prev=NULL;
    node* ptr=root;
    int flag;
    while(ptr){
        prev=ptr;
        if(val<ptr->value){
            ptr=ptr->left;
            flag=1;
        }
        else{
            ptr=ptr->right;
            flag=2;
        }
    }
    if(flag==1)
        prev->left=NewNode(val);
    else
        prev->right=NewNode(val);
    return root;
}
node* minimum(node* ptr)
{
    node* prev=ptr;
    while(ptr->left){
        ptr=ptr->left;
        prev=ptr;
    }
    return prev;
}

node* Pminimum(node* ptr)
{
    node* prev=ptr;
    while(ptr->left){
        prev=ptr;
        ptr=ptr->left;
    }
    return prev;
}

node* maximum(node* ptr)
{
    node* prev=ptr;
    while(ptr->right){
        ptr=ptr->right;
        prev=ptr;
    }
    return prev;
}

node* Pmaximum(node* ptr)
{
    node* prev=ptr;
    while(ptr->right){
        prev=ptr;
        ptr=ptr->right;
    }
    return prev;
}

int search(node* root,int val)
{
    if(!root)
        return 1;
    node* prev=NULL;
    node* ptr=root;
    while(ptr){
        prev=ptr;
        if(val==ptr->value)
            return 0;
        if(val<ptr->value){
            ptr=ptr->left;
        }
        else{
            ptr=ptr->right;
        }
    }
    return 1;
}

node* del(node* root,int val)
{
    if(!root)
        return NULL;
    node* prev=NULL;
    node* ptr=root;
    int flag;
    while(ptr){

        if(val==ptr->value)
        {
            if(ptr->left)
            {
                node* maxi=maximum(ptr->left);
                node* p_maxi=Pmaximum(ptr->left);
                ptr->value=maxi->value;
                p_maxi->right=maxi->left;
                delete(maxi);
                return root;
            }
            else if(ptr->right)
            {
                node* mini=minimum(ptr->right);
                node* p_mini=Pminimum(ptr->right);
                ptr->value=mini->value;
                p_mini->left=mini->right;
                delete(mini);
                return root;
            }
            else{
                delete(ptr);
                if(flag==1)
                {
                    prev->left = NULL;
                }
                else
                    prev->right = NULL;
                return root;
            }
        }
        prev=ptr;
        if(val<ptr->value){
            ptr=ptr->left;
            flag = 1;
        }
        else{
            ptr=ptr->right;
            flag=2;
        }
    }
    return root;
}

void inorder(node *p)
{
    if (root == NULL)
    {
        cout<<"Tree is empty"<<endl;
        return;
    }
    if(p!=NULL)
    {
        inorder(p->left);
        cout << p->value << " ";
        inorder(p->right);
    }
}

int main()
{
    cout << "Input no. of elements to be inserted initially: ";
    int n;
    cin >> n;

    cout<<"Enter the numbers: "<<endl;
    for(int i=0;i<n;i++)
    {
        int c;
        cin>>c;
        root=insert(root,c);
    }

    while(1)
    {
        cout<<endl;
        cout << "Enter process no:"<<endl;
        cout << "1.Insert 2.Search 3.Delete 4.Inorder 5.Exit" << endl;
        int n;
        cin >> n;
        if(n==1)
        {
            int c;
            cout << "Enter value to be inserted: "<<endl;
            cin >> c;
            int k = search(root,c);
            if(k==1)
            root = insert(root,c);
            else
                cout << "Value already exists in the tree" << endl;
        }

        else if(n==2)
        {
            cout<<"Enter value to be searched "<<endl;
            int c;
            cin>>c;
            int b=search(root,c);
            if(b==1)
                cout<<"Value does not exist "<<endl;
            else
                cout<<"Value exists"<<endl;
        }
        else if(n==3)
        {
            cout<<"Enter value to be deleted"<<endl;
            int c;
            cin>>c;
            if(!search(root,c))
                root=del(root,c);
            else
                cout<<"Value does not exist"<<endl;
        }
        else if(n==4)
        {
            inorder(root);
            cout << endl;
            cout <<endl;
        }
        else if(n==5)
            return 0;
        else
        {
            cout << "Wrong case,Enter a valid value" <<endl;
            continue;
        }
    }
    return 0;
}
