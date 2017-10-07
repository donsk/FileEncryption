#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<conio.h>

void printMenu(void);
int checkPwd(int type);
int encryptFile(char *sourcefile,char *secretKey,char *targetFile);
char redo(void);

int password=123456;
int main()
{
    int newpwd,newpwda;
    char sourcefile[30],targetFile[30],secretKey[21],action;

    if(!checkPwd(1))
    {
        printf("sorry ,you input the wrong pwd three times,press any key to exit...");
        getch();
        exit(1);
    }

    while(1)
    {
        system("cls");
        printMenu();
        scanf("%c",&action);
        fflush(stdin);
        system("cls");

        switch(action) {
            case 'z':
                exit(0);
                break;
            case 'a':
                while (1) {
                    printf("input the file name yout wang to encryption(include the path):");
                    scanf("%s", sourcefile);
                    printf("input the secretKey: ");
                    scanf("%s", secretKey);
                    printf("the file name after encryption (include the path):");
                    scanf("%s", targetFile);
                    if (encryptFile(sourcefile, secretKey, targetFile));
                    {
                        printf("congratualition,the file [%s] cryption success,save as[%s].\n", sourcefile, targetFile);
                        if (redo() == 'a') {
                            system("cls");
                        } else {
                            break;
                        }

                    }

                }
                break;

            case 'b':
                while (1) {
                    printf("input the file name you want to uncryption(include the path):");
                    scanf("%s", sourcefile);
                    printf("input the secretKey;");
                    scanf("%s", secretKey);
                    printf("the file name after uncryption(include the path):");
                    scanf("%s", targetFile);
                    if (encryptFile(sourcefile, secretKey, targetFile)) {
                        printf("congratualition,the file[%s] uncryption success,save as[%s].\n", sourcefile,
                               targetFile);

                    }
                    if (redo() == 'a') {
                        system("cls");

                    } else {
                        break;
                    }
                }
                break;
            case 'c':
                while (1)
                {
                    if(!checkPwd(2)){
                        printf("sorry you input the wront pwd three times,press any key to exit...");
                        getch();
                        exit(0);
                    }
                    if(newpwd==newpwda) {
                        password = newpwd;
                        printf("good ,changed the pwd success!\n");

                    }else{
                        printf("the pwd you input twice times not same,chage the pwd failed!\n");

                    }
                    if(redo()=='a'){
                        system("cls");
                    }else{
                        break;
                    }
                }
                break;

            default:
                printf("no the menu,press any key to the main menu...");
                getch();


        }

    }
    return EXIT_SUCCESS;

    return 0;
}


void printMenu() {
    printf("***************** file encryption soft *****************\n");
    printf("*                                                      *\n");
    printf("*      **************************************          *\n");
    printf("*      *                                    *          *\n");
    printf("*      *  software owener:C programing china           *\n");
    printf("*      *  author:rabbit                        *       *\n");
    printf("*      *  PS: Dont ask why called rabbit          *    *\n");
    printf("*      *                                    *          *\n");
    printf("*      **************************************          *\n");
    printf("*                                                      *\n");
    printf("*                                                      *\n");
    printf("*      chose the action below :                        *\n");
    printf("*      a. file encryption                              *\n");
    printf("*      b. file uncryption                              *\n");
    printf("*      c. change pwd                                   *\n");
    printf("*      z. exit                                         *\n");
    printf("*                                                      *\n");
    printf("********************************************************\n");
}
    int checkPwd(int type)
    {
        int pwd;
        int trytimes;

        if(type==1){
            printf("the soft has a code,check out right now: ");

        } else{
            printf("type the old pwd before make a new one:");

        }
        for(trytimes=1;trytimes<=3;trytimes++)
        {
            scanf("%d",&pwd);
            fflush(stdin);
            if(pwd==password){
                return 1;
                break;
            }else if(trytimes==3){
                return 0;

            } else{
                printf("sorry,the pwd is wrong,you still have %d times:",3-trytimes);

            }
        }
        return 0;
    }


int encryptFile(char *sourcefile,char *secretKey,char *targetFile){
    FILE *fpSource,*fpTarget;
    char buffer[21];
    int readCount,keyLen=strlen(secretKey),i;

    fpSource=fopen(sourcefile,"rb");
    if(fpSource==NULL){
        printf("can't open %s,check the file name or path!\n");
        return 0;
    }
    fpTarget=fopen(targetFile,"wb");
    if(fpTarget==NULL){
        printf("can't write in to this file,check the file path or name!\n");
        return 0;
    }
    while((readCount=fread(buffer,1,keyLen,fpSource))>0){
        for(i=0;i<readCount;i++){
            buffer[i]^=secretKey[i];
        }
        fwrite(buffer,1,readCount,fpTarget);
    }
    fclose(fpSource);
    fclose((fpTarget));
    return 1;
}

char redo(){
    char action;

    printf("then ,you want do what: ");
    printf("a,continiu.\n");
    printf("b.back to the main menu.\n");

    while(1){
        fflush(stdin);
        scanf("%c",&action);
        fflush(stdin);

        if(action!='a'&&action!='b'){
            printf("no the option,chose again: \n");

        } else{
            return action;
            break;
        }
    }
}


