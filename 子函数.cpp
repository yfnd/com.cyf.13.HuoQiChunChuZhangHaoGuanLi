
void OUTPUT() 
{ 
system("color E"); 
int s; 
printf("\t ^_^��ѧ�ƻ����Ʋ˵� ^_^ \n"); 
printf("\t *************************************************** \n"); 
printf("\t �� �γ̴��� | �γ����� | ���޿γ� �� \n"); 
printf("\t *************************************************** \n"); 
printf("\t * 1 |C1 | �� * \n"); 
printf("\t * 2 |C2 | 1 * \n"); 
printf("\t * 3 |C3 | 1, 2 * \n"); 
printf("\t * 4 |C4 | 1 * \n"); 
printf("\t * 5 |C5 | 3, 4 * \n"); 
printf("\t * 6 |C6 | 11 * \n"); 
printf("\t * 7 |C7 | 5, 3 * \n"); 
printf("\t * 8 |C8 | 3, 6 * \n"); 
printf("\t * 9 |C9 | �� * \n"); 
printf("\t * 10 |C10 | 9 * \n"); 
printf("\t * 11 |C11 | 9 * \n"); 
printf("\t * 12 |C12 | 9,10,1 * \n"); 
printf("\t *************************************************** \n"); 
printf("\n"); 
printf("< �� Enter����>:"); 
scanf("%c",&s); //scanf("��ʽ���Ʒ� ",& ��ַ���� )��ʽ���뺯���������û�
ָ���ĸ�ʽ�Ӽ����ϰ��������뵽ָ���ı���֮��
} 
/* ����ͼ��ĳ������λ�� */ 
int LocateVex(ALGraph G,VertexType u) 
{ 
int i; 
for(i=0;i<G .vexnum;++i) 
if(strcmp(u,G.vertices[i].data)==0) 
return i; 
return -1; 
} 
/* �����ڽӱ�洢�ṹ */ 
int CreateGraph(ALGraph &G) 
{ 
int i,j,k; 
VertexType va; 
ArcNode *p; 
�� 24 ҳ �� 29 ҳ
printf(" �������ѧ�ƻ��Ŀγ��� :"); 
scanf("%d",&G.vexnum); 
printf(" ��������ſγ̵����޿γ̵��ܺ� (������ ):"); 
scanf("%d",&G.arcnum); 
printf(" ������ %d �ſγ̵Ŀγ̴��� (���%d ���ַ� ,����):",G.vexnum,MAX_NAME); 
for(i=0;i<G .vexnum;++i) //����ͷ���
{ 
scanf("%s",&G.vertices[i].data); 
G.vertices[i].firstarc=NULL; 
} 
for(i=0;i<G .vexnum;i++) 
{ 
printf(" ������� %d �ſγ̵�ѧ��ֵ :",i+1); 
scanf("%d",&G.vertices[i].grades); 
while(G.vertices[i].grades>MaxScores||G.vertices[i].grades<=0) 
{ 
printf(" ����!ѧ�ֱ������� 0 ��������� %d ֮��,����������� !\n",MaxScores); 
//��������ѧ�ִ������޻���� 0������־���
printf(" ������� %d �ſγ̵�ѧ��ֵ :",i+1); 
scanf("%d",&G.vertices[i].grades); 
} 
} 
printf(" ���������пγ̵����޿γ� (�����޿γ����� 0,����Ҳ���� 0)\n"); 
for(k=0;k<G.vexnum;++k) //����������� ,����ǰ�巨
{ 
printf("%s �����޿γ� :",G.vertices[k].data); /// 
scanf("%s",va); // 
while(va[0]!='0') //ikva 
{ 
i=LocateVex(G,va); //��β
j=k; //��ͷ
p=(ArcNode*)malloc(sizeof(ArcNode)); 
p->adjvex=j; 
p->nextarc=G.vertices[i].firstarc; //���ڱ�ͷ
G.vertices[i].firstarc=p; 
scanf("%s",va); 
} 
} 
system("cls"); 
return OK; 
} 
/* ���ͼ G ����Ϣ */ 
void Display(ALGraph G) 
�� 25 ҳ �� 29 ҳ
{ 
system("color B"); 
int i; 
ArcNode *p; 
printf(" ������ͼ�� \n"); 
printf("%d ������ :",G.vexnum); 
for(i=0;i<G .vexnum;++i) 
printf("%4s",G.vertices[i].data); 
printf("\n%d ������ :\n",G.arcnum); 
for(i=0;i<G .vexnum;i++) 
{ 
p=G.vertices[i].firstarc; 
while(p) 
{ 
printf("%s--->%s\n",G.vertices[i].data,G.vertices[p->adjvex].data); 
p=p->nextarc; 
} 
} 
} 
/* �󶥵����� */ 
void FindInDegree(ALGraph G,int indegree[]) 
{ 
int i; 
ArcNode *p; 
for(i=0;i<G .vexnum;i++) 
indegree[i]=0; 
for(i=0;i<G .vexnum;i++) 
{ 
p=G.vertices[i].firstarc; 
while(p) 
{ 
indegree[p->adjvex]++; 
p=p->nextarc; 
} 
} 
} 
struct Name 
{ 
char c[20]; 
}name;


