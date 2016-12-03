template <class T> class Tree
{
	public:
		class TNode
		{
			public:
			TNode()
			{
				left=right=NULL;
			}
			TNode(T idata,TNode *ileft=NULL,TNode *iright=NULL)
			{
				data=idata;
				left=ileft;
				right=iright;
			}
			T data;
			TNode *left;
			TNode *right;
		};
		Tree()
		{
			root=NULL;
		}
		~Tree()
		{
			if(!isTreeEmpty())
				deleteTree(root);
		}
		void deleteTree(TNode *ptr)
		{
			if(ptr->left!=NULL)
				deleteTree(ptr->left);
			if(ptr->right!=NULL)
				deleteTree(ptr->right);
			delete ptr;
		}
		bool isTreeEmpty()
		{
			return root==NULL;
		}
		bool searchElementRecursive(TNode *ptr,T idata)
		{
			if(ptr==NULL)
				return 0;
			if(ptr->data==idata)
				return 1;
			else if(ptr->data<idata)
				return searchElementRecursive(ptr->right,idata);
			else
				return searchElementRecursive(ptr->left,idata);
		}
		bool findElementRecursive(T idata)
		{
			return searchElementRecursive(root,idata);
		}
		bool findElementIterative(T idata)
		{
			TNode *ptr=root;
			while(ptr!=NULL)
			{
				if(ptr->data==idata)
					return 1;
				else if(ptr->data<idata)
					ptr=ptr->right;
				else
					ptr=ptr->left;
			}
			return 0;
		}
		void breadthFirstTopLeft()
		{
			TNode *ptr=root;
			if(ptr!=NULL)
			{
				Queue<TNode *> que;
				que.enqueue(ptr);
				while(!que.isQueueEmpty())
				{
					ptr=que.dequeue();
					cout<<ptr->data<<" ";
					if(ptr->left!=NULL)
						que.enqueue(ptr->left);
					if(ptr->right!=NULL)
						que.enqueue(ptr->right);
				}
				cout<<"\n";
			}
		}
		void breadthFirstTopRight()
		{
			TNode *ptr=root;
			if(ptr!=NULL)
			{
				Queue<TNode *> que;
				que.enqueue(ptr);
				while(!que.isQueueEmpty())
				{
					ptr=que.dequeue();
					cout<<ptr->data<<" ";
					if(ptr->right!=NULL)
						que.enqueue(ptr->right);
					if(ptr->left!=NULL)
						que.enqueue(ptr->left);
				}
				cout<<"\n";
			}
		}
		void breadthFirstBottomLeft()
		{
			TNode *ptr=root;
			Stack<TNode *> stk;
			if(ptr!=NULL)
			{
				Queue<TNode *> que;
				que.enqueue(ptr);
				while(!que.isQueueEmpty())
				{
					ptr=que.dequeue();
					stk.push(ptr);
					if(ptr->right!=NULL)
						que.enqueue(ptr->right);
					if(ptr->left!=NULL)
						que.enqueue(ptr->left);
				}
			}
			while(!stk.isStackEmpty())
			{
				ptr=stk.pop();
				cout<<ptr->data<<" ";
			}
			cout<<"\n";
		}
		void breadthFirstBottomRight()
		{
			TNode *ptr=root;
			Stack<TNode *> stk;
			if(ptr!=NULL)
			{
				Queue<TNode *> que;
				que.enqueue(ptr);
				while(!que.isQueueEmpty())
				{
					ptr=que.dequeue();
					stk.push(ptr);
					if(ptr->left!=NULL)
						que.enqueue(ptr->left);
					if(ptr->right!=NULL)
						que.enqueue(ptr->right);
				}
			}
			while(!stk.isStackEmpty())
			{
				ptr=stk.pop();
				cout<<ptr->data<<" ";
			}
			cout<<"\n";
		}
		void inorderRecursive(TNode *ptr)
		{
			if(ptr!=NULL)
			{
				inorderRecursive(ptr->left);
				cout<<ptr->data<<" ";
				inorderRecursive(ptr->right);
			}
		}
		void preorderRecursive(TNode *ptr)
		{
			if(ptr!=NULL)
			{
				cout<<ptr->data<<" ";
				preorderRecursive(ptr->left);
				preorderRecursive(ptr->right);
			}
		}
		void postorderRecursive(TNode *ptr)
		{
			if(ptr!=NULL)
			{
				postorderRecursive(ptr->left);
				postorderRecursive(ptr->right);
				cout<<ptr->data<<" ";
			}
		}
		void inorderRecursive()
		{
			inorderRecursive(root);
			cout<<"\n";
		}
		void preorderRecursive()
		{
			preorderRecursive(root);
			cout<<"\n";
		}
		void postorderRecursive()
		{
			postorderRecursive(root);
			cout<<"\n";
		}
		void preorderIterative()
		{
			TNode *ptr=root;
			if(ptr!=NULL)
			{
				Stack<TNode *> stk;
				stk.push(ptr);
				while(!stk.isStackEmpty())
				{
					ptr=stk.pop();
					cout<<ptr->data<<" ";
					if(ptr->right!=NULL)
						stk.push(ptr->right);
					if(ptr->left!=NULL)
						stk.push(ptr->left);
				}
				cout<<"\n";
			}
		}
		void postorderIterative()
		{
			TNode *ptr=root;
			Stack<TNode *> rstk;
			if(ptr!=NULL)
			{
				Stack<TNode *> stk;
				stk.push(ptr);
				while(!stk.isStackEmpty())
				{
					ptr=stk.pop();
					rstk.push(ptr);
					if(ptr->left!=NULL)
						stk.push(ptr->left);
					if(ptr->right!=NULL)
						stk.push(ptr->right);
				}
				while(!rstk.isStackEmpty())
				{
					ptr=rstk.pop();
					cout<<ptr->data<<" ";
				}
				cout<<"\n";
			}
		}
		void inorderIterative()
		{
			TNode *ptr=root;
			Stack<TNode *> stk;
			for(;ptr!=NULL;ptr=ptr->left)
				stk.push(ptr);
			while(!stk.isStackEmpty())
			{
				ptr=stk.pop();
				cout<<ptr->data<<" ";
				if(ptr->right!=NULL)
					for(TNode *tmp=ptr->right;tmp!=NULL;tmp=tmp->left)
						stk.push(tmp);
			}
			cout<<"\n";
		}
		void insert(T idata)
		{
			TNode *ptr=root;
			TNode *prev=NULL;
			while(ptr!=NULL)
			{
				prev=ptr;
				if(ptr->data<idata)
					ptr=ptr->right;
				else
					ptr=ptr->left;
			}
			if(root==NULL)
				root=new TNode(idata);
			else if(prev->data<idata)
				prev->right=new TNode(idata);
			else
				prev->left=new TNode(idata);
		}
		void findDeleteMerging(T idata)
		{
			TNode *ptr=root;
			TNode *prev=root;
			while(ptr!=NULL)
			{
				if(ptr->data==idata)
					break;
				else if(ptr->data<idata)
				{
					prev=ptr;
					ptr=ptr->right;
				}
				else
				{
					prev=ptr;
					ptr=ptr->left;
				}
			}
			if(ptr==NULL)
				cout<<"No element found: "<<idata<<endl;
			else if(prev==root)
				root=deleteMerging(ptr);
			else if(prev->left==ptr)
				prev->left=deleteMerging(ptr);
			else
				prev->right=deleteMerging(ptr);
		}
		TNode *deleteMerging(TNode *ptr)
		{
			if(ptr->left==NULL && ptr->right==NULL)
			{
				delete ptr;
				ptr=NULL;
			}
			else if(ptr->left==NULL)
			{
				TNode *tmp=ptr;
				ptr=ptr->right;
				delete tmp;
			}
			else if(ptr->right==NULL)
			{
				TNode *tmp=ptr;
				ptr=ptr->left;
				delete tmp;
			}
			else
			{
				TNode *tmp=ptr;
				TNode *prev=ptr;
				for(tmp=tmp->right;tmp->left!=NULL;prev=tmp,tmp=tmp->left);
				if(ptr->right!=tmp)
				{
					tmp->left=ptr->left;
					tmp->right=ptr->right;
					prev->left=NULL;
					delete ptr;
					ptr=tmp;
				}
				else
				{
					tmp->left=ptr->left;
					delete ptr;
					ptr=tmp;
				}
			}
			return ptr;
		}
		TNode *findDeleteCopying(TNode *ptr,T idata)
		{
			if(ptr==NULL);
			else if(ptr->data<idata)
				ptr->right=findDeleteCopying(ptr->right,idata);
			else if(ptr->data>idata)
				ptr->left=findDeleteCopying(ptr->left,idata);
			else
			{
				if(ptr->left==NULL && ptr->right==NULL)
				{
					delete ptr;
					ptr=NULL;
				}
				else if(ptr->left==NULL)
				{
					TNode *tmp=ptr;
					ptr=ptr->right;
					delete tmp;
				}
				else if(ptr->right==NULL)
				{
					TNode *tmp=ptr;
					ptr=ptr->left;
					delete tmp;
				}
				else
				{
					TNode *tmp=ptr;
					for(tmp=tmp->right;tmp->left!=NULL;tmp=tmp->left);
					ptr->data=tmp->data;
					ptr->right=findDeleteCopying(ptr->right,ptr->data);
				}
			}
			return ptr;
		}
		void findDeleteCopying(T idata)
		{
			root=findDeleteCopying(root,idata);
		}
		TNode *root;
};
