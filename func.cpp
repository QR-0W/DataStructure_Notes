#include <iostream>
using namespace std;
#define ElemType int
int main(int argc, char **argv)
{
    return 0;
}

bool ListInsert(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.Length + 1)
        return false;
    if (L.Length >= MaxSize)
        return false;
    for (int j = L.Length > j >= i; j--)
        L.data[j] = L.data[j - 1];
    L.data[i - 1] = e;
    L.Length++;
    return true;
}

bool ListDelete(SqList &L, int i, ElemType e)
{
    if (i < 1 || i > L.Length) // 判断范围是否有效
        return false;
    e = L.data[i - 1];                 // 把被删除的元素给e
    for (int j = i; j < L.Length; j++) // 元素前移
        L.data[j - 1] = L.data[j];
    L.Length--; // 长度-1
    return true;
}

int LocateElem(SqList L, ElemType e)
{
    int i;
    for (i = 0; i < L.Length; i++)
        if (L.data[i] == e)
            return i + 1; // 下表为i的元素等于e，返回位序i+1
    return 0;             // 查找失败
}

typedef struct LNode                    // 定义节点类型
{
    ElemType data;                      // 数据域
    struct LNode *next;                 // 指针域
} LNode, *LinkList;

LinkList List_HeadInsert(LinkList &L)   //头插法建立单链表
{
    LNode *s;
    int x;

    L = (LNode *)malloc(sizeof(LNode)); //创建头节点
    L->next = NULL;                     //初始为空

    scanf("%d", &x);
    while (x != -1)                     //这里用-1代表结束
    {
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        s->next = L->next;
        L->next = s;                    //新结点插入到表中
        scanf("%d", &x);
    }
    return L;
}

LinkList List_TailInsert(LinkList &L)   //头插法建立单链表
{
    int x;
    L = (LNode *)malloc(sizeof(LNode));
    LNode *s, *r = L;                   //r为表尾指针
    scanf("%d", &x);
    while (x != -1)
    {
        s = (LNode *)malloc(sizeof(LNode));
        s ->data = x;
        r -> next = s;
        r = s;                          //r指向新的表尾结点
        scanf("%d", &x);
    }
    r -> next = NULL;                   //尾指针置空
    return L;
}

LNode *GetElem(LinkList L, int i)
{
    int j = 1;                          //计数，初始为1
    LNode *p = L->next;
    if (i < 0)                          //若i无效，则返回NULL
        return NULL;
    if (i == 0)                         //如果i为0则返回头节点
        return L;
    while (p && j < i)                  //从第1个结点开始找
    {
        p = p->next;
        j++;
    }
    return p;                           //若i大于表长则返回NULL
}

LNode *LocateElem(LinkList L, ElemType e)
{
    LNode *p = L->next;
    while (p != NULL && p->data != e)   //从第1个结点开始查找
        p = p->next;
    return p;                           //找到后返回，否则返回NULL
}

typedef struct DNode                    //双链表
{   
    ElemType data;                      //数据域
    struct DNode *prior, *next;         //前驱后继
} DNode, *DLinkList;

#define MaxSize 50                      //静态链表的最大长度
typedef struct{
    ElemType data;  
    int next;                           //下一个元素的数组下标
}SLinkList[MaxSize];

#define MaxSize 50
typedef struct
{
    ElemType data[MaxSize];             //存放数据元素
    int top;                            //栈顶指针
}SqStack;

void InitStack(SqStack &S)
{
    S.top = -1;                         //初始化栈顶指针
}

bool StackEmpty(SqStack S)
{
    if (S.top == -1)                    //栈空
        return true;        
    else                                //非空
        return false;
}

bool Push(SqStack &S, ElemType e)
{
    if(S.top == MaxSize -1)             //栈满
        return false;
    S.data[++S.top] = e;                //指针先+1再入栈
    return true;
}

bool Pop(SqStack &S, ElemType &e)
{
    if(S.top == -1)                     //栈空
        return false;
    e = S.data[S.top--];                //先出栈指针再-1
    return true;
}

bool GetTop(SqStack S, ElemType &x)
{
    if(S.top == -1)                     //栈空
        return false;
    x = S.data[S.top];                  //x记录栈顶元素
    return true;
}

typedef struct Linknode
{
    ElemType data;                      //数据域
    struct Linknode *next;              //指针域
} *LiStack;

#define MaxSize 50
typedef struct
{
    ElemType data[MaxSize];             //存放队列元素
    int front, rear;                    //队头、队尾指针
} SqQueue;

void InitQueue(SqQueue &Q)
{
    Q.rear = Q.front = 0;               //初始化队首、队尾
}

bool isEmpty(SqQueue Q)
{
    if(Q.rear == Q.front)               //队空
        return true;
    else
        return false;
}

bool EnQueue(SqQueue &Q, ElemType e)
{
    if((Q.rear + 1) % MaxSize == Q.front)
        return false;                   //队满
    Q.data[Q.rear] = e;
    Q.rear = (Q.rear + 1) % MaxSize;    //队尾+1取模
    return true;
}

bool DeQueue(SqQueue &Q, ElemType &e)
{
    if(Q.rear == Q.front)
        return false;                   //队空
    e = Q.data[Q.front];
    Q.front = (Q.front + 1) % MaxSize;  //队头+1取模
    return true;
}

typedef struct LinkNode
{
    ElemType data;
    struct LinkNode *Next;
} LinkNode;

typedef struct
{
    LinkNode *front, *rear;
} LinkQueue;

void InitQueue(LinkQueue &Q)
{
    Q.front = Q.rear = (LinkNode *)malloc(sizeof(LinkNode));
    Q.front->Next = NULL;               //初始为空
}

bool isEmpty(LinkQueue Q)
{
    if(Q.front == Q.rear)
        return true;
    return false;
}

void EnQueue(LinkQueue &Q, ElemType e)
{
    LinkNode *s = (LinkNode *)malloc(sizeof(LinkNode));
    s->data = e;
    
    s->Next = NULL;                     //尾插法
    Q.rear->Next = s;
    Q.rear = s;
}

bool DeQueue(LinkQueue &Q, ElemType &e)
{
    if(Q.front == Q.rear)
        return false;
    LinkNode *p = Q.front->Next;

    e = p->data;
    Q.front->Next = p->Next;

    if(Q.rear == p)                     //若队列中只有一个结点，还需要调整rear
        Q.rear = Q.front;
    
    free(p);
    return true;
}

void infixToPostFix(char infix[], char s2[], int &top2) //s2为结果栈
{
    char s1[MaxSize];
    int top1 = -1;
    int i = 0;
    while (infix[i]!='\0')
    {
        // 若为数字则直接入队
        if('0'<=infix[i] && infix[i]<='9')              
        {
            s2[top2++] = infix[i];                      //入队之后到下一位 
            ++i;
        }
        // 若为左括号则直接入栈
        else if (infix[i] == '(')                       
        {
            s1[++top1] = '(';
            ++i;
        }
        // 若为运算符则进行判断
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            if(top1 ==-1 || s1[top1] == '(' || getPriority(infix[i]) > getPriority(s1[top1]))
            //栈空/左括号/当前运算符大于栈顶预算夫优先级则入栈
            {
                s1[++top1] = infix[i];
                ++i;
            }
            else
                s2[++top2] = s1[top1--];                //否则出栈
        }
        // 若为右括号
        else if (infix[i] == ')')                      
        {
            while (s1[top1]!='(')
                s2[++top2] = s1[top1--];                //不停出栈
            --top1;                                     //左括号出栈
            ++i;                                        //跳过右括号
        }
    }
    // 将剩余的符号全部放入结果中
    while (top1 != -1)                                  
    {
        s2[++top2] = s1[top1--];
    }
}

void infixToPreFix(char infix[], int len, char s2[], int &top2) // s2为结果栈
{
    char s1[MaxSize];
    int top1 = -1;
    int i = len - 1;
    while (i >= 0)
    {
        // 若为数字则直接入队
        if ('0' <= infix[i] && infix[i] <= '9')
        {
            s2[top2++] = infix[i]; // 入队之后到下一位
            --i;
        }
        // 若为右括号则直接入栈
        else if (infix[i] == ')')
        {
            s1[++top1] = ')';
            --i;
        }
        // 若为运算符则进行判断
        else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
        {
            if (top1 == -1 || s1[top1] == ')' || getPriority(infix[i]) >= getPriority(s1[top1]))
            // 栈空/右括号/当前运算符大于等于栈顶预算夫优先级则入栈
            {
                s1[++top1] = infix[i];
                --i;
            }
            else
                s2[++top2] = s1[top1--]; // 否则出栈
        }
        // 若为左括号
        else if (infix[i] == '(')
        {
            while (s1[top1] != ')')
                s2[++top2] = s1[top1--]; // 不停出栈
            --top1;                      // 右括号出栈
            --i;                         // 跳过左括号
        }
    }
    // 将剩余的符号全部放入结果中
    while (top1 != -1)
    {
        s2[++top2] = s1[top1--];
    }
}

int getPriority(char op)
{
    if (op == '+' || op =='-')
        return 0;
    else
        return 1;
}

int calSub(float opand1, char op, float opand2, float &result)
{
    if (op == '+')
        result = opand1 + opand2;
    if (op == '-')
        result = opand1 - opand2;
    if (op == '*')
        result = opand1 * opand2;
    if (op == '/')
    {
        if (fabs(opand2) < MIN)
            return 0;
        else
            result = opand1 / opand2;
    }
    return 1;
}

float calInfix(char exp[])
{
    float s1[MaxSize];
    char s2[MaxSize];
    int top1 = -1, top2 = -1;
    int i = 0;
    while (exp[i] != '\0')
    {
        //数字直接入栈
        if ('0' <= exp[i] && exp[i] <= '9')
        {
            s1[++top1] = exp[i] - '0';
            ++i;
        }
        //左括号入运算符栈
        else if (exp[i] == '(')
        {
            s2[++top2] = '(';
            ++i;
        }
        //运算符要判断
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            //栈空、栈顶为左括号、当前优先级高直接入栈
            if (top2 == -1 || s2[top2] == '(' || getPriority(exp[i] > getPriority(s2[top2])))
            {
                s2[++top2] = exp[i];
                ++i;
            }
            else
            {
                float opnd1, opnd2, result;
                char op;
                int flag;
                opnd2 = s1[top1--]; // 第二个操作数先出栈
                opnd1 = s1[top1--]; // 第一个操作数后出栈
                op = s2[top2--]; 
                flag = calSub(opnd1, op, opnd2, result);
                if (flag == 0)
                {
                    cout << "ERROR" << endl;
                    break;
                }
                s1[++top1] = result; // 将结果压入栈中
            }
        }
        //右括号
        else if (exp[i] == ')')
        {
            while(s2[top2] != '(')
            {
                float opnd1, opnd2, result;
                char op;
                int flag;
                opnd2 = s1[top1--]; // 第二个操作数先出栈
                opnd1 = s1[top1--]; // 第一个操作数后出栈
                op = s2[top2--];
                flag = calSub(opnd1, op, opnd2, result);
                if (flag == 0)
                {
                    cout << "ERROR" << endl;
                    break;
                }
                s1[++top1] = result; // 将结果压入栈中
            }
            --top2;                  // 左括号出栈
            ++i;                     // 跳过右 括号
        }
    }
    //如果栈中还有元素，则进行运算 
    while (top2 != -1)
    {
        float opnd1, opnd2, result;
        char op;
        int flag;
        opnd2 = s1[top1--]; // 第二个操作数先出栈
        opnd1 = s1[top1--]; // 第一个操作数后出栈
        op = s2[top2--];
        flag = calSub(opnd1, op, opnd2, result);
        if (flag == 0)
        {
            cout << "ERROR" << endl;
            break;
        }
        s1[++top1] = result; // 将结果压入栈中
    }
    return s1[top1];
}

float calPostFix(char exp[])
{
    float s[MaxSize];
    int top = -1;
    int i = 0;
    while (exp[i] != '\0')
    {
        // 若为数字则直接入队
        if ('0' <= exp[i] && exp[i] <= '9')
            s[++top] = exp[i] -  '0';
        // 若为运算符则直接计算
        else if (exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            float opnd1, opnd2, result;
            char op;
            int flag;
            opnd2 = s[top--];           //第二个操作数先出栈
            opnd1 = s[top--];           //第一个操作数后出栈 
            op = exp[i];
            flag = calSub(opnd1, op, opnd2, result);
            if(flag == 0)
            {
                cout << "ERROR" << endl;
                break;
            }
            s[++top] = result;          //将结果压入栈中
        }
        ++i;
    }
    return s[top];
}

float calPreFix(char exp[], int len)
{
    float s[MaxSize];
    int top = -1;
    for (int i = len - 1; i >= 0; --i)
    {
        if('0' <= exp[i] && exp[i] <= '9')
            s[++top] = exp[i] - '0';
        else
        {
            float opnd1, opnd2, result;
            char op;
            int flag;
            opnd1 = s[top--]; // 第一个操作数先出栈
            opnd2 = s[top--]; // 第二个操作数后出栈
            op = exp[i];
            flag = calSub(opnd1, op, opnd2, result);
            if (flag == 0)
            {
                cout << "ERROR" << endl;
                break;
            }
            s[++top] = result; // 将结果压入栈中
        }
    }
    return s[top];
}

typedef struct BiTNode
{
    ElemType data;
    struct BiTNode *lChild, *rChild;
} BiTNode, *BiTree;

void PreOrder(BiTree T)
{
    if (T!=NULL)
    {
        visit(T);
        PreOrder(T->lChild);
        PreOrder(T->rChild);
    }
}

void InOrder(BiTree T)
{
    if(T!=NULL)
    {
        InOrder(T->lChild);
        visit(T);
        InOrder(T->rChild);
    }
}

void PostOrder(BiTree T)
{
    if(T!=NULL)
    {
        PostOrder(T->lChild);
        PostOrder(T->rChild);
        visit(T);
    }
}

typedef struct ThreadNode
{
    ElemType data;
    struct ThreadNode* lChild, *rChild;
    int lTag, rTag;
}ThreadNode, *ThreadTree;

void InThread(ThreadTree &p, ThreadTree &pre)
{
    if (p != NULL)
    {
        InThread(p->lChild, pre);   //递归，线索化左子树
        if (p->lChild == NULL)      //左子树为空，建立前驱线索
        {
            p->lChild = pre;
            p->lTag = 1;
        }
        if (pre != NULL && pre->rChild == NULL)
        {
            pre->rChild = p;        //建立前驱结点的后继线索
            pre->rTag = 1;
        }
        pre = p;                    //标记当前节点成为刚刚访问过的结点
        InThread(p->rChild, pre);   //递归，线索化右子树
    }
}

void CreateInThread(ThreadTree T)
{
    ThreadTree pre = NULL;
    if (T != NULL)
    {
        InThread(T, pre);       //对非空二叉树线索化
        pre->rChild = NULL;
        pre->rTag = 1;          //处理最后一个结点
    }
}


ThreadNode *Firstnode(ThreadNode *p)    //求第一个结点
{
    while (p->lTag == 0)
    {
        p = p->lChild;
    }
    return p;
}               

ThreadNode *Nextnode(ThreadNode *p)     //求后继
{
    if (p->rTag == 0)
    {
        return Firstnode(p->rChild);
    }
    else
    {
        return p->rChild;
    }
}

void Inorder(ThreadNode *T)
{
    for (ThreadNode *p = Firstnode(T);p!=NULL;p = Nextnode(p))
        visit(p);
}

#define MAX_TREE_SIZE 100
typedef struct
{
    ElemType data;
    int parent;
} PTNode;

typedef struct
{
    PTNode node[MAX_TREE_SIZE];
    int n;
} PTree;

typedef struct CSNode
{
    ElemType data;
    struct CSNode *firstChild, *nextSibling;
} CSNode, *CSTree;

#define SIZE 100
int UFSets[SIZE];

void Initial(int S[])
{
    for (int i = 0; i < SIZE; i++)
        S[i] = -1;
}

int Find(int S[], int x)
{
    while (S[x] >= 0)
    {
        x = S[x];
    }
    return x;
}

void Union(int S[], int Root1, int Root2)
{
    S[Root2] = Root1;
}

#define MaxVertexNum 100
typedef char VertexType;
typedef int EdgeType;

typedef struct
{
    VertexType Vex[MaxVertexNum];               //顶点表
    EdgeType Edge[MaxVertexNum][MaxVertexNum];  //邻接矩阵表
    int vexNum, arcNum;
} MGraph;

#define MaxVertexNum 100

typedef struct ArcNode                          //边表结点
{
    int adjvex;                                 //弧指向的顶点位置
    struct ArcNode *next;                       //指向下一条弧的指针
} ArcNode;

typedef struct VNode                            //顶点表结点
{
    VertexType data;                            //顶点信息
    ArcNode *first;                             //指向第一条依附于该顶点的弧的指针
} VNode, AdjList[MaxVertexNum];

typedef struct
{
    AdjList vertices;                           //邻接表
    int vexnum, arcnum;                         //图的顶点数和弧数
} ALGraph;

bool visited[MAX_VERTEX_NUM];                   //访问标记数组

void BESTraverse(Graph G)                       //对图进行广度优先遍历
{
    for (i = 0; i < G.vexnum; ++i)
    {
        visited[i] = FALSE;                     //访问标记数组初始化
    }
    InitQueue(Q);                               //初始化辅助队列
    for (i = 0; i < G.vexnum; ++i)              //从 0 号顶点开始遍历
    {
        if (!visited[i])                        //对每个连通分量 BFS
        {
            BFS(G, i);
        }
    }
}

void BFS(Graph G, int v)                        //从顶点 v 开始，广度优先遍历图 G
{                                   
    visit(v);                                   //访问初始顶点 v
    visited[v] = TRUE;                          //标记已访问
    Enqueue(Q, v);                              //顶点 v 入队 Q
    while (!isEmpty(Q))
    {
        DeQueue(Q, v);                          //顶点 v 出队
        for (w = FirstNeighbour(G, v); w >= 0; w = NextNeighbour(G, v, W))
                                                //检测 v 所有邻接点
        {
            if (!visited[w])                    //w 为 v 的尚未访问的邻接顶点
            {
                visit(w);                       //访问 w
                visited[w] = TRUE;
                EnQueue(Q, w);
            }
        }
    }
}

void BFS_Min_Distance(Grapg G, int u)
{
    for (i = 0; i < G.vexnum; ++i)
    {
        d[i] = INFINITY;            //d[i] 表示从 u 到 i 的最短路径，此处先初始化
    }
    visited[u] = TRUE;
    d[u] = 0;
    EnQueue(Q, u);
    while (!isEmpty(Q))             //BFS 算法主过程
    {
        DeQueue(Q, u);              //队头 u 出队
        for (w = FirstNeighbour(G, u); w >= 0; w = NextNeighbour(G, u, w))
        {
            if (!visited[w])        //w 为u 尚未访问的邻接顶点
            {
                visited[w] = TRUE;  //标记为已访问
                d[w] = d[u] + 1;    //路径长度 + 1
            }
        }
    }
}

bool visited[MAX_VERYEX_NUM];

void DFSTraverse(Graph G)
{
    for (v = 0; v < G.vexnum; ++v)
    {
        visited[v] = FALSE;         //初始化
    }
    for (v = 0; v < G.vexnum; ++v)  //本代码从 v=0 开始遍历
    {
        if (!visited[v])
        {
            DFS(G, v);
        }
    }
}

void DFS(Graph G, int v)
{
    visit(v);
    visited[v] = TRUE;
    for (w = FirstNeighbour(G, v); w >= 0; w = NextNeighbour(G, v, w))                        
    {
        if (!visited[w])            // w 为 v 的未访问邻接顶点
        {
            DFS(G, w);
        }
    }
}