package Stack.Implementation.Java;

// Java program to Implement a stack
// using singly linked list
// import package
import static java.lang.System.exit;

// Create Stack Using Linked list
class StackUsingLL {

	// A linked list node
	private class Node {

		int data; // integer data
		Node link; // reference variable Node type
	}
	// create global top reference variable global
	Node top;
	// Constructor
	StackUsingLL() { this.top = null; }

	// push :  add an element x in the stack
	public void push(int x) // insert at the beginning
	{
		// create new node temp and allocate memory
		Node temp = new Node();

		// initialize data into temp data field
		temp.data = x;

		// put top reference into temp link
		temp.link = top;

		// update top reference
		top = temp;
	}

	// isEmpty: To check if the stack is empty or
	// not
	public boolean isEmpty() { return top == null; }

	// peek : To return top element in a stack
	public int peek()
	{
		// check for empty stack
		if (!isEmpty()) {
			return top.data;
		}
		else {
			System.out.println("Stack is empty");
			return -1;
		}
	}

	// pop:remove top element from the stack
	public void pop() // remove at the beginning
	{
		// check for stack underflow
		if (top == null) {
			System.out.print("\nStack Underflow");
			return;
		}

		// update the top pointer to point to the next node
		top = (top).link;
	}

	public void display()
	{
		// check for stack underflow
		if (top == null) {
			System.out.printf("\nStack Underflow");
			exit(1);
		}
		else {
			Node temp = top;
			while (temp != null) {

				// print node data
				System.out.printf("%d->", temp.data);

				// assign temp link to temp
				temp = temp.link;
			}
		}
	}
}

// Driver code
class EntryPoint {
	public static void main(String[] args)
	{
		// create Object of Implementing class
		StackUsingLL st = new StackUsingLL();
			// insert Stack value
		st.push(11);
		st.push(22);
		st.push(33);
		st.push(44);

		// print Stack elements
		System.out.println("Stack elements before:");
		st.display();

		// print Top element of Stack
		System.out.printf("\npeek element is %d\n",
						st.peek());

		// Delete top element of Stack
		st.pop();
		st.pop();

		// print Stack elements
		System.out.println("Stack elements after:");
		st.display();

		// print Top element of Stack
		System.out.printf("\npeek element is %d\n",
						st.peek());
	}
}

