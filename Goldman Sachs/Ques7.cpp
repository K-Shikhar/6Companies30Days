int findPosition(int n , int m , int k) {
        if(n==1)
            return 1;
        
        if((m+k-1)%n==0)
            return n;
            
        return (m+k-1)%n;
    }