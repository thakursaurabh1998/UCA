int* cutSticks(int lengths_count, int* lengths, int* result_count) {

    int i,j;
    int arr[1000]={0};
    int min = lengths[i];
    int lower;
    int* result=(int*)malloc(sizeof(int)*lengths_count);
    int r = 0;
    int index[1000];
    int in=0;
    for(i=0;i<lengths_count;i++)
    {
        if(arr[lengths[i]]==0)
            index[in++]=lengths[i];
        arr[lengths[i]]+=1;
        if(lengths[i]<min)
            min=lengths[i];
    }
    int flag,newmin;
    for(j=0;j<in;j++){
        int sum=0;
        flag=1;
        for(i=min;i<1000;i++)
        {
            sum+=arr[i];
            if(arr[i]!=0 && i>min && flag==1){
                flag=0;
                newmin = i;
            }
        }
        min=newmin;
        result[r++] = sum;
    }
    *result_count = in;
    return result;
}


int maxDifference(int a_count, int* a) {
    
    int i,j,pin,maxd,diff;
    pin = 0;
    maxd = a[1]-a[0];
    for(i=1;i<a_count;i++)
    {
        diff = a[i] - a[pin];
        if(a[i]<a[pin])
        {
            pin=i;
        }
        if(maxd<diff)
            maxd=diff;
    }
    if(maxd<=0)
        return -1;
    else
        return maxd;
}