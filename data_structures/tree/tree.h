#include"queue.h"
#include"stack.h"
#include<climits>
using namespace std;
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
				TNode *left,*right;
		};
		Tree()
		{
			root=NULL;
		}
		~Tree()
		{
			if(!isTreeEmpty())
				deleteTreeRecursive(root);
		}
		// Is Tree Empty
		bool isTreeEmpty()
		{
			return root==NULL;
		}
		// Count number of nodes or size of the tree
		int sizeRecursive()
		{
			return sizeRecursive(root);
		}
		int sizeRecursive(TNode *ptr)
		{
			if(ptr!=NULL)
				return 1+sizeRecursive(ptr->left)+sizeRecursive(ptr->right);
			return 0;
		}
		// Find the height of the tree
		int heightRecursive()
		{
			heightRecursive(root);
		}
		int heightRecursive(TNode *ptr)
		{
			if(ptr==NULL)
				return 0;
			int lft=heightRecursive(ptr->left);
			int rgt=heightRecursive(ptr->right);
			if(ptr==root)
				return lft>rgt?lft:rgt;
			else
				return lft>rgt?lft+1:rgt+1;
		}
		// Find the height of the tree interative
		int heightIterative()
		{
			if(root==NULL)
				return 0;
			TNode *ptr=root;
			TNode *prev;
			Queue<TNode *> que;
			que.enq(ptr);
			que.enq(NULL);
			int count=-1;
			while(!que.isQueueEmpty())
			{
				prev=ptr;
				ptr=que.deq();
				if(prev==NULL && ptr==NULL)
					break;
				if(ptr==NULL)
				{
					count++;
					que.enq(NULL);
					continue;
				}
				if(ptr->left!=NULL)
					que.enq(ptr->left);
				if(ptr->right!=NULL)
					que.enq(ptr->right);
			}
			return count;
		}
		// Invert a tree recursive
		void invertRecursive()
		{
			if(root!=NULL)
				invertRecursive(root);
		}
		void invertRecursive(TNode *ptr)
		{
			if(ptr->left!=NULL)
				invertRecursive(ptr->left);
			if(ptr->right!=NULL)
				invertRecursive(ptr->right);
			TNode *tmp=ptr->right;
			ptr->right=ptr->left;
			ptr->left=tmp;
		}
		// least common ancestor
		void lcaTree(T idata1,T idata2)
		{
			Queue<TNode *> qu1;
			Queue<TNode *> qu2;
			TNode *lca=NULL;
			for(TNode *ptr=root;ptr->data!=idata1;)
			{
				qu1.enq(ptr);
				if(ptr->data<idata1)
					ptr=ptr->right;
				else
					ptr=ptr->left;
			}
			for(TNode *ptr=root;ptr->data!=idata2;)
			{
				qu2.enq(ptr);
				if(ptr->data<idata2)
					ptr=ptr->right;
				else
					ptr=ptr->left;
			}
			while(!qu1.isQueueEmpty() && !qu2.isQueueEmpty())
			{
				TNode *tmp1=qu1.deq();
				TNode *tmp2=qu2.deq();
				if(tmp1->data==tmp2->data)
					lca=tmp1;
				else
					break;
			}
			if(lca==NULL)
				cout<<"No common ancestor\n";
			else
				cout<<lca->data<<endl;
		}

		/*********** Tree Travesal **********/

		// Inorder recursive
        void inorderRecursive()
        {
			inorderRecursive(root);
			cout<<"\n";
        }
        void inorderRecursive(TNode *ptr)
        {
			if(ptr==NULL)
				return;
			inorderRecursive(ptr->left);
            cout<<ptr->data<<" ";
			inorderRecursive(ptr->right);
        }

        // Preorder recursive
        void preorderRecursive()
        {
			preorderRecursive(root);
            cout<<"\n";
        }
        void preorderRecursive(TNode *ptr)
        {
			if(ptr==NULL)
				return;
            cout<<ptr->data<<" ";
			preorderRecursive(ptr->left);
            preorderRecursive(ptr->right);
        }

        // Postorder recurisve
        void postorderRecursive()
        {
			postorderRecursive(root);
            cout<<"\n";
        }
        void postorderRecursive(TNode *ptr)
        {
			if(ptr==NULL)
				return;
			postorderRecursive(ptr->left);
            postorderRecursive(ptr->right);
            cout<<ptr->data<<" ";
        }

		// Inorder iterative
		void inorderIterative()
		{
			if(root==NULL)
				return;
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

		// Preorder iterative
		void preorderIterative()
		{
			if(root==NULL)
				return;
			TNode *ptr=root;
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

		// Postorder iterative
		void postorderIterative()
		{
			if(root==NULL)
				return;
			TNode *ptr=root;
			Stack<TNode *> stk,tmp_stk;
			tmp_stk.push(ptr);
			while(!tmp_stk.isStackEmpty())
			{
				ptr=tmp_stk.pop();
				stk.push(ptr);
				if(ptr->left!=NULL)
					tmp_stk.push(ptr->left);
				if(ptr->right!=NULL)
					tmp_stk.push(ptr->right);
			}
			while(!stk.isStackEmpty())
			{
				ptr=stk.pop();
				cout<<ptr->data<<" ";
			}
			cout<<"\n";
		}

		// Breadth first top-down left-right
        void bfsTopdownLeftright()
        {
            TNode *ptr=root;
            if(ptr==NULL)
                return;
            Queue<TNode *> que;
            que.enq(ptr);
            while(!que.isQueueEmpty())
            {
                ptr=que.deq();
                cout<<ptr->data<<" ";
                if(ptr->left!=NULL)
                    que.enq(ptr->left);
                if(ptr->right!=NULL)
                    que.enq(ptr->right);
            }
            cout<<"\n";
        }

        // Breadth first bottom-up right-left
        void bfsBottomupRightleft()
        {
            if(root==NULL)
                return;
            TNode *ptr=root;
            Stack<TNode *> stk;
            Queue<TNode *> que;
            que.enq(ptr);
            while(!que.isQueueEmpty())
            {
                ptr=que.deq();
                stk.push(ptr);
                if(ptr->left!=NULL)
                    que.enq(ptr->left);
                if(ptr->right!=NULL)
                    que.enq(ptr->right);
            }
            while(!stk.isStackEmpty())
            {
                ptr=stk.pop();
                cout<<ptr->data<<" ";
            }
            cout<<"\n";
        }

		void zigZagLevel()
		{
			if(root==NULL)
				return;
			TNode *ptr=root;
			Queue<TNode *> que;
			Stack<TNode *> stk;
			bool order=0;
			que.enq(ptr);
			que.enq(NULL);
			while(!que.isQueueEmpty())
			{
				int i;
				for(i=0;(ptr=que.deq())!=NULL;i++)
					stk.push(ptr);
				if(!i)
					break;
				order=order^1;
				while(!stk.isStackEmpty())
				{
					ptr=stk.pop();
					cout<<ptr->data<<" ";
					if(order)
					{
						if(ptr->left!=NULL)
							que.enq(ptr->left);
						if(ptr->right!=NULL)
							que.enq(ptr->right);
					}
					else
					{
						if(ptr->right!=NULL)
							que.enq(ptr->right);
						if(ptr->left!=NULL)
							que.enq(ptr->left);
					}
				}
				que.enq(NULL);
			}
			cout<<"\n";
		}

		/************************************/

		/************ Max/Min element ***********/

		// Maximum element in binary tree recursive (not BST)
		T findMaxBinaryTreeRecursion()
		{
			return findMaxBinaryTreeRecursion(root);
		}
		T findMaxBinaryTreeRecursion(TNode *ptr)
		{
			T max_val=INT_MIN;
			if(ptr==NULL)
				return max_val;
			T left_val=findMaxBinaryTreeRecursion(ptr->left);
			T right_val=findMaxBinaryTreeRecursion(ptr->right);
			return ptr->data>left_val?(ptr->data>right_val?ptr->data:right_val):(left_val>right_val?left_val:right_val);
		}

		// Maximum element in binary tree iterative (not BST)
		T findMaxBinaryTreeIterative()
		{
			int max_val=INT_MIN;
			TNode *ptr=root;
			if(ptr==NULL)
				return max_val;
			Queue<TNode *> que;
			que.enq(ptr);
			while(!que.isQueueEmpty())
			{
				ptr=que.deq();
				ptr->data>max_val?max_val=ptr->data:max_val;
				if(ptr->left!=NULL)
					que.enq(ptr->left);
				if(ptr->right!=NULL)
					que.enq(ptr->right);
			}
			return max_val;
		}

		// Find maximum recursive
        T maximumRecursive()
        {
            if(root!=NULL)
                return maximumRecursive(root);
            cout<<"Empty tree\n";
        }
        T maximumRecursive(TNode *ptr)
        {
            if(ptr->right==NULL)
                return ptr->data;
            else
                return maximumRecursive(ptr->right);
        }
        // Find minimum recursive
        T minRecursive()
        {
            if(root!=NULL)
                return minRecursive(root);
            cout<<"Empty Tree"<<endl;
        }
        T minRecursive(TNode *ptr)
        {
            if(ptr->left==NULL)
                return ptr->data;
            else
                return minRecursive(ptr->left);
        }

		/************************************/

		/********* Search element ***********/

		// Search an element in binary tree recursive (not BST)
		bool searchBinaryTreeRecursive(T idata)
		{
			return searchBinaryTreeRecursive(root,idata);
		}
		bool searchBinaryTreeRecursive(TNode *ptr,T idata)
		{
			if(ptr==NULL)
				return 0;
			if(ptr->data==idata || searchBinaryTreeRecursive(ptr->left,idata))
				return 1;
			else
				return searchBinaryTreeRecursive(ptr->right,idata);
		}

		// Search an element in binary tree iterative (not BST)
		bool searchBinaryTreeIterative(T idata)
		{
			if(root==NULL)
				return 0;
			TNode *ptr=root;
			bool ret_val=0;
			Queue<TNode *> que;
			que.enq(ptr);
			while(!que.isQueueEmpty())
			{
				ptr=que.deq();
				if(ptr->data==idata)
					ret_val=1;
				if(ptr->left!=NULL)
					que.enq(ptr->left);
				if(ptr->right!=NULL)
					que.enq(ptr->right);
			}
			return ret_val;
		}

		// Search an element recursive
        bool searchRecursive(T idata)
        {
            return searchRecursive(root,idata);
        }
        bool searchRecursive(TNode *ptr,T idata)
        {
            if(ptr==NULL)
                return 0;
            else if(ptr->data<idata)
                searchRecursive(ptr->right,idata);
            else if(ptr->data>idata)
                searchRecursive(ptr->left,idata);
            else
                return 1;
        }

		/************************************/

		/********** Insert element **********/

		// Insert element in binary tree recursive (not BST)
		void insertBinaryTreeRecursive(T idata)
		{
			insertBinaryTreeRecursive(root,idata);
		}
		void insertBinaryTreeRecursive(TNode *ptr,T idata)
		{
			if(ptr==NULL)
				ptr=new TNode(idata);
			else if(ptr->left==NULL)
				ptr->left=new TNode(idata);
			else if(ptr->right==NULL)
				ptr->right=new TNode(idata);
			else
				insertBinaryTreeRecursive(ptr->left,idata);
		}

		// Insert element in binary tree iterative (not BST)
		void insertBinaryTreeIterative(T idata)
		{
			if(root==NULL)
			{
				root=new TNode(idata);
				return;
			}
			TNode *ptr=root;
			Queue<TNode *> que;
			que.enq(ptr);
			while(!que.isQueueEmpty())
			{
				ptr=que.deq();
				if(ptr->left==NULL)
				{
					ptr->left=new TNode(idata);
					break;
				}
				if(ptr->right==NULL)
				{
					ptr->right=new TNode(idata);
					break;
				}
				que.enq(ptr->left);
				que.enq(ptr->right);
			}
			while(!que.isQueueEmpty())
				que.deq();
		}

		// Insert element recursive
		void insertElementRecursive(T idata)
		{
			if(root==NULL)
				root=new TNode(idata);
			else
				insertElementRecursive(root,idata);
		}
		void insertElementRecursive(TNode *ptr,T idata)
		{
			if(ptr->data<idata)
			{
				if(ptr->right==NULL)
					ptr->right=new TNode(idata);
				else
					insertElementRecursive(ptr->right,idata);
			}
			else
			{
				if(ptr->left==NULL)
					ptr->left=new TNode(idata);
				else
					insertElementRecursive(ptr->left,idata);
			}
		}

		// Insert element iterative
		void insertElementIterative(T idata)
		{
			if(root==NULL)
			{
				root=new TNode(idata);
				return;
			}
			TNode *ptr=root;
			for(;;)
			{
				if(ptr->data>idata)
				{
					if(ptr->left==NULL)
					{
						ptr->left=new TNode(idata);
						return;
					}
					ptr=ptr->left;
				}
				else
				{
					if(ptr->right==NULL)
					{
						ptr->right=new TNode(idata);
						return;
					}
					ptr=ptr->right;
				}
			}

		}

		/************************************/

		/********* Delete Tree **************/

		// Delete all elements recursive
        void deleteTreeRecursive(TNode *ptr)
        {
            if(ptr->left!=NULL)
                deleteTreeRecursive(ptr->left);
            if(ptr->right!=NULL)
                deleteTreeRecursive(ptr->right);
            //cout<<"Deleting "<<ptr->data<<endl;
            delete ptr;
        }

		void deleteTreeIterative()
		{
			if(root==NULL)
				return;
			Queue<TNode *> que;
			Stack<TNode *> stk;
			TNode *ptr=root;
			que.enq(ptr);
			while(!que.isQueueEmpty())
			{
				ptr=que.deq();
				if(ptr->left!=NULL)
					que.enq(ptr->left);
				if(ptr->right!=NULL)
					que.enq(ptr->right);
				stk.push(ptr);
			}
			while(!stk.isStackEmpty())
			{
				ptr=stk.pop();
//				cout<<"Deleting "<<ptr->data<<endl;
				delete ptr;
			}
		}			

		/***********************************/

		/******* Leaf & Full nodes *********/

		// Leaf nodes
		int findLeaves()
		{
			return findLeaves(root);
		}
		int findLeaves(TNode *ptr)
		{
			if(ptr==NULL)
				return 0;
			if(ptr->left==NULL && ptr->right==NULL)
				return 1;
			return findLeaves(ptr->left)+findLeaves(ptr->right);
		}
		int findFullNodes()
		{
			return findFullNodes(root);
		}
		int findFullNodes(TNode *ptr)
		{
			if(ptr==NULL)
				return 0;
			if(ptr->left!=NULL && ptr->right!=NULL)
				return 1+findFullNodes(ptr->left)+findFullNodes(ptr->right);
			else
				return findFullNodes(ptr->left)+findFullNodes(ptr->right);
		}
		/***********************************/
		
		TNode *root;
};
