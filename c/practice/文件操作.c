# include<stdio.h>

int main()
{
    char ch;
    FILE *fp;
    int i;
    if((fp=fopen("C:\Users\hlc24\Desktop\111.txt","r"))==NULL) /* 打开一个由argv[1]所指的文件*/
    {
        printf("not open");
        exit(0);
    }
    while ((ch=fgetc(fp))!=EOF) /* 从文件读一字符，显示到屏幕*/
        putchar(ch);
    fclose(fp);
    return 0;
}