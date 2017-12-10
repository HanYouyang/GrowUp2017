#A1016

bool cmp(Record a, Record b){
    int s = strcmp(a.name, b.name);
    if(s != 0) return s < 0;
    else if (a.month < b.month) return a.month < b.month;
    else if (a.dd != b.dd) return a.dd < b.dd;
    else if (a.hh != b.hh) return a.hh < b.hh;
    else return a.mm < b.mm;
}

while (start.day < end.day || start.hour < end.hour || start.minute < end.minute){
    start.minute++;
    if(start.minute == 60){
        start.minute = 0;
        start.hour++;

    }
    if(start.hour == 24){
        start.hour = 0;
        start.day++;

    }

}

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int maxn = 1010;
int toll[25];
struct Record{
    char name[25];
    int month, dd, hh, mm;
    bool status;
} rec[maxn], temp;

bool cmp(Record a, Record b){
    int s = strcmp(a.name, b.name);
    if(s!= 0) return s < 0;
    else if(a.month < b.month) return a.month < b.month;
    else if(a.dd != b.dd) return a.dd < b.dd;
    else if(a.hh != b.hh) return a.hh < b.hh;
    else return a.mm < b.mm
}

void get_ans(int on, int off, int& time, int& money){
    temp = rec[on];
    while(temp.dd < rec[off].dd || temp.hh < rec[off].hh || temp.mm <rec[off].mm){
        time++;
        money += toll[temp.hh];
        temp.mm++;
        if(temp.mm >= 60){
            temp.mm = 0;
            temp.hh++;
        }
        if(temp.hh >= 24){
            temp.hh = 0;
            temp.dd++;
        }
    }

}

int main(){
    for(int i = 0; i < 24; i++){
        scanf("%d", &toll[i]);
    }
    int n;
    scanf("%d", &n);
    char line[10];
    for(int i = 0; i < n; i++){
        scanf("%s", rec[i].name);
        scanf("%d:%d:%d:%d", &rec[i].month, &rec[i].dd, &rec[i].hh, &rec[i].mm);
        scanf("%s", line);
        if(strcmp(line, "on-line") == 0){
            rec[i].status = true;
        }
        else{
            rec[i].status = false;
        }
    }
    sort(rec, rec+n, cmp);
    int on = 0, off, next;
    while(on < n){
        int needPrint = 0;
        next = on;
        while(next < n && strcmp(rec[next].name, rec[on].name) == 0){
            if(needPrint == 0 && rec[next].status == true){
                needPrint = 1;
            }
            else if(needPrint == 1 && rec[next].status = false){
                needPrint = 2;
            }
            next++;
        }
        if(needPrint < 2){
            on = next;
            continue;
        }
        int AllMoney = 0;
        printf("%s %02d\n", rec[on].name, rec[on].month);
        while(on < next){
            while(on < next - 1&& !(rec[on].status == true && rec[on + 1].status == false)){
                on++;
            } 
            off = on + 1;
            if(off == next){
                on = next;
                break;
            }
            printf("%02d:%02d:%02d:", rec[on].dd, rec[on].hh, rec[on].mm);
            printf("%02d:%02d:%02d:", rec[off].dd, rec[off].hh, rec[on].mm);
            int time = 0, money = 0;
            get_ans(on, off, time, money);
            AllMoney += money;
            printf("%d $%.2f\n", time, money / 100.0);
            on = off + 1;
        }
        printf("Total amount: $%.2f\n", AllMoney / 100.0);
    }
    return 0;
}

#A1025
bool cmp(Student a, Student b){
    if(a.score != b.score) return a.score > b.score;
    else return strcmp(a.id, b.id) < 0;
}

#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
struct Student{
    char id[15];
    int score;
    int location_number;
    int local_rank;
}stu[30010];

bool cmp(Student a, Student b){
    if(a.score != b.score) return a.score > b.score;
    else return strcmp(a.id > b.id) < 0;
}

int main(){
    int n, k, num = 0;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%s %d", stu[num].id, &stu[num].score);
        stu[num].location_number = i;
        num++;
    }
    sort(stu + num -k, stu + num, cmp);
    stu[num - k].local_rank = 1;
    for(int j = num - k +1; j < num; j++){
        if(stu[j].score == stu[j-1].score){
            stu[j].local_rank = stu[j-1].local_rank;
        }
        else{
            stu[j].local_rank = j + 1 - (num - k);
        } 
    }

printf("%d\n", num);
sort(stu, stu + num, cmp);
int r = 1;
for(int i = 0; i < num; i++){
    if(i > 0 && stu[i].score != stu[i-1].score){
        r = i + 1;
    }
    printf("%s ", stu[i].id);
    printf("%d %d %d\n", r, stu[i].location_number, stu[i].local_rank);   
}
return 0;
}
