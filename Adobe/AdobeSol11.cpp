string amendSentence (string s)
    {
        string str="",temp="";
        for(int i=0;i<s.length();i++)
        {
            if(islower(s[i]))
            {
                temp+=s[i];
            }
            else if(isupper(s[i]))
            {
                str+=temp;
                str+=" ";
                temp="";
                temp+=tolower(s[i]);
            }
        }
        str+=temp;
        if(str[0]==' ')
        return str.substr(1);
        else
        {
            return str;
        }
    }