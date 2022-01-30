double r,x,y;
    Solution(double radius, double x_center, double y_center) {
        r=radius;
        x=x_center;
        y=y_center;
    }
    
    vector<double> randPoint() 
    {
        
        double dist=r*sqrt(((double)rand()/RAND_MAX));
        double angle=2*M_PI*((double)rand()/RAND_MAX);
        double xcor= x+dist*(cos(angle));
        double ycor= y+dist*(sin(angle));
        
        return {xcor,ycor};
    }