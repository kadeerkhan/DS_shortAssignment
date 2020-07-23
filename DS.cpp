bool proper_prefix_stack(string S, string T)
{
	if(S.length()>=T.length())
	{
		return false;		//if length of S is equal to or greater than length of T then S is not a proper prefix of T
	}
	Stack<char> stack_s;//create stack for S
	Stack<char> stack_t;//create stack for T
	for(int i=0;i<S.length();++i)
	{
		stack_s.push(S[i]);//push characters of S in stack for S
		stack_t.push(T[i]);//push characters of T in stack for T
	}
	char s,t;
	while(!stack_s.isempty())//if characters of S are still remaining
	{
		s=stack_s.pop(); //pop character from stack for S
		t=stack_t.pop(); //pop character from stack for T
		if(t!=s)//compare both characters
		{
			return false;// if characters are not same then S is not a proper prefix of T
		}
	}
	return true; //lengths of S and T are same. Every character of S matches with sith starting character of T. S is a proper prefix of T
}

bool proper_prefix_queue(string S, string T)
{
	if(S.length()>=T.length())
	{
		return false;		//if length of S is equal to or greater than length of T then S is not a proper prefix of T
	}
	Queue<char> queue_s;//create queue for S
	Queue<char> queue_t;//create queue for T
	for(int i=0;i<S.length();++i)
	{
		queue_s.enqueue(S[i]);//enqueue characters of S in queue for S
		queue_t.enqueue(T[i]);//enqueue characters of T in queue for T
	}
	char s,t;
	while(!queue_s.isempty())//if characters of S are still remaining
	{
		s=queue_s.dequeue(); //dequeue character from queue for S
		t=queue_t.dequeue(); //dequeue character from queue for T
		if(t!=s)//compare both characters
		{
			return false;// if characters are not same then S is not a proper prefix of T
		}
	}
	return true; //lengths of S and T are same. Every character of S matches with sith starting character of T. S is a proper prefix of T
}


int E_D(string S, string T)// method takes 2 strings
{
	int d=S.length()-T.length();//takes the difference between lenths of the two strings, d>0 means inserting and d<0 means deleting
	dl_Linked_List<char> B;//Doubly linked list used as stack
	for(int i=0;i<S.length();++i)
	{
		B.insert(S[i]);//filling the array with one of string's charcters
	}
	while(!B.isempty())//loop for popping out of stack
	{
		char s=B.getat(0);//popping out of stack
		for(int j=0;j<T.length();++j)//loop for checking in other string
		{
			if(T[j]==s)
			{
				T[j]='-'; //mark '-' if the character exists
				break;//marking only once and break
			}
		}
		B.remove(0);//popping out of stack
	}
	int m=0;
	for(int i=0;i<T.length();++i)
	{
		if(T[i]!='-')
		{
			++m;//counting the unmatched characters that will either have to modified or deleted
		}
	}
	if(d<0)
	{
		d=0;//if the difference is negative then they have to be deleted, which is already done so in this case it's effect should be zero
	}
	return m+d;//add the differnce with the unmatched and return. 
}


void Butterfly(int A[],int nA,ni,nj,nk,nl)//Takes arguments a cycle, size of cycle, 4 elements(integer in our case)
{
	sl_Linked_List B; //singly link linked list for storing cycle
	for(int i=0;i<nA;++i)//loop for inserting the elements in the linked list
	{
		if(A[i]==nj)//condition to check whether should start performing the butterfly operation
		{
			sl_Linked_List T;//temporary Linked list to use as stack for reversing the elements for butterfly operation
			for(;A[i]!=nl;++i)//loop for inserting elements in stack 
			{
				T.insert(0,A[i]);//insertion in stack
			}
			while(!T.isempty())//loop for emptying the stack in into the main cycle
			{
				B.insert(T.getat(0));//reverse insertion in maincycle
				T.remove(0);//poping the element from stack
			}
		}
		B.insert(A[i]);//inserting into the main cycle before and after the butterfly operation
			
	}
}