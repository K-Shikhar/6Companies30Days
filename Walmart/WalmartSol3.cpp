bool winnerOfGame(string colors) 
    {
        int ca=0,cb=0;
        for(int i=1;i<colors.size()-1;i++)
        {
            if(colors[i]=='A' && colors[i+1]=='A' && colors[i-1]=='A')
            {
                ca++;
            }
            if(colors[i]=='B' && colors[i+1]=='B' && colors[i-1]=='B')
            {
                cb++;
            }
        }
        if(ca>cb)
        {
            return true;
        }
        return false;
    }