#include <stdio.h>
#include <stdlib.h>
typedef struct {
    char hoten[30];
    int masv;
    float d1, d2, d3;
} Data;
typedef struct tagNode {
    Data infor;
    struct tagNode *link;
} Node;
typedef struct {
    Node *pHead;
    Node *pTail;
    int spt;
} LList;
void initList(LList *L)
{
    L->pHead = NULL;
    L->pTail = NULL;
    L->spt = 0;
}
int emptyList(LList L)
{
    return (L.spt == 0);
}
void insert_Head(LList *L, Data x)
{
    Node *pp;
    pp = (Node*)malloc(sizeof(Node));
    if(pp == NULL) 
	return;
    pp->infor = x;
    pp->link = L->pHead;

    if(emptyList(*L)) {
        L->pTail = pp;
    }
    L->pHead = pp;
    L->spt++;
}
void insert_Tail(LList *L, Data x)
{
    Node *pp;
    pp = (Node*)malloc(sizeof(Node));
    if(pp == NULL)
	return;
    pp->infor = x;
    pp->link = NULL;
    if(emptyList(*L)) {
        L->pHead = pp;
        L->pTail = pp;
    }
    else {
        L->pTail->link = pp;
        L->pTail = pp;
    }

    L->spt++;
}
void delete_Head(LList *L)
{
    Node *pp;
    if(emptyList(*L)) {
        printf("Danh sach rong!\n");
        return;
    }
    pp = L->pHead;
    L->pHead = L->pHead->link;
    free(pp);
    L->spt--;
    if(L->pHead == NULL) {
        L->pTail = NULL;
    }
}
void delete_Tail(LList *L)
{
    Node *pp;
    if(emptyList(*L)) {
        printf("Danh sach rong!\n");
        return;
    }
    pp = L->pHead;
    if(L->pHead == L->pTail) {
        L->pHead = NULL;
        L->pTail = NULL;
    }
    else {
        while(pp->link != L->pTail) {
            pp = pp->link;
        }
        free(L->pTail);
        L->pTail = pp;
        L->pTail->link = NULL;
    }
    L->spt--;
}
void nhap(Data *x)
{
    printf("Nhap ma sv: ");
    scanf("%d", &(x->masv));

    if(x->masv > 0) {
        printf("Nhap ho ten: ");
        scanf(" %29[^\n]", x->hoten);
        printf("Nhap diem mon 1: ");
        scanf("%f", &(x->d1));
        printf("Nhap diem mon 2: ");
        scanf("%f", &(x->d2));
        printf("Nhap diem mon 3: ");
        scanf("%f", &(x->d3));
    }
}
void in(Data x)
{
    printf("Ten: %s, Ma: %d, Diem 1: %.2f, Diem 2: %.2f, Diem 3: %.2f\n",
           x.hoten, x.masv, x.d1, x.d2, x.d3);
}
Node* search(LList L, int ma)
{
    Node *pp = L.pHead;
    while(pp != NULL) {
        if(pp->infor.masv == ma) {
            return pp;
        }
        pp = pp->link;
    }
    return NULL;
}
void processList(LList L)
{
    Node *pp = L.pHead;
    if(emptyList(L)) {
        printf("Danh sach rong!\n");
        return;
    }
    while(pp != NULL) {
        in(pp->infor);
        pp = pp->link;
    }
}
void freeList(LList *L)
{
    Node *pp;
    while(L->pHead != NULL) {
        pp = L->pHead;
        L->pHead = L->pHead->link;
        free(pp);
    }
    L->pTail = NULL;
    L->spt = 0;
}
int main()
{
    LList L;
    Data x;
    int kt = 0, chon, ma;
    Node *pp;
    initList(&L);
    do {
        printf("\nQuan Ly Danh Sach Sinh Vien\n");
        printf("1: Them vao dau danh sach\n");
        printf("2: Them vao cuoi danh sach\n");
        printf("3: Xoa dau danh sach\n");
        printf("4: Xoa cuoi danh sach\n");
        printf("5: Tim kiem sinh vien\n");
        printf("9: Duyet danh sach\n");
        printf("0: Thoat\n");
        printf("Moi ban chon: ");
        scanf("%d", &chon);
        switch(chon) {
            case 1:
                nhap(&x);
                if(x.masv > 0)
                    insert_Head(&L, x);
                break;
            case 2:
                nhap(&x);
                if(x.masv > 0)
                    insert_Tail(&L, x);
                break;
            case 3:
                delete_Head(&L);
                break;
            case 4:
                delete_Tail(&L);
                break;
            case 5:
                printf("Nhap ma sinh vien can tim: ");
                scanf("%d", &ma);
                pp = search(L, ma);
                if(pp != NULL)
                    in(pp->infor);
                else
                    printf("Khong tim thay sinh vien!\n");
                break;
            case 9:
                processList(L);
                break;
            case 0:
                printf("Bye bye!\n");
                kt = 1;
                break;
            default:
                printf("Lua chon khong hop le!\n");
        }
    } while(kt == 0);
    freeList(&L);
    return 0;
}
