/******************************************************************************
�� �� ��    HW04_02
��    ��    ����
��    ��	������1601
ѧ    ��    U201614898
��    ��    1007458378@qq.com
��    ��    C���Գ������
�� ҵ ��    HW04_02
��ֹ����    2016��4��27��

������
���������뷽������д��������һ�е籨���֣�������ѡ���������һΪԭ�������
��Ϊ�任��ĸ�Ĵ�Сд����Сд��a����ɴ�д��A������д��D�����Сд��d������
�����ַ����䡣��#define��������Ƿ�任��ĸ�Ĵ�Сд��
���磬#define CHANGE 1 ������任������֣���#define CHANGE 0��ԭ�������

���룺
hello !
world !
hello world!
abcd
0j$MmKmKgFee:rOiN2vCuSHB94?Ir'XK)b#1$>"B5]?[@ZN:{4>.R:15R}KX=n$|0=xm
uQ;v$2?,$dt>.u$f]*5co?wVee>w\4)fJa7SEbMI)9oD!iYNmO=?3g>Xmo)664
!9rCWvM,_&%t^;6&l^Pbi*iiqXzGGBx#.`+T*)yoZ6!-"x(b`j\pQu,</pre></p><h4>�������</h4><p><pre>hello !
WORLD !
hello world!
ABCD
0j$MmKmKgFee:rOiN2vCuSHB94?Ir'XK)b#1$>"B5]?[@ZN:{4>.R:15R}KX=n$|0=xm
Uq;V$2?,$DT>.U$F]*5CO?WvEE>W\4)FjA7seBmi)9Od!IynMo=?3G>xMO)664
!9RcwVm,_&%T^;6&L^pBI*IIQxZggbX#.`+t*)YOz6!-"X(B`J\PqU,
******************************************************************************/

#include<stdio.h>
#include<string.h>
#define CHANGE c%2

void Conversion();


char s[100];
int len;
int count = 0;
int i;

int main()
{
	while (fgets(s,100,stdin))
	{
		len = strlen(s) ;
		char c= s[0];
		if (CHANGE == 0)
		{
			printf("%s", s);
		}
		else
		{
			Conversion();
		}
	}
}

void Conversion()
{
	for (int i = 0; i < len; i++)
	{
		if ('a' <= s[i] && s[i] <= 'z')
		{
			s[i] = s[i] - 32;
		}
		if ('A' <= s[i] && s[i] <= 'Z')
		{
			s[i] = s[i] + 32;
		}
	}
	printf("%s", s);
}

