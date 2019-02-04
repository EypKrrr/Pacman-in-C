//Eyup KORURER 06.12.2017
//GNU GCC compiler ile derlenmiþtir.


#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#include <conio.h>
/**
*0=duvar 178
*1=boþ yol boþluk
*2=yem 254
*3=düþman 190
*4=kullanýcý 184
*/

#define UP_ARROW    72
#define LEFT_ARROW  75
#define DOWN_ARROW  80
#define RIGHT_ARROW 77

int alan[19][18]=
{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,3,1,1,1,1,1,1,0,0,1,1,1,1,1,1,3,0},{0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0},
    {0,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,0},{0,1,0,0,1,0,0,1,1,1,1,0,0,1,0,0,1,0},{0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0},
    {0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0},{0,1,1,1,1,0,0,1,0,0,1,0,0,1,1,1,1,0},{0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0},
    {0,1,1,1,1,1,1,1,4,1,1,1,1,1,1,1,1,0},{0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0},{0,1,1,1,1,0,0,1,0,0,1,0,0,1,1,1,1,0},
    {0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0},{0,1,0,0,1,0,0,1,0,0,1,0,0,1,0,0,1,0},{0,1,0,0,1,0,0,1,1,1,1,0,0,1,0,0,1,0},
    {0,1,0,0,1,1,1,1,0,0,1,1,1,1,0,0,1,0},{0,1,0,0,0,0,0,1,0,0,1,0,0,0,0,0,1,0},{0,1,1,1,1,1,1,1,0,0,1,1,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};

int yem_haritasi[19][18]=
{
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},{0,2,2,2,2,2,2,2,0,0,2,2,2,2,2,2,2,0},{0,2,0,0,0,0,0,2,0,0,2,0,0,0,0,0,2,0},
    {0,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,0},{0,2,0,0,2,0,0,2,2,2,2,0,0,2,0,0,2,0},{0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0},
    {0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0},{0,2,2,2,2,0,0,2,0,0,2,0,0,2,2,2,2,0},{0,2,0,0,0,0,0,2,0,0,2,0,0,0,0,0,2,0},
    {0,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,2,0},{0,2,0,0,0,0,0,2,0,0,2,0,0,0,0,0,2,0},{0,2,2,2,2,0,0,2,0,0,2,0,0,2,2,2,2,0},
    {0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0},{0,2,0,0,2,0,0,2,0,0,2,0,0,2,0,0,2,0},{0,2,0,0,2,0,0,2,2,2,2,0,0,2,0,0,2,0},
    {0,2,0,0,2,2,2,2,0,0,2,2,2,2,0,0,2,0},{0,2,0,0,0,0,0,2,0,0,2,0,0,0,0,0,2,0},{0,2,2,2,2,2,2,2,0,0,2,2,2,2,2,2,2,0},
    {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0}
};


int konum[2]= {9,8};
int konum1[2]= {1,1};
int konum2[2]= {1,16};
int scor=0;


void dusman_hamlesi(int durum,int x,int y)
{

    if(x<konum[0] && y<konum[1] )//Oyuncu sað alt köþedeyse
    {

        if(alan[x][y+1]==1 || alan[x][y+1]==4)//Sað
        {
            alan[x][y+1]=3;
            y++;
        }
        else if(alan[x+1][y]==1 || alan[x+1][y]==4) //Alt
        {
            alan[x+1][y]=3;
            x++;
        }
        else if(alan[x][y-1]==1 || alan[x][y-1]==4) //Sol
        {
            alan[x][y-1]=3;
            y--;
        }
        else if(alan[x-1][y]==1 || alan[x-1][y]==4) //Üst
        {
            alan[x-1][y]=3;
            x--;
        }
    }
    else if(x<konum[0] && y==konum[1])//Oyuncu alttaysa
    {

        if(alan[x+1][y]==1 || alan[x+1][y]==4 ) //Alt
        {
            alan[x+1][y]=3;
            x++;
        }
        else if(alan[x][y-1]==1 || alan[x][y-1]==4 ) //Sol
        {
            alan[x][y-1]=3;
            y--;
        }
        else if(alan[x][y+1]==1 || alan[x][y+1]==4 )//Sað
        {
            alan[x][y+1]=3;
            y++;
        }
        else if(alan[x-1][y]==1 || alan[x-1][y]==4 )  //Üst
        {
            alan[x-1][y]=3;
            x--;
        }

    }
    else if(x<konum[0] && y>konum[1])//Oyuncu sol alt köþedeyse
    {

        if(alan[x+1][y]==1 || alan[x+1][y]==4 ) //Alt
        {
            alan[x+1][y]=3;
            x++;
        }
        else if(alan[x][y-1]==1 || alan[x][y-1]==4 ) //Sol
        {
            alan[x][y-1]=3;
            y--;
        }
        else if(alan[x][y+1]==1 || alan[x][y+1]==4)//Sað
        {
            alan[x][y+1]=3;
            y++;
        }
        else if(alan[x-1][y]==1 || alan[x-1][y]==4 )  //Üst
        {
            alan[x-1][y]=3;
            x--;
        }
    }
    else if(x==konum[0] && y>konum[1])//Oyuncu soldaysa
    {

        if(alan[x][y-1]==1 || alan[x][y-1]==4 ) //Sol
        {
            alan[x][y-1]=3;
            y--;
        }
        else if(alan[x-1][y]==1 || alan[x-1][y]==4 ) //Üst
        {
            alan[x-1][y]=3;
            x--;
        }
        else if(alan[x+1][y]==1 || alan[x+1][y]==4 ) //Alt
        {
            alan[x+1][y]=3;
            x++;
        }
        else if(alan[x][y+1]==1 || alan[x][y+1]==4 )//Sað
        {
            alan[x][y+1]=3;
            y++;
        }
    }
    else if(x>konum[0] && y>konum[1])//Oyuncu sol üst köþedeyse
    {

        if(alan[x-1][y]==1 || alan[x-1][y]==4) //Üst
        {
            alan[x-1][y]=3;
            x--;
        }
        else if(alan[x][y-1]==1 || alan[x][y-1]==4 ) //Sol
        {
            alan[x][y-1]=3;
            y--;
        }
        else if(alan[x][y+1]==1 || alan[x][y+1]==4 )//Sað
        {
            alan[x][y+1]=3;
            y++;
        }
        else if(alan[x+1][y]==1 || alan[x+1][y]==4 ) //Alt
        {
            alan[x+1][y]=3;
            x++;
        }
    }
    else if(x>konum[0] && y==konum[1])//Oyuncu üstteyse
    {

        if(alan[x-1][y]==1 || alan[x-1][y]==4 ) //Üst
        {
            alan[x-1][y]=3;
            x--;
        }
        else if(alan[x][y-1]==1 || alan[x][y-1]==4) //Sol
        {
            alan[x][y-1]=3;
            y--;
        }
        else if(alan[x][y+1]==1 || alan[x][y+1]==4 )//Sað
        {
            alan[x][y+1]=3;
            y++;
        }
        else if(alan[x+1][y]==1 || alan[x+1][y]==4 ) //Alt
        {
            alan[x+1][y]=3;
            x++;
        }
    }
    else if(x>konum[0] && y<konum[1])//Oyuncu sað üst köþedeyse
    {

        if(alan[x][y+1]==1 || alan[x][y+1]==4 )//Sað
        {
            alan[x][y+1]=3;
            y++;
        }
        else if(alan[x-1][y]==1 || alan[x-1][y]==4 ) //Üst
        {
            alan[x-1][y]=3;
            x--;
        }
        else if(alan[x][y-1]==1 || alan[x][y-1]==4 ) //Sol
        {
            alan[x][y-1]=3;
            y--;
        }
        else if(alan[x+1][y]==1 || alan[x+1][y]==4 ) //Alt
        {
            alan[x+1][y]=3;
            x++;
        }
    }
    else if(x==konum[0] && y<konum[1])//Oyuncu saðdaysa
    {

        if(alan[x][y+1]==1 || alan[x][y+1]==4 )//Sað
        {
            alan[x][y+1]=3;
            y++;
        }
        else if(alan[x+1][y]==1 || alan[x+1][y]==4 ) //Alt
        {
            alan[x+1][y]=3;
            x++;
        }
        else if(alan[x-1][y]==1 || alan[x-1][y]==4 ) //Üst
        {
            alan[x-1][y]=3;
            x--;
        }
        else if(alan[x][y-1]==1 || alan[x][y-1]==4 ) //Sol
        {
            alan[x][y-1]=3;
            y--;
        }
    }
    if(durum==1)
    {
        alan[konum1[0]][konum1[1]]=1 ;
        konum1[0]=x;
        konum1[1]=y;
    }
    else
    {
        alan[konum2[0]][konum2[1]]=1 ;
        konum2[0]=x;
        konum2[1]=y;
    }

}



int kontrol(int yon)
{
    switch (yon)
    {
    case 1:
        if(alan[konum[0]-1][konum[1]]==1)
            return 1;
        else
            return 0;
    case 2:
        if(alan[konum[0]][konum[1]+1]==1)
            return 1;
        else
            return 0;
    case 3:

        if(alan[konum[0]+1][konum[1]]==1)
            return 1;
        else
            return 0;
    case 4:

        if(alan[konum[0]][konum[1]-1]==1)
            return 1;
        else
            return 0;
    default:
        return 0;
    }
}

void ilerle(int yon)
{
    if(yon==1)
    {
        alan[konum[0]][konum[1]]=1;
        konum[0]-=1;
        alan[konum[0]][konum[1]]=4;
        if(yem_haritasi[konum[0]][konum[1]]==2)
        {
            scor++;
            yem_haritasi[konum[0]][konum[1]]=0;
        }
    }
    else if(yon==2)
    {
        alan[konum[0]][konum[1]]=1;
        konum[1]+=1;
        alan[konum[0]][konum[1]]=4;
        if(yem_haritasi[konum[0]][konum[1]]==2)
        {
            scor++;
            yem_haritasi[konum[0]][konum[1]]=0;
        }
    }
    else if(yon==3)
    {
        alan[konum[0]][konum[1]]=1;
        konum[0]+=1;
        alan[konum[0]][konum[1]]=4;
        if(yem_haritasi[konum[0]][konum[1]]==2)
        {
            scor++;
            yem_haritasi[konum[0]][konum[1]]=0;
        }
    }
    else if(yon==4)
    {
        alan[konum[0]][konum[1]]=1;
        konum[1]-=1;
        alan[konum[0]][konum[1]]=4;
        if(yem_haritasi[konum[0]][konum[1]]==2)
        {
            scor++;
            yem_haritasi[konum[0]][konum[1]]=0;
        }
    }
}

void yazdir()
{
    int i,j;
    for(i=0; i<19; i++)
    {
        for(j=0; j<18; j++)
        {
            if(alan[i][j]==0)
                printf("%c%c",178,178);
            else if(alan[i][j]==3)
                printf("%c ",190);
            else if(alan[i][j]==4)
                printf("%c ",184);
            else if(yem_haritasi[i][j]==2)
                printf("%c ",254);
            else if(alan[i][j]==1)
                printf("  ");


        }
        if(i==0)
            printf("Score:%d",(5*scor));
        printf("\n");
    }
}

int main()
{

    int secim=2,eski_yon=68,ilerlesin_mi;
    char yon;
    yazdir();
    printf("OYUNA BASLAMAK ICIN HERHANGI BIR TUSA BASIN!!!");
    getch();

    do
    {

        if (1)
        {
            Sleep(200);
            if (kbhit())
            {

                yon =getch();

            }
        }

        if(yon==72)
        {
            secim=1;
        }
        else if(yon==77)
        {
            secim=2;
        }
        else if(yon==80)
        {
            secim=3;
        }
        else if(yon==75)
        {
            secim=4;
        }
        ilerlesin_mi=kontrol(secim);
        if(ilerlesin_mi==1)
            ilerle(secim);

        dusman_hamlesi(1,konum1[0],konum1[1]);
        dusman_hamlesi(2,konum2[0],konum2[1]);

        system("CLS");
        yazdir();
        if(konum[0]==konum1[0] && konum[1]==konum1[1] || konum[0]==konum2[0] && konum[1]==konum2[1])
{
    printf("KAYBETTINIZ!!!\a");
    getch();
    break;
}else if(scor==140)
{
    printf("TEBRIKLER  KAZANDINIZ\a");
    getch();
    break;
}
    }
    while(1);
    return 0;
}
