#include "header.h"

//Jordan
void ReadXML(int *Width, int *Height, int *Highscores)
{
    char str[555];
    char str2[20][20];
    char s[4] = "<>";
    char *token;
    int counter, counter1 , counter3 ;
    int found = 0 , savePlace = 0 , colmun = 0 , row = 0, list = 0 , flag = 0;
    FILE * file = fopen( "data.xml" , "r");

    while (fscanf(file, "%s", str)!=EOF && flag == 0)
    {
        counter = 0;
        found = 0;

        if (strlen(str) > 3)
        {
     if  (str[counter] == '<'&& ( str[strlen(str) - 1] == '>'
                || str[strlen(str) - 2] == '>'|| str[strlen(str) - 3] == '>' || str[strlen(str) -4] == '>') )
            {
                counter++;
            }
    else if (str[counter+1] == '<' && str[strlen(str) - 1] == '>')

            {
                counter +=2 ;
            }
   else if ( str[counter+2] == '<' &&  str[strlen(str) - 1] == '>')

            {
                counter+=3;
            }
  else if ( str[counter+3] == '<' &&  str[strlen(str) - 1] == '>' )

            {
                counter += 4;
            }
 else
            {
                found = 1;
            }

   if (found == 0)
            {
                while(counter < strlen(str)-2 )
                {
                    if( (str[counter] >= 'A' && str[counter] <= 'z') || str[counter] == '<'
                            || str[counter] == '>' || str[counter] == '/')
                    {
                        //do nothing
                    }
                    else if (found == 0)
                    {
                        if (str[counter+1] == '\0' || str[counter+2] =='\0' || str[counter+3] =='\0' ||str[counter+4] == '\0')
                        {
                            if(str[counter-1] != '>')
                            {
                                flag = 1;
                            }
                        }
                        else if(str[counter-1] == '>' && str[counter+1] == '<' )
                        {
                            
                        }
                        else if (str[counter-1] == '>' && str[counter+2] == '<')
                        {
                           
                        }
                        else if (str[counter-1] == '>' && str[counter+3] == '<')
                        {
                            
                        }
                        else
                        {
                            flag = 1;
                        }

                        found = 1;
                    }
                    counter++;
                }
            }
            else
            {
                flag = 1;
            }
        }
        token = strtok(str,s);

        counter = 0;

        if (str[counter] == '<')
        {
            counter = 1;
        }

        if (token == NULL)
        {
            flag = 1;
        }
        found = 0;


        while( token != NULL && flag == 0)
        {
            counter3 = 0 ;
            counter1 = 0;

            if (str[counter] == '<')
            {
                counter++;
            }

            while ( strlen(token) > counter1 )
            {
                if ( (strlen(str) == 1 || strlen(str) == 2 || strlen(str) == 3) && found == 0 )
                {
                    counter = 0;
                    found = 1;
                }

                if (str[counter] == token[counter1] )
                {
                    counter3++;
                }
                counter1++;
                counter++;
            }
            if ( str[counter +1 ] == '>' || str[counter+1] == '<')
            {
                flag = 1;
            }

            if(counter3 == strlen(token))
            {
                strcpy(str2[savePlace],token);
                savePlace++;
            }
            else
            {
                flag = 1;
            }

            counter++;

            token = strtok(NULL,s);

        }
    }

    if (flag == 0)
    {
        counter = 0;
        counter3 = 0;
		

        while ( str2[counter][counter3] != '\0' && flag == 0)
        {
            if(str2[counter][counter3] == str2[savePlace-1][counter3+1] )
            {
                counter3++;
            }
            else
            {
                flag = 1;
            }
        }
        if (str2[savePlace-1][0] != '/' || strcmp(str2[counter] , "Configurations") != 0)
        {
            flag = 1;
        }
        counter++;
		
        while(counter < savePlace-2 && flag == 0)
        {
            counter3 = 0;
            while (str2[counter][counter3] != '\0' && flag == 0)

            {
                if (str2[counter][counter3] == str2[counter+2][counter3 + 1])
                {
                    counter3++;
                }
                else
                {
                    flag = 1;
                }
            }
            if (flag == 0 && str2[counter+2][0] =='/')
            {
                if (strcmp(str2[counter] , "Width" ) == 0 )
                {
                    colmun = atoi(str2[counter+1]);
                }
                else if(strcmp(str2[counter] , "Height" ) == 0)
                {
                    row = atoi(str2[counter+1]);
                }
                else if(strcmp(str2[counter] , "Highscores") == 0)
                {
                    list = atoi(str2[counter+1]);
                }
                else
                {
                    flag = 1;
                }
            }
            else
            {
                flag = 1;
            }
            counter += 3;
        }
    }
	
    if( colmun > 3  && colmun < 13 && row > 3 && row < 13
            && list >= 0 && list < 13)
    {
        *Width = colmun , *Height = row , *Highscores = list;
    }
    else
    {
        flag = 1;
    }
    if (flag == 1)
    {
        *Width =  7  , *Height =  6 , *Highscores = 5;
    }
    return;
}