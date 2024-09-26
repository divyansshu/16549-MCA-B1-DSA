'''
operations on singly linked list:
* insert at front
* insert at end
* insert at mid
* delete at front
* delete at end
* delete at mid
* traverse and display list
* clear list
* length of list

'''

class Node:
    def __init__(self,value) -> None:
        self.data = value
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
        self.n = 0
        
    def __len__(self):
        return self.n
    
    '''insert at the end of the linked list'''
    def insert_at_end(self, value):
        
        ## create a new node
        newNode = Node(value)      
        
        ## if linked list is empty
        if self.head == None:
            self.head = newNode
                  
        ## if linked list is not empty
        else:
            curr = self.head
            while curr.next != None:
                curr = curr.next
            curr.next = newNode
        self.n = self.n + 1    
        
    ''' insert from the front of a linked list '''
    def insert_at_front(self,value):
          ## create a new node
        newNode = Node(value)      
        
        ## if linked list is empty
        if self.head == None:
            self.head = newNode 
            
        else:
            newNode.next = self.head
            self.head = newNode
        self.n = self.n + 1    
    
    
    ''' insert at the middle of a linked list ''' 
    def insert_at_mid(self, data, value):
         ## create a new node
        newNode = Node(value)      
        
        ## if linked list is empty
        if self.head == None:
            self.head = newNode
            
        ## if linked list is not empty
        else:
            curr = self.head
            while curr != None:
                if curr.data == data:
                    newNode.next = curr.next
                    curr.next = newNode
                    break
                curr = curr.next
            if curr == None:
                print(f"{data} is not present in list")        
        self.n = self.n + 1            
                     
    '''empty the linked list'''
    def clear(self):
        self.head = None
        self.n = 0
        
    '''delete the node from the front '''
    def delete_at_front(self):
              
        ## if linked list is empty
        if self.head == None:
            print('list is already empty')
            return
        else:
            curr = self.head
            self.head = curr.next
        self.n = self.n - 1 
    
    
    '''delete the node from the end'''
    def delete_at_end(self):
        
         ## if linked list is empty
        if self.head == None:
            print('list is already empty')
            return 
        
        ## if list contain only one node
        elif self.head.next == None:
            self.head = None
                       
        else:
            curr = self.head
            while curr.next.next != None:
                curr = curr.next
            curr.next = None
            
        self.n = self.n - 1    
    
    '''delete a node after a given node'''  
    def delete_at_mid(self, data):
        
         ## if linked list is empty
        if self.head == None:
            print('list is already empty')
            return 
        
        ## if only one node is present
        elif self.head.next == None:
            self.head = None
            
        ## if first node is to be deleted
        elif self.head.data == data:
            self.delete_at_front()
            return    
        
        else:
            curr = self.head
            prev = None

            while curr != None:
                if curr.data == data:
                    break
                else:
                    prev = curr
                    curr = curr.next
                    
            ## if node not present in list
            if curr == None:
                print("node not present")
                return
            ## if node is present
            else:
                 prev.next = curr.next       
        self.n = self.n - 1        
                                                                 
    
    ''' traverse to each node and display the data '''                
    def display(self):
        
        ## if list is empty
        if self.head == None:
            print('list is empty')
        else:
             curr = self.head
             while curr != None:
                 print(curr.data, end=" ")
                 curr = curr.next
           
                                
              
L = LinkedList()
L.insert_at_end(10)
L.insert_at_end(20)
L.insert_at_end(30)
L.insert_at_end(40)
L.display()
print("\n",L.__len__())

# L.insert_at_mid(10,15)
# L.insert_at_mid(20,25)
# L.insert_at_mid(30,35)
# L.display()

# L.insert_at_front(10)
# L.insert_at_front(20)
# L.insert_at_front(30)
# L.display()
# print("\n",L.__len__())

# L.delete_at_front()
# L.display()
# print("\n",L.__len__())

# L.delete_at_end()
# L.display()
# print("\n",L.__len__())

L.delete_at_mid(10)
L.display()
print("\n",L.__len__())
       