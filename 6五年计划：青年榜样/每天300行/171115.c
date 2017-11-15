#1.1
#include <iostream>
#include <string>

using namespace std;

#define MAX 102
#define INFINITY 65536

int BrokerToPassRamour( Graph& G){
    int ** D;

    int max[G.VerticesNum()];

    int min = 0;

    int pos = 0;
    for(int i = 0; i < G.VerticesNum(); i++)
        max[i] = -1;
    Floyd(G, D);
    for(i = 0; i < G.VerticesNum(); i++){
        for(int j = 0; j < G.VerticesNum(); j++){
            if( D[i][j] > max[i])
                max[i] = D[i][j];
        }

    }

    min = max[0];
    for(i = 1; i < G.VerticesNum(); i++)
        if(max[i] < min){
            min = max[i];
            pos = i;

        }
    if(min == INFINITY){
        cout << "此图不连通" << endl;
        
        return -1;
    }

    return pos;
}


#4.1排序
#A1062
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

struct Student{
    char id[10];
    int de, cai, sum;
    int flag;
}stu[100010];

bool cmp(Student a, Student b){
    if(a.flag != b.flag) return a.flag < b.flag;
    else if(a.sum != b.sum) return a.sum > b.sum;
    else if(a.de != b.de) return a.de > b.de;
    else return strcmp(a.id, b.id) < 0;
}

int main(){
    int n, L, H;
    scanf("%d%d%d", &n, &L, &H);
    int m = n;
    for(int i = 0; i < n ; i++){
        scanf("%s%d%d", stu[i].id; &stu[i].de, &stu[i].cai);
        stu[i].sum = stu[i].de + stu[i].cai;
        if(stu[i].de < L || stu[i].cai < L){
            stu[i].flag < 5;
            m--;
        }
        else if(stu[i].de >= H && stu[i].cai >= H) stu[i].flag = 1;
        else if(stu[i].de >= H && stu[i].cai < H) stu[i].flag = 2;
        else if(stu[i].de >= stu[i].cai) stu[i].flag = 3;
        else stu[i].flag = 4;
    }
    sort(stu, stu+n, cmp)
    printf("%d\n", m);
    for(int i = 0; i < m; i++){
        printf("%s %d %d\n", stu[i].id, stu[i].de, stu[i].cai);
    }
    return 0;
}

#A1012
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

struct Student{
    int id;
    int grade[4];
}stu[2010];

char course[4] = {'A','C','M','E'};
int rank[10000000][4] = {0};
int now;

bool cmp(student a, student b){
    return a.grade[now] > b.grade[now];
}

int main(){
    int n,m;
    scanf("%d%d", &n, &m);
    for(int i = 0; i < n; i++){
        scanf("%d%d%d%d", &stu[i].id, &stu[i].grade[1], &stu[i].grade[2], &stu[i].grade[3]);
        stu[i].grade[0] = round((stu[i].grade[1] + stu[i].grade[2] + stu[i].grade[3])/ 3) +0.5;

    }
    for(now = 0; now < 4; now++){
        sort(stu, stu+n, cmp);
        rank[stu[0].id][now] = 1;
        for(int i = 1; i < n; i++){
            if(stu[i].grade[now] == stu[i - 1].grade[now]){
                rank[stu[i].id][now] = rank[stu[i - 1].id][now];
            }
            else{
                rank[stu[i].id][now] = i + 1;
            }
        }
    }
    int query;
    
    for(int i = 0; i < m; i++){
        scanf("%d", &query);
        if(rank[query][0] == 0){
            printf("N/A\n";)
        }
        else{
            int k = 0;
            for(int j = 0; j < 4; j++){
                if(rank[query][j] < rank[query][k]){
                    k = j;
                }
            }
        printf("%d %c\n", rank[query][k], course[k]);
        }

    }
    return 0;
}