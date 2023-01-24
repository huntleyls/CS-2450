#include <stdio.h>
  
void printStringStats(char *str)
{	
	int i;
	int vowels=0;
	int consonants = 0;
	int ch;
	int size;
	
	for(i=0;str[i] != '\0';i++)   
    	{
    	if((str[i]>=65 && str[i]<=90)|| (str[i]>=97 && str[i]<=122))
    	{		
	    for (ch = 0; str[ch] != '\0'; ++ch);
	    
	    
	    
            if(str[i]=='a'|| str[i]=='e'||
		str[i]=='i'||str[i]=='o'||
		str[i]=='u'||str[i]=='A'||
		str[i]=='E'||str[i]=='I'||
		str[i]=='O' ||str[i]=='U')
		      vowels++;
            else
             consonants++;
        }
 
 	}
	if (ch >= 1)
		{
			size = ch + 1;
		}
    
	
    	
	printf("%d:%d:%d:%d \n", ch, size, vowels, consonants);

	

}
