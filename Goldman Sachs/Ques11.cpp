int *findTwoElement(int *arr, int n) {

        long long repeating;
        int missing=0;
        for(int i=0;i<n;i++)
        {
            int k=abs(arr[i]);
            missing^=(abs(arr[i])^(i+1));
            if(arr[k-1]<0)
            {
                repeating=k;
            }
            else
            {
                arr[k-1]*=-1;
            }
        }
        missing^=repeating;
        int a[2]={repeating,missing};
        int *ptr=a;
        return ptr;
    }