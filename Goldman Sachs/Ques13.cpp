	string repeat(string str, int times) {
        string res = "";
        for (int i=0; i<times; i++)
            res += str;
        return res;
    }
    string decodedString(string s){
        int i=0;
        while (i < s.size()) 
        {
            if (s[i] != ']') 
            {
                i++;
                continue;
            }
            int j = i;
            while (s[j] != '[')
            {
                j--;
            }
            string r = s.substr(j+1, i-j-1);
            int k = j;
            j--;
            while ((j > 0) &&(isdigit(s[j]))) 
            {
                j--;
            }
            if (j != 0) 
            {
                j++;
            }
            int t = stoi(s.substr(j, k-j));
            s.replace(j, i-j+1, repeat(r, t));
            i = j+r.size()*t;
        }
        return s;
    }