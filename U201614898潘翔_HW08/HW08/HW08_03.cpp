#include <stdio.h> 
#include <ctype.h>  //�����ж��ַ����� �ַ�����
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
	s[0] = toupper(s[0]);				//����һ���ַ���ɴ�д
	for (int i = 1; s[i] != '\n'; ++i)  
	{         
		if (s[i] == ' ')       
		{             
			s[i+1] = toupper(s[i+1]);     
			i++;        
		}    
	}         
	FILE *fp;    
	fp = fopen("test.txt", "w+");  //�ض����ļ�
	char ch;
	for (int i = 0; (ch=s[i]) != '\n'; i++)   
	{         
		fputc(ch, fp); //д���ļ�
		putchar(ch);   //�������Ļ
	}
	fclose(fp);    
	return 0; 
}