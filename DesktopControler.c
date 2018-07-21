#include <stdio.h>
#include <stdlib.h>
#define EFN "D:\\efn.pyw"
#define FAS "D:\\inf.tsk"
#define DAS "del D:\\efn.pyw /f /s /q"
#define CAS1 "tasklist /fi \"STATUS eq running\" /fo csv > D:\\inf.tsk"
#define CAS2 "echo ~ >> D:\\inf.tsk"
#define CMD "start /max"
#define MLC 5000
#define NULL 0
#define false 0
#define true 1
#define all 0
void cls();
void ctl();
int main()
{
    system("title Rayanoos.ir");
    system("echo off");
    system("cls");
    char *ptr;
    FILE* fp;
    fp = fopen(EFN , "r");
    if (!fp){
        fclose(fp);
        fp = fopen(EFN,"w");
        fprintf(fp,"%d",1);
        fclose(fp);
        return(0);
    }
    fclose(fp);
    system(CAS1);
    system(CAS2);
    fp = fopen(FAS,"r");
    ptr =  (char*) malloc(MLC);
    fscanf(fp,"%[^~]s",ptr);
    fclose(fp);
    cls(ptr);
    free(ptr);
    printf("\n\n-- Press [y] to Continue in this computer.\n-- Press [n] to start normaly.");
    char cl  ;
    while(1)
    {
        cl = getch();
        if (cl=='Y' || cl=='y' )
        {
            system(CMD);
            break;
        }
        if ( cl=='N' || cl=='n')
        {
            system(DAS);
            system("cls");
            system("shutdown -L");
            system("cls");
            printf("\n\n--- Please wait for Log off ...");
            break;
        }
    }
    return 0;
}
void cls (char *cns)
{
    char *ptr;
    int linenum,ier = 0,lsline=0;
    ptr =  (char*) malloc(MLC);
    ptr = cns;

    for (ier=0 ; ier<MLC; ++ier)
    {
        if (ptr[ier]=='K' && ptr[ier+1]=='\"')
        {

            ptr[ier+2] = '$';
            lsline++;
        }else if (ptr[ier-1]=='U' && ptr[ier]=='s' && ptr[ier+1]=='a' && ptr[ier+2]=='g'
                 &&ptr[ier+3]=='e' && ptr[ier+4]=='\"')
                 {
                    ptr[ier+5]='$';
                    lsline++;
                }
    }
    ctl(lsline , ptr);
    free(ptr);
}

void ctl(int lines , char * LIST)
{
    int ier=0,ier2 , bl = false;
    char * list[lines+1];
    for (ier =0 ; ier <= (lines+1);ier++)
        list[ier] = (char*) malloc(MLC);
    list[all] = LIST;
    for (ier2=1 ; ier2 < (lines+1) ; ier2++)
    {
        for (ier=0 ; ier < MLC ; ier++)
        {
            if (list[all][ier]=='$'){
                list[ier2][ier]=list[all][ier];
                list[all][ier]='*';
                break;
            }


            if (list[all][ier]=='\"') bl = true;
            if (bl == true)
            {
            list[ier2][ier]=list[all][ier];
            list[all][ier]='*';
            }



        }
    }
int ii;
    for (ier2=1 ; ier2 < (lines+1) ; ier2++)
    {
        for ( ier = 0 ; ier < MLC ;++ier)
        {
            if (list[ier2][ier]=='\"'){ii=++ier; break;
        }}

        for ( ier =0 ; ii < MLC ; ++ier,ii++){
            list[ier2][ier] =list[ier2][ii];
        }
    }
    char ename[70],cmd[256];
    for (ier2=2 ; ier2 < (lines+1) ; ier2++)
    {
        for (ii = 0 ; ii <sizeof(ename) ; ii ++) ename[ii]='\0';
        for (ii = 0 ; ii <sizeof(cmd) ; ii ++) cmd[ii]='\0';
        for (ier = 0 ; ier < MLC ; ++ier )
        {
            if (list[ier2][ier]=='\"') break;
            ename[ier] = list[ier2][ier];
        }
        if (!(strstr(ename , "DesktopControler"))
                && !(strstr(ename , "conhost"))  ){
        strcpy(cmd , "taskkill /im ");
        strcat(cmd , ename);
        strcat(cmd , " /f");
        system(cmd);
        system("cls");
        }
    }


    for (ier=0;ier <= (lines+1); ier++) free(list[ier]); // Free mallocs
}

/*
*  Free C/C++ Source codes.
*  www.Rayanoos.ir
*/
