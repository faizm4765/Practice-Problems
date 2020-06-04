
void swap(int arr[],int a ,int b){
    int t = arr[a];
    arr[a] = arr[b];
    arr[b] = t;
}


void sort012(int a[], int n)
{
    // coode here 
    int l = 0,m = 0, h = n-1;
    while(m<=h){
        if(a[m] == 0){
            swap(a,l,m);
            l++;
            m++;
        }else if(a[m] == 1){
            m++;
        }else if(a[m] == 2){
            swap(a,m,h);
            h--;
        }
    }
}
