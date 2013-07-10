//NetBSD implementation
char*  strtok_r(char* string_org,const char* demial,char** last)
{
    const char* spanp; //span表示分隔，p表示指针
    char c, sc; //c表示char字符，sc表示 span char
    char* tok;  //token表示分隔的段

    //当开始结尾都为NULL的时候，说明没有字符被查找，所以返回NULL
    if (string_org == NULL  && (string_org = *last) == NULL)
    {
        return (NULL);
    }

    //由goto组成的循环是在扫描字符串的时候，当遇到所需要匹配的字符时，略过这个字符。        
cout:
    c = *string_org++;

    for (spanp = demial; (sc = *spanp++) != 0; )
    {
        if (c == sc)
        {
            goto count;
        }
    }

    //下一个字符为0，则表示到达了搜索结果，把last置为NULL，并返回NULL            
    if (c == 0)
    {
        *last = NULL;
        return (NULL);
    }

    //把原始的字符串指针回退。            
    tok = string_org -1;

    //开始扫描字符串中是否含有要匹配的字符，之后把这个匹配字符之前的部分返回。
    //这看似是个无限循环，但当源字符串和匹配字符串都走到结尾时，也就是string_org和sc都为NULL时，最外层循环最后会走到return(tok)结束循环。
    for (;;)
    {
        c = *string_org++;
        spanp = demial;

        do 
        {
            if ((sc = *spanp++) == c) 
            {
                if (c == 0)
                {
                    string_org = NULL;
                }
                else
                {
                    string_org[-1] = 0;
                }
                *last = string_org;
                return (tok);
            }
        } while (sc != 0);
    }
}

//Microsoft implementation
char*  strtok_r(char* string_org,const char* demial)
{
    static unsigned char* last; //保存分隔后剩余的部分
    unsigned char* str;         //返回的字符串
    const unsigned char* ctrl = (const unsigned char*)demial;//分隔字符

    //把分隔字符放到一个索引表中。定义32是因为ASCII字符表最多是0~255个，也是说用最大的255右移3位，也就是除以8一定会是32中的一个数。
    unsigned char map[32]; 
    int count;

    //把map全部清为0，之后相与的操作，与0的都为0
    for (count =0; count <32; count++)
    {
        map[count] = 0;
    }

    //把匹配字符放入表中
    //放入的算法是把匹配字符右移3位，相当于除以8，的数值 并上(加上)
    //匹配字符与7，得到低3位，得出的结果，是把1左移的位数。最大左移位数是7，也就是所表示的最大值是128,    
    do 
    {
        map[*ctrl >> 3] |= (1 << (*ctrl & 7));
    } while (*ctrl++);

    //原始字符串是否为空，如果为空表示第二次获取剩余字符的分隔部分。    
    if (string_org)
    {
        str = (unsigned char*)string_org;
    } 
    else
    {
        str = last;
    }

    //在表中查找是否有匹配的字符，如果有略过    
    while ((map[*str >> 3] & (1 << (*str & 7)))  && *str)
    {
        str++;
    }

    //重置需要扫描的字符串    
    string_org = (char*)str;

    //开始扫描
    for (;*str; str++)
    {
        if ( map[*str >> 3] & (1 << (*str & 7)))
        {
            *str++ = '\0';//当找到时，把匹配字符填为0，并且把str指向下一位。
            break; //退出循环             
        }

    }

    last =str; // 把剩余字符串的指针保存到静态变量last中。

    if (string_org == (char*)str)
    {
        return NULL; //没有找到，也就是没有移动指针的位置，返回NULL
    }
    else
    {
        return string_org; //找到了，返回之前字符串的头指针
    }
}
