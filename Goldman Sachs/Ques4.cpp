string encode(string s)
{     
    int l=1;
    string ans="",str="";
    str=s[0];
  for(int i=1;i<s.length();i++)
  {
      if(s[i]==s[i-1])
      {
          l++;
      }
      else
      {
          string s2=to_string(l);
          l=1;
          ans+=str;
          ans+=s2;
          str="";
          str+=s[i];
      }
  }
  ans+=str;

  string s2=to_string(l);
    ans+=s2;
  return ans;
  
  
}     