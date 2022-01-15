class Solution{
public:
    int minSteps(int D){
        int n = ceil(0.5*sqrt(1+8.0*D)-0.5);
        int m = floor(0.5*sqrt(1+8.0*D)-0.5);
        if(((n*(n+1)/2)-D)%2==0)
        {
            return n;
        }
        else
        {
            int a=n%2;
            n++;
            return n+a;
        }
        
    }
};