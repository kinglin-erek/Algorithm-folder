const int CurrentSize = 20;
struct node{
    int key;
    int data;
};

node Element[CurrentSize];

int BinarySearch(const int x){
    int high = CurrentSize-1, low = 0,mid;
    while(low <= high){
        mid =(low + high)/2;
        if(x>Element[mid].key) low = mid+1;
        else if(x<Element[mid].key) high = mid -1;
        else return mid + 1;
    }
    return 0;
}

int BinarySearchl(const int x, int low, int high)
{
    int mid=0;
    if(low <= high)
    {
        mid = (low + high) / 2;
        if (x > Element[mid-1].key)
            mid = BinarySearchl(x,mid+1,high);
        else if (x < Element[mid-1].key)
            mid = BinarySearchl(x,low,mid-1);
    }
    return mid;
}