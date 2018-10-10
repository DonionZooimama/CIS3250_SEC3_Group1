#include "header.h"

//Jordan
void ReadXML(int *Width, int *Height, int *Highscores)
{
    char cur_line[555]; // This assumes max line length is 554 characters
    char str2[20][20];
    char s[4] = "<>";
    char *token;
    int counter, counter1 , counter3;
    int line_len;
    int found = 0 , savePlace = 0 , colmun = 0 , row = 0, list = 0 , flag = 0;
    FILE * file = fopen( "data.xml" , "r");

    while (
        fscanf(file, "%s", cur_line) != EOF && // Check to see if EOF is a valid return for fscanf
        flag == 0
        )
    {
        // Take each line of xml file and store it in cur_line
        line_len = strlen(cur_line);

        counter = 0;
        found = 0;

        if ( line_len > 3 )
        {
            if(
                // If cur_line is "<~~~>", "<~~~>X", "<~~~>XX", or "<~~~>XXX"
                cur_line[counter] == '<'  && 
                ( 
                    cur_line[line_len - 1] == '>'  || 
                    cur_line[line_len - 2] == '>'  || 
                    cur_line[line_len - 3] == '>'  || 
                    cur_line[line_len - 4] == '>'
                ) 
            )
            {
                counter++;
            }
            else if ( cur_line[counter+1] == '<' && cur_line[line_len - 1] == '>' )
            {
                // If cur_line is "X<~~~>"
                counter += 2;
            }
            else if ( cur_line[counter+2] == '<' &&  cur_line[line_len - 1] == '>' )
            {
                // If cur_line is "XX<~~~>"
                counter += 3;
            }
            else if ( cur_line[counter+3] == '<' &&  cur_line[line_len - 1] == '>' )
            {
                // If cur_line is XXX<~~~>
                counter += 4;
            }
            else
            {
                // if cur_line doesnt follow any of the above formats, found (found what???) = 1
                found = 1;
            }


            if (found == 0)
            {
                while(counter < line_len-2 )
                {
                    if( 
                        (  cur_line[counter] >= 'A'  &&  cur_line[counter] <= 'z'  )  || 
                           cur_line[counter] == '<'                                   || 
                           cur_line[counter] == '>'                                   || 
                           cur_line[counter] == '/'                                   
                        )
                    {
                        // If cur_line[counter] is a letter, or '<', '>', '/'
                        // Do nothing
                    }
                    else if (found == 0)
                    {
                        if(
                            cur_line[counter+1] == '\0'  || 
                            cur_line[counter+2] == '\0'  || 
                            cur_line[counter+3] == '\0'  ||
                            cur_line[counter+4] == '\0'  
                        )
                        {
                            if(cur_line[counter-1] != '>')
                            {
                                flag = 1;
                            }
                            // Else ??
                        }
                        else if(cur_line[counter-1] == '>' && cur_line[counter+1] == '<' )
                        {
                            // What
                        }
                        else if (cur_line[counter-1] == '>' && cur_line[counter+2] == '<')
                        {
                            // Is  
                        }
                        else if (cur_line[counter-1] == '>' && cur_line[counter+3] == '<')
                        {
                            // This
                        }
                        else
                        {
                            flag = 1;
                        }
                        // found gets switched on no matter what
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
        else {

        }

        token = strtok(cur_line,s);

        counter = 0;

        if (cur_line[counter] == '<')
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

            if (cur_line[counter] == '<')
            {
                counter++;
            }

            while ( strlen(token) > counter1 )
            {
                if ( (line_len == 1 || line_len == 2 || line_len == 3) && found == 0 )
                {
                    counter = 0;
                    found = 1;
                }

                if (cur_line[counter] == token[counter1] )
                {
                    counter3++;
                }
                counter1++;
                counter++;
            }
            if ( cur_line[counter +1 ] == '>' || cur_line[counter+1] == '<')
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