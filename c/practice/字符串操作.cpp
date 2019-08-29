

//字符串比较
bool strcmp(const char*str1,const char *str2)
{
    assert((str1!=null)&&(str2!=null));
    int ret;
    while(!(ret=*(unsgined char*)str1-*(unsgined char*)str2) && *str2)
    {
        str1++;
        str2++;
    }
    if(ret>0)
    {
        return true;
    }
    else if(ret<0)
    {
        return false;
    }
}

int strcmp(const char *source,const char *dest)  
{  
    if((source == NULL) && (dest == NULL))  
    {  
        return 0;  
    }  
    while((*source != '\0') && (*dest != '\0'))  
    {  
        if(*source != *dest)  
        {  
            return 1;  
        }  
        else  
        {  
            source ++;  
            dest ++;  
        }  
    }  
    if((*source == '\0') && (*dest == '\0'))  
    {  
        return 0;  
    }  
    else  
    {  
        return 1;  
    }  
}  


///字符串拷贝

char * strcpy(char *str1,const char* str2)
{
    assert((str1!=null)&&(str2!=null));
    char *temp=str1;
    while((*str1++==*str2++)!='\0')
    {
        
    }

    return temp;
}