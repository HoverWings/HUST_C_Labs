#include <stdio.h> 
#include <ctype.h>  //用于判断字符类型 字符处理
int main()
{      
	char s[100];          
	for (int i = 0; i < 100; ++i)   
	{          
		scanf("%c", &s[i]);        
		if (s[i] == '\n')         
		{             
			break;        
		}  
	}      
	s[0] = toupper(s[0]);				//将第一个字符变成大写
	for (int i = 1; s[i] != '\n'; ++i)  
	{         
		if (s[i] == ' ')       
		{             
			s[i+1] = toupper(s[i+1]);     
			i++;        
		}    
	}         
	FILE *fp;    
	fp = fopen("test.txt", "w+");  //重定向到文件
	char ch;
	for (int i = 0; (ch=s[i]) != '\n'; i++)   
	{         
		fputc(ch, fp); //写入文件
		putchar(ch);   //输出到屏幕
	}
	fclose(fp);    
	return 0; 
}