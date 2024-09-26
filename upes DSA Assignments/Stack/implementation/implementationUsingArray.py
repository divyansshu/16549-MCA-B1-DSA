
class StackUsingArray:
    
    def __init__(self,size) -> None:
        self.stack = []
        self.size = size
        
    def isFull(self):
        return self.size == len(self.stack) 
    
    def isEmpty(self):
        return len(self.stack) == 0   
    
    def push(self, item):
        if self.isFull():
            print("Stack is full, cannot insert new element")
            
        else:
            self.stack.append(item)
            print(f"pushed {item} to the stack")
            
    
    def pop(self):
        if self.isEmpty():
            print("Stack is empty, cannot delete an element")
            return
        
        else:
            self.stack.pop();
            print(f"{self.stack[-1]} is popped from stack")
            self.size -= 1                
            
    def peek(self):
        
        if self.isEmpty():
            print("Stack is empty")
            return
        
        else:
            print("Top element is: ",self.stack[-1])
            return
        
    def len(self):
        print("length of stack is: ", self.size)    
    
    def display(self):
         if self.isEmpty():
             print("stack is empty")
             
         else:
             print(self.stack[::-1])
  
  
             
s = StackUsingArray(4) # creating the stack of size 4
s.push(10)
s.push(20)
s.push(30)
s.push(40)
s.push(50) # output: Stack is full, cannot insert new element
s.len() # output: length of stack is: 4 
s.display() # output: [40,30,20,10]

s.peek() # output: 40

s.pop() # output: 30 is popped from stack
s.len() # output: length of stack is 3
s.display() #output: [30,20,10]
             
                    