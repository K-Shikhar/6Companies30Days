class Solution
{
    public:
    void linkdelete(struct Node  *head, int M, int N)
    {
       Node* temp=head;
        while(temp!=NULL)
        {
            int p=M-1,q=N+1;
            while(p--)
            {
                if(temp==NULL)
                {
                    return;
                }
                temp=temp->next;
            }
            if(!temp)
            {
                return;
            }
            Node* temp2=temp;
            while(q--)
            {
                if(temp2==NULL)
                {
                    temp->next=NULL;
                    return;
                }
                temp2=temp2->next;
            }
            temp->next=temp2;
            temp=temp2;
        }

    }
};