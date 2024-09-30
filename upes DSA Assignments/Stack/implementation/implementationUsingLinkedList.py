class Node:
    def __init__(self, data) -> None:
        self.data = data
        self.next = None
        
class StackUsingLinkedList:
    def __init__(self) -> None:
        self.head = None
    
    #push an element to the stack
    def push(self, data):
        newNode = Node(data)
        
        #if stack is empty
        if self.head == None:
            self.head = newNode
            
        else:
            newNode.next = self.head
            self.head = newNode
            
        print(f"{data} is pushed into stack")
            
            
            
    def pop(self):
        
        #if stack is empty
        if self.isEmpty():
            print("cannot pop stack is empty")
            return
        # if stack is not empty
        else:
            curr = self.head
            print(f"{curr.data} is popped from stack")
            self.head = curr.next 
            
    def peek(self):
        
         #if stack is empty
        if self.isEmpty():
            print("stack is empty")
            return
        else:
            print(f"{self.head.data} is top element")
            
    def isEmpty(self):
        return self.head is None
                             
    
    def display(self):
        
        #if stack is empty
        if self.isEmpty():
            print("Stack is empty")
            return
        
        curr = self.head
        while curr != None:
            print(curr.data)
            curr = curr.next
            
                        
s = StackUsingLinkedList()

s.push(10) # output: 10 is pushed into stack
s.push(20) # output: 20 is pushed into stack
s.push(30) # output: 30 is pushed into stack
s.push(40) # output: 40 is pushed into stack

s.display() # output: 40 30 20 10

s.peek() # output: 40 is top element

s.pop() # output: 40 is popped from stack
s.pop() # output: 30 is popped from stack
s.pop() # output: 20 is popped from stack
s.pop() # output: 10 is popped from stack
s.display()   # output: stack is empty

       
            
                
            
            
    
                 