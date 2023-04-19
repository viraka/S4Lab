#include<stdio.h>
int q[100];
int f = -1;
int r = -1;
void insert (int n)
{
        if (f==-1)
            f=0;
        r = r+1;
        q[r] = n;
}
int delete ()
{
        int n;
        n = q[f];
        f = f+1;
        if (f==r)
            f=r=-1;
        return n;
}
int main()
{
        int p, tq, n, i, t=0,ct;
        float twt = 0, ttat = 0;
        printf ("\nEnter how many processes: ");
        scanf ("%d", &n);
        int a[10][6], bt[10], exist[10] = {0};
        printf ("\n Enter arrival time & burst time of each process:");
        for (i=0; i<n; i++)
        {
                
                printf ("\nProcess ID: ");
                scanf ("%d", &a[i][0]);
                printf ("\nA.T of process %d: ", a[i][0]);
                scanf ("%d", &a[i][1]);
                printf ("\nB.T of process %d: ", a[i][0]);
                scanf ("%d", &a[i][2]);
                bt[i] = a[i][2];
        }
        printf ("\nEnter time quantum: ");
        scanf ("%d", &tq);
        insert (0);
        exist[0] = 1;
        t = a[0][1];
        while (f<=r && f>=0)
        {
                p = delete ();
                if (a[p][2]>=tq)
                {
                        a[p][2]-=tq;
                        t+=tq;
                }
                else
                {
                        t+=a[p][2];
                        a[p][2] = 0;
                }
                for (i=0; i<n; i++)
                {
                        if (exist[i]==0 && a[i][1]<=t)
                        {
                                insert (i);
                                exist[i]=1;
                        }
                }
                if (a[p][2]==0)
                {
                    a[p][5] = t;
                    a[p][4]=a[p][5]-a[p][1];
                    a[p][3]=a[p][4]-bt[p];
                    ttat+=a[p][4];
                    twt+=a[p][3];
                }
                else
                {
                        insert (p);
                }
        }        
        printf("\nP.No.\tAT\tBT\tTAT\tWT\tCT");
        for (i=0; i<n; i++)
        {
            printf("\n%d\t%d\t%d\t%d\t%d\t%d", a[i][0], a[i][1], bt[i], a[i][4], a[i][3],a[i][5]);
        }
        printf ("\nAverage Turnaround time = %f", ttat/n);
        printf ("\nAverage Waiting time = %f", twt/n);
        return 0;
}
