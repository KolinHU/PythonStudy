## #1 顺序表

//Seqlist.h

const int DefaultSize = 100;

template <typename Type>
class Seqlist
{
  public:
    Seqlist(int sz = DefaultSize) : m_nmaxsize(sz), m_ncurrentsize(-1)
    {
        if (sz > 0)
        {
            m_elements = new Type[m_nmaxsize];
        }
    }

    ~SeqList()
    {
        delete[] m_elements;
    }

    int Length()
    {
        return m_ncurrentsize + 1;
    }

    int Find(Type x) const;

    int IsElement(Type x) const;

    int Insert(Type x, int i);

    int Remove(Type x);

    int IsEmpty()
    {
        return m_ncurrentsize == -1;
    }

    int IsFull()
    {
        return m_ncurrentsize = m_nmaxsize - 1;
    }

    Type Get(int i)
    {
        return i < 0 || i > m_ncurrentsize ? (cout << "no this element" << endl;) : m_elements[i];
    }

    void Print();

  private:
    Type *m_elements;
    const int m_nmaxsize;
    int m_ncurrentsize;
}

template <typename Type>
int Seqlist<Type>::Find(Type x) const
{
    for (int i = 0; i < m_ncurrentsize, i++)
    {
        if (m_elements[i] == x)
        {
            return i;
        }
        else
        {

            cout << "can not find this element" << endl;
            return -1;
        }
    }
}

template <typename Type>
int SeqList<Type>::IsElement(Type x) const
{
    if (Find(x) == -1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

template <typename Type>
int SeqList<Type>::Insert(Type x, int i)
{
    if (i < 0 || i > m_ncurrentsize || m_ncurrentsize = m_nmaxsize - 1)
    {
        cout << "this operate is illegal" << endl;
        return 0;
    }
    m_ncurrentsize++;

    for (int j = m_ncurrentsize; j > i; j--)
    {
        m_elements[j] = m_elements[j - 1];
    }
    m_melement[i] = x;

    return 1;
}

template <typename Type>
int Seqlist<Type>::Remove(Type x)
{
    int size = m_ncurrentsize;
    for (int i = 0; i < m_ncurrentsize; i++)
    {
        if (m_elementsp[i] == x)
        {
            for (int j = i; j < m_ncurrentsize; j++)
            {
                m_elements[j] = m_elements[j + 1];
            }
            m_ncurrentsize--;
            continue;
        }
    }

    if (size = m_ncurrentsize)
    {
        cout << "no this data" << endl;
        return 0;
    }
    return 1;
}

template <typename Type>
void SeqList<Type>::Print()
{
    for (int i = 0; i <= m_ncurrentsize; i++)
    {
        cout << i + 1 << ":\t" << m_elements[i] << endl;
    }
    cout << endl
         << endl;
}

//test
int main()
{
    SeqList<int> test(15);
    int array[15] = {2, 5, 8, 1, 9, 9, 7, 6, 4, 3, 2, 9, 7, 7, 9};
    for (int i = 0; i < 15; i++)
    {
        test.Insert(array[i], 0);
    }
    test.Insert(1, 0);
    cout << (test.Find(0) ? "can't be found " : "Be found ") << 0 << endl
         << endl;
    test.Remove(7);
    test.Print();
    test.Remove(9);
    test.Print();
    test.Remove(0);
    test.Print();
    return 0;
}



##  2 单链表

//ListNode.h

template <typename Type>
class SingleList;

template <typename Type>
class ListNode
{
    private:
    friend typename SingleList<Type>;

    ListNode():m_pnext(null){}
    ListNode(const Type item,ListNode<Type> *next=null):m_data(item),m_pnext(next){}
    ~ListNode()
    {
        m_pnext=null;
    }

    public:
    Type GetData();
    friend ostream& operator<< <Type>(ostream&,ListNode<Type>& );

    private:
    Type m_data;
    ListNode *m_pnext; 

}

template <typename Type>
Type ListNode<Type>::GetData()
{
    return this->m_data;
}

template <typename Type> 
ostream& operator<<(ostream& os,ListNode<Type>& out)
{
    os<<out->m_data;
    return os;
}

//SingleList.h

# include "ListNode.h"

template <typename Type>
class SingleList
{
    public:
    SingleList():head(new ListNode<Type>()){}
    ~SingleList()
    {
        MakeEmpty();
        delete head;
    }

    public:
    void MakeEmpty();
    int Length();
    ListNode<Type> *Find(Type value,int n);
    ListNode<Type> *Find(int n);
    bool Insert(Type item,int n=0);
    Type Remove(int n=0);
    bool RemoveAll(Type item);
    Type Get(int n);
    void Print();

    private:
    ListNode<Type> *head;

}

template <typename Type>
void SingleList<Type>::MakeEmpty()
{
    ListNode<Type> *pdel;
    while(head->m_pnext!=null)
    {
        pdel=head->m_pnext;
        head->m_pnext=pdel->m_pnext;
        delete pdel;
    }
}

template <typename Type>
int SingleList<Type>::Length()
{
    ListNode<Type> *pmove=head->m_pnext;
    int count=0;
    while(pmove!=null)
    {
        pmove=pmove->m_pnext;
        count++;
    }
    return count;
}

template <typename Type>
ListNode<Type>* SingleList<Type>::Find(int n)
{
    if(n<0)
    {
        cout<<"the n is out of boundary"<<endl;
        return null;
    }
    ListNode<Type> *pmove=head->m_pnext;
    for(int i=0;i<n&&pmove;i++)
    {
        pmove=pmove->m_pnext;
    }

    if(pmove==null)
    {
        cout<<"the n is out of boundary"<<endl;
        return null;
    }

    return pmove;

}

template <typename Type>
ListNode<Type>* SingleList<Type>::Find(Type value,int n)
{
    if(n<1)
    {
        cout<<"the n is illegal"<<endl;
        return null;
    }
    ListNode<Type> *pmove=head;
    int count=0;
    while(count!=n&&pmove)
    {
       pmove=pmove->m_pnext;
       if(pmove->m_data==value)
       {
           count++;
       }
    }

    if(pmove==null)
    {
        cout<<"the n is out of boundary"<<endl;
        return null;
    }

    return pmove;
}

template <typename Type>
bool SingleList<Type>::Insert(Type item,int n)
{
    if(n<0)
    {
        return 0;
    }

    ListNode<Type> *pmove=head;
    ListNode<Type> *pnode=new ListNode<Type>(item);

    if(pnode==null)
    {
        return 0;
    }

    for(int i=0;i<n&&pmove;i++)
    {
        pmove=pmove->m_pnext;
    }
    if(pmove==null)
    {
        cout<<"the n is illegal"<<endl;
        return 0;
    }

    pnode->m_pnext=pmove->m_pnext;
    pmove->m_pnext=pnode;
    return 1;

} 

template <typename Type>
bool SingleList<Type>::RemoveAll(Type item)
{
    ListNode<Type> *pmove=head;
    ListNode<Type> *pdel=head->m_pnext;

    while(pdel!=null)
    {
        if(pdel->m_data==item)
        {
            pmove->m_pnext=pdel->m_pnext;
            delete pdel;
            pdel
        }

        pmove=pmove->m_pnext;
        pdel=pdel->m_pnext;
    }
    return 1;
}

template <typename Type>
Type SingleList<Type>::Remove(int n)
{
    if(n<0)
    {
        exit(1);
    }
    ListNode<Type> *pmove=head,*pdel;
    for(int i=0;i<n&&pmove->m_pnext;i++)
    {
        pmove=pmove->m_pnext;
    }

    if(pmove->m_pnext==null)
    {
        cout<<"no this element"<<endl;
        exit(1);
    }

    pdel=pmove->m_pnext;
    pmove->m_pnext=pdel->m_pnext;
    Type temp=pdel->m_data;
    delete pdel;
    return temp;
}



### 3 循环链表(对比普通链表，讲末尾的NULL换成head)

// ListNode.h
template <typename Type>
class CircularList;

template <typename Type>
class ListNode
{
    private:
    friend typename CircularList<Type>;

    ListNode():m_pnext(null){}
    ListNode(const Type item,ListNode<Type> *next=null):m_data(item),m_pnext(next){}
    ~ListNode()
    {
        m_pnext=null;
    }

    private:
    Type m_data;
    ListNode *m_pnext; 
}

//CircularList.h

# include "ListNode.h"

template <typename Type>
class CircularList
{
    public:
    CircularList():head(new ListNode<Type>())
    {
        head->m_pnext=head;
    }
    ~SingleList()
    {
        MakeEmpty();
        delete head;
    }

    public:
    void MakeEmpty();
    int Length();
    ListNode<Type> *Find(Type value,int n);
    ListNode<Type> *Find(int n);
    bool Insert(Type item,int n=0);
    Type Remove(int n=0);
    bool RemoveAll(Type item);
    Type Get(int n);
    void Print();

    private:
    ListNode<Type> *head;

}

template <typename Type>
void CircularList<Type>::MakeEmpty()
{
    ListNode<Type> *pdel,*pmove=head;
    while(pmove->m_pnext!=head)
    {
        pdel=pmove->m_pnext;
        pmove->m_pnext=pdel->m_pnext;
        delete pdel;
    }
} 

template <typename Type>
int CircularList<Type>::Length()
{
    ListNode<Type> *pmove=head;
    int count=0;
    while(pmove->m_pnext!=head)
    {
        pmove=pmove->m_pnext;
        count++;
    }
    return count;
}


### 4 顺序栈

// SeqStack.h
template <typename Type>
class SeqStack
{
    public:
        SeqStack(int sz):m_ntop(-1),m_nmaxsize(sz)
        {
            m_pelement=new Type[sz];
            if(m_pelement==null)
            {
                exit(1);
            } 
        }
        ~SeqStack()
        {
            delete[] m_pelement;
        }

    public:
        void Push(const Type item);
        Type Pop();
        Type GetTop() const;
        void Print();

        void MakeEmpty()
        {
            m_ntop=-1;
        } 
        bool IsEmpty()const
        {
            return m_ntop=-1;
        }
        bool IsFull()const
        {
            return m_ntop=m_nmaxsize-1;
        }

    private:
        int m_ntop;
        Type * m_pelement;
        int m_nmaxsize;
}

template <typename Type>
void SeqStack<Type>::Push(const Type item)
{
    if(IsFull)
    {
        cout<<"the stack is full";
        return;
    }
    m_pelement[++m_ntop]=item;
}

template <typename Type>
Type SeqStack<Type>::Pop()
{
    if(IsEmpty)
    {
        count<<"The stack id empty"<<endl;
        exit(1);
    }
    return m_pelement[m_ntop--];
}

template <typename Type>
Type SeqStack<Type>::GetTop()const
{
    if(IsEmpty)
    {
        count<<"The stack id empty"<<endl;
        exit(1);
    }
    return m_pelement[m_ntop];
}


### 5 链式栈
// StackNode.h

template <typename Type> 
class LinkStack;

template <typename Type>
class StackNode;
{
    private:
        friend class LinkStack<Type>;
        StackNode(Type dt,StackNode<Type>*next=null):m_data(dt),m_pnext(next){}

    private:
        Type m_data;
        StackNode<Type> *m_pnext;    
}

//LinkStack.h

# include "StackNode.h"

template <typename Type> 
class LinkStack
{
    public:
        LinkStack():m_ptop(null){}
        ~LinkStack()
        {
            MakeEmpty();
        }

    public:
        void MakeEmpty();
        void Push(const Type item);
        Type Pop();
        Type GetTop() const;
        void Print();
        bool IsEmpty()const
        {
            return m_ptop=null;
        }    

    private:
        StackNode<Type> *m_ntop;    
}

template <typename Type>
void LinkStack<Type>::MakeEmpty()
{
    StackNode<Type> *pmove;
    while(m_pmove!=null)
    {
        pmove=m_ptop;
        m_ptop=m_ptop->m_pnext;
        delete pmove;
    }
}

template <typename Type>
void LinkStack<Type>::Push(const Type item)
{
    m_ptop=new StackNode<Type>(item,m_ptop);
}

template <typename Type>
Type LinkStack<Type>::GetTop()const
{
    if(IsEmpty)
    {
        cout<<"the stack is empty"<<endl;
        exit(1);
    }

    return m_ptop->m_data;
} 

template <typename Type>
Type LinkStack<Type>::Pop()
{
     if(IsEmpty)
    {
        cout<<"the stack is empty"<<endl;
        exit(1);
    }

    StackNode<Type> *pdel=m_ptop;
    m_ptop=m_ptop->m_pnext;
    Type temp=pdel->m_pnext;
    delete pdel;
    return temp;
}


### 6.链式队列

// QueueNode.h

template <typename Type> class LinkQueue;
template <typename Type> class QueueNode
{
    private:
        friend class LinkQueue<Type>;
        QueueNode(const Type item,QueueNode<Type> *next=null):m_data(item),m_pnext(next){}

    private:
        Type m_data;
        QueueNode<Type> *m_pnext;    

}

//LinkQueue.h

template <typename Type> class LinkQueue
{
    public:
        LinkQueue():m_prear(null),m_pfront(null){}

        ~LinkQueue()
        {
            MakeEmpty();
        }

        void Append (const Type item);
        Type Delete();
        Type GetFront();
        void MakeEmpty();
        bool IsEmpty()const
        {
            return m_pfront=null;
        }

    private:
        QueueNode<Type> *m_prear,*m_pfront;    
}

template <typename Type> void LinkQueue<Type>::MakeEmpty()
{
    QueueNode<Type> *pdel;
    while(m_pfront)
    {
        pdel=m_pfront;
        m_pfront=m_pfront->m_pnext;
        delete pdel;
    }
}

template <typename Type> void LinkQueue<Type>::Append(const Type item)
{
    if(m_pfront==null)
    {
        m_pfront=m_prear=new QueueNode<Type>(item);
    }
    else
    {
        m_prear=m_prear->m_pnext=new QueueNode<Type>(item);
    }
}


template <typename Type> Type LinkQueue<Type>::Delete()
{
    if(IsEmpty())
    {
        cout<<"no element"<<endl;
        exit1() ;
    }

    QueueNode<Type> *pdel=m_pfront;

    Type temp=m_pfront->m_data;
    m_pfront=m_pfront->m_pnext;

    delete pdel;
    return temp;

}

templata <typename Type> Type LinkQueue<Type>::GetFront()
{
    if(IsEmpty())
    {
        cout<<"there is no element"<<endl;
        exit(1);
    }
    return m_pfront->m_data;
}


### 7.二叉树

//BinTreeNode.h

template <typename Type> class BinaryTree;
template <typename Type> class BinTreeNode
{
    public:
        friend class BinaryTree<Type>;
        BintTreeNode():m_pleft(null),m_pright(null){}
        BinTreeNode(Type item,BinTreeNode<Type> *left=null,BinTreeNode<Type> *right=null)
        :m_data(item),m_pleft(left),m_pright(right){}

        Type GetData() const;
        BinTreeNode<Type> *GetLeft() const;
        BinTreeNode<Type> *GetRight() const;

        void SetData(const Type data);
        void SetLeft(const BinTreeNode<Type> *left);
        void SetRight(const BinTreeNode<Type> *right);

        void InOrder();
        void PreOrder();
        void PostOrder();

        int Size();
        int Height();

        BinTreeNode<Type> *Copy(const BinTreeNode<Type>*copy);

        void Destroy()
        {
            if(thi!=null)
            {
                this->m_pleft->Destroy();
                this->m_pright->Destroy();
                delete this;
            }
        }

        friend bool equle<Type>(const BinTreeNode<Type> *s,const BinTreeNode<Type> *t);

        private:
            BinTreeNode<Type> *m_pleft,*m_pright;
            Type m_data;

}

template <typename Type> Type BinTreeNode<Type>::GetData()const
{
    return this!=null?m_data:null;
}

template <typename Type> BinTreeNode<Type>* BinTreeNode<Type>::GetLeft()const
{
    return this!=null?m_pleft:null;
}

template <typename Type> BinTreeNode<Type>* BinTreeNode<Type>::GetRight()const
{
    return this!=null?m_pright:null;
}


template <typename Type> void BinTreeNode<Type>::SetData(const Type data)
{
    if(this!=null)
    {
        m_data=data;
    }
}

template <typename Type> void BinTreeNode<Type>::SetLeft(const BinTreeNode<Type>*left)
{
    if(this!=null)
    {
        m_pleft=left;
    }
}

template <typename Type> void BinTreeNode<Type>::SetRight(const BinTreeNode<Type>*right)
{
    if(this!=null)
    {
        m_pright=right;
    }
}

template <typename Type> BinTreeNode<Type>* BinTreeNode<Type>::Copy(const BinTreeNode<Type> *copy)
{
    if(copy==null)
    {
        return null;
    }
    BinTreeNode<Type> *temp=new BinTreeNode<Type>(copy->m_data);
    temp->m_pleft=Copy(copy->m_pleft); 
    temp->m_pright=Copy(copy->m_pright); 
    return temp;
}

template <typename Type> void BinTreeNode<Type>::InOrder()
{
    if(this!=null)
    {
        this->m_pleft->InOrder();
        count<<"----"<<this.m_data<<endl;
        this.m_pright->InOrder();
    }
}

template <typename Type> void BinTreeNode<Type>::PreOrder()
{
    if(this!=null)
    {
        count<<"----"<<this.m_data<<endl;
        this->m_pleft->PreOrder();
        this.m_pright->PreOrder();
        
    }
}

template <typename Type> void BinTreeNode<Type>::PostOrder()
{
    if(this!=null)
    {
        this->m_pleft->PostOrder();
        this.m_pright->PostOrder();
        count<<"----"<<this.m_data<<endl;
        
    }
}

template <typename Type> int BinTreeNode<Type>::Size()
{
    if(this==null)
    {
        return 0;
    }
    return 1+this->m_pleft->Size()+this->m_pright->Size();
}

template <typename Type> int BinTreeNode<Type>::Height()
{
    if(this==null)
    {
        return -1;
    }
    int lheight,rheight;
    lheight=this->m_pleft->Height();
    rheight=this->m_pright->Height();
    return 1+(lheight>rheight?lheight:rheight);
}


### 8.堆(完全二叉树)
//MinHeap.h

template <typename Type> class MinHeap
{
    public:
        MinHeap(int size):m_nMaxsize(size>defaultsize?size:defaultsize),m_pheap(new Type[m_nMaxsize]),m_ncurrentsize(0){}
        MinHeap(Type heap[],int n);
        ~MinHeap()
        {
            delete []m_pheap;
        }

    public:
        bool Insert(const Type item);    
        bool Delete(const Type item);
        bool IsEmpty()const
        {
            return m_ncurrentsize==0;
        }    
        bool IsFull() const
        {
            return m_ncurrentsize==m_nMaxsize;
        }
        void Print(const int Start=0,int n=0);

    private:
        void Adjust(const int start,const int end);

        static const int defaultsize=100;
        const int m_nMaxsize;
        Type *m_pheap;
        int m_ncurrentsize;
}

template <typename Type>
void MinHeap<Type>::Adjust(const int start,const int end)
{
    int i=start;j=i*2+1;
    Type temp=m_pheap[i];
    while(j<=end)
    {
        if(j<end && m_pheap[j]>m_pheap[j+1])
        {
            j++;
        }
        if(temp<=m_pheap[j])
        {
            break;
        }
        else
        {
            m_pheap[i]=m_pheap[j];
            i=j;
            j=2*i+1;
        }
    }
    m_pheap[i]=temp;
}

template <typename Type>
MinHeap<Type>::MinHeap(Type heap[],int n):m_nMaxsize(n>defaultsize?n:defaultsize)
{
    m_pheap=new Type[m_nMaxsize];
    for(int i=0;i<n;i++)
    {
        m_pheap[i]=heap[i];
    }
    m_ncurrentsize=n;
    int pos=(n-2)/2;
    while(pos>=0)
    {
        Adjust(pos,n-1);
        pos--;
    }
} 

template <typename Type>
bool MinHeap<Type>::Insert(const Type item)
{
    if(m_ncurrentsize==m_nMaxsize)
    {
        cout<<"heap full"<<endl;
        return 0;
    }
    m_pheap[m_ncurrentsize]=item;
    int j=m_ncurrentsize,i=(j-1)/2;
    Type temp=m_pheap[j];
    while(j>0)
    {
        if(m_pheap[i]<=temp)
        {
            break;
        }
        else
        {
            m_pheap[j]=m_pheap[i];
            j=i;
            i=(j-1)/2;
        }
    }

    m_pheap[j]=temp;
    m_ncurrentsize++;
    return 1;
}

template <typename Type>
bool MinHeap<Type>::Delete(const Type item)
{
    if(0==m_ncurrentsize)
    {
        cout<<"heap empty"<<endl;
        return 0;
    }
    for(int i=0;i<m_ncurrentsize;i++)
    {
        if(m_pheap[i]==item)
        {
            m_pheap[i]=m_pheap[m_ncurrentsize-1];
            Adjust(i,m_ncurrentsize-2);
            m_ncurrentsize--;
            i=0;
        }

    }
    return 1;
}




