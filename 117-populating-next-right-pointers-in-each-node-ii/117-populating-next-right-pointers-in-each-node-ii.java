class Solution {
    
    Node prev, leftmost;
    
    public void processChild(Node childNode) 
    {
        
        if (childNode != null) 
        {
            
         
            if (this.prev != null) 
            {
                this.prev.next = childNode;
                    
            } 
            else 
            {
                this.leftmost = childNode;
            }    
                
            this.prev = childNode; 
        }
    }
        
    public Node connect(Node root) 
    {
        
        if (root == null) 
        {
            return root;
        }
        
       
        this.leftmost = root;
        
        Node curr = leftmost;
        
      
        while (this.leftmost != null) 
        {
            
           
            this.prev = null;
            curr = this.leftmost;
        
            this.leftmost = null;
          
            while (curr != null) 
            {
                this.processChild(curr.left);
                this.processChild(curr.right);
                
                curr = curr.next;
            }
        }
                
        return root ;
    }
}