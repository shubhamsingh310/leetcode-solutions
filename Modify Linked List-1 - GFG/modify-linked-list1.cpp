//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
struct Node* modifyTheList(struct Node *head);
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

void print(Node *head)
{
    Node *temp=head;
	while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout<<endl;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};
*/
class Solution{
    public:
    Node* vectorToLinkedList(const std::vector<int>& vec) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int num : vec) {
        Node* newNode = new Node(num);
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}
    struct Node* modifyTheList(struct Node *head)
    {
       vector<int> v;
       while(head!=NULL)
       {
           v.push_back(head->data);
           head=head->next;
       }
       int c =v.size()/2;
       reverse(v.begin(),v.end());
       for(int i=0;i<c;i++)
       {
           v[i]=v[i]-v[v.size()-i-1];
       }
       Node *nhead=vectorToLinkedList(v);
       return nhead;
    }
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		struct Node *head = NULL,*temp=NULL;
		while(n--){
		    int a;
            cin>>a;
			Node *newNode = new Node(a);
			if(head==NULL)
                head=newNode;
            else
                temp->next=newNode;
            temp=newNode;
		}
		Solution obj;
		head = obj.modifyTheList(head);
		print(head);
		
	}
    return 0;
}
// } Driver Code Ends