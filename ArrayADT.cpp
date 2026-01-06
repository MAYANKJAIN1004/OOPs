#include <iostream>
using namespace std;

class arrayADT
{
    private:
        int capacity;
        int lastindex;
        int *ptr;
    public:
        arrayADT()
        {
            capacity = 10;
            lastindex = -1;
            ptr = NULL;
        }
        arrayADT(arrayADT &ref)
        {
            capacity = ref.capacity;
            lastindex = ref.lastindex;
            ptr = new int[capacity];
            for(int i=0;i<=ref.lastindex;i++)
            {
                ptr[i] = ref.ptr[i];
            }
        }
        void CreateArray(int);
        int getItem(int);
        void setItem(int,int);
        void editItem(int,int);
        void removeItem(int);
        int searchItem(int);
        friend ostream& operator<<(ostream &dout,arrayADT a);
        void sortArray()
        {
            for(int i=0;i<lastindex;i++)
            {
                for(int j=0;j<lastindex-i;j++)
                {
                    if(ptr[j]>ptr[j+1])
                    {
                        int temp = ptr[j];
                        ptr[j] = ptr[j+1];
                        ptr[j+1] = temp;
                    }
                }
            }
        }
        int countItems()
        {
            return lastindex+1;
        }
        void display()
        {
            cout<<capacity<<" "<<lastindex<<" "<<ptr<<endl;
        }
        ~arrayADT()
        {
            delete []ptr;
        }
};

ostream& operator<<(ostream &dout,arrayADT a)
{
    for(int i=0;i<a.countItems();i++)
    {
        cout<<a.getItem(i)<<" ";
    }
    return dout;
}

int arrayADT::searchItem(int value)
{
    if(lastindex == -1)
    {
        cout<<"Array is empty"<<endl;
        return -1;
    }
    else
    {
        for(int i=0;i<=lastindex;i++)
        {
            if(ptr[i] == value)
            {
                return i;
            }
        }
        return -1;
    }
}
void arrayADT::removeItem(int indx)
{
    if(lastindex == -1)
    {
        cout<<"Array is empty"<<endl;
    }
    else if(indx < 0 || indx > lastindex)
    {
        cout<<"Invalid index"<<endl;
    }
    else
    {
        int i=indx;
        while(i<lastindex)
        {
            ptr[i] = ptr[i+1];
            i++;
        }
        lastindex--;
    }
}

void arrayADT::editItem(int indx, int value)
{
    if(lastindex == -1)
    {
        cout<<"Array is empty"<<endl;
    }
    else if(indx < 0 || indx > lastindex)
    {
        cout<<"Invalid index"<<endl;
    }
    else
    {
        ptr[indx] = value;
    }
}

void arrayADT::setItem(int indx, int value)
{
    if(lastindex == capacity-1)
    {
        cout<<"Array is full"<<endl;
    }
    else if(indx<0 || indx>capacity-1)
    {
        cout<<"Invalid index"<<endl;
    }
    else if(indx>lastindex+1)
    {
        cout<<"Cannot skip index"<<endl;
    }   
    else if(indx <= lastindex)
    {
        lastindex++;
        int i=lastindex;
        while(i>indx)
        {
            ptr[i] = ptr[i-1];
            i--;
        }
        ptr[indx] = value;
    }
    else
    {
        ptr[indx] = value;
        lastindex++;
    }
}

int arrayADT::getItem(int indx)
{
    if(lastindex == -1)
    {
        cout<<"Array is empty"<<endl;
    }
    else if(indx < 0 || indx > lastindex)
    {
        cout<<"Invalid index"<<endl;
    }
    else
    {
        return ptr[indx];
    }
    return -1;
}

void arrayADT::CreateArray(int capacity)
{
    this->capacity = capacity;
    lastindex = -1;
    ptr = new int[capacity];

    //cout<<this->capacity<<" "<<lastindex<<" "<<sizeof(ptr)<<endl;
}

int main()
{
    arrayADT arr;
    arr.CreateArray(5);
    arr.setItem(0,10);
    arr.setItem(1,5);
    arr.setItem(2,30);
    arr.setItem(1,20);
    //arr.display();
    cout<<arr<<endl;
    arr.editItem(2,45);
    cout<<arr<<endl;
    arr.removeItem(1);
    cout<<arr<<endl;
    arr.sortArray();
    cout<<arr<<endl;

    return 0;
}