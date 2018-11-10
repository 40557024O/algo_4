#include <stdio.h>
#include <algorithm>
#include <stdlib.h>

using namespace std;

struct Box
{
    int arr[3]= {};
    struct Box *next=0;
    int depth=0;

};

void Copy(int arr[],int a[])
{
    for(int i=0; i<3; i++)
    {
        arr[i]=a[i];
    }
}

bool z(struct Box a,struct Box b)
{
    return a.arr[0]<b.arr[0];
}

bool y(struct Box a,struct Box b)
{
    return a.arr[1]<b.arr[1];
}

bool x(struct Box a,struct Box b)
{
    return a.arr[2]<b.arr[2];
}

bool Check(struct Box a,struct Box b)
{
    if(a.arr[0]<b.arr[0]&&a.arr[1]<b.arr[1]&&a.arr[2]<b.arr[2])//if a is smaller ,then return 1 1and insert in the front
    {
        return true;
    }
    else
    {
        return false;
    }

}

int main()
{
    int num=0;
    scanf("%d",&num);
    //struct Box *box=(struct Box*)malloc(num*sizeof(struct Box));
    Box box[1000];
    for(int i=0; i<num; i++)
    {
        int a[3]= {};
        scanf("%d%d%d",&a[0],&a[1],&a[2]);
        sort(a,a+3);
        Copy(box[i].arr,a);
        box[i].depth=1;

    }
    sort(box,box+num,x);
    sort(box,box+num,y);
    sort(box,box+num,z);
    /*for(int i=0;i<num;i++)
    {
        printf("\n%d %d %d\n",box[i].arr[0],box[i].arr[1],box[i].arr[2]);
    }*/

	int max=0;
    for(int i=1; i<num; i++)
    {
        for(int j=i-1; j>=0; j-=1)
        {
            if(Check(box[j],box[i]))
            {
                if(box[i].depth<=box[j].depth)
                {
                	box[i].next=&box[j];
                	//printf("%d(%d)-> %d(%d)\n",i,box[i].depth,j,box[j].depth);
                	box[i].depth=box[j].depth+1;
				}
				
                
                if(box[i].depth>max)
                {
                	max=box[i].depth;
					//printf("[%d]\n",i);
                	break;
				}
                
            }
          

        }
        //printf("%d\n",box[i].depth);

    }
    //max+=1;
    printf("%d",max);
    







}



