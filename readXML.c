#include "header.h"

//Jordan
// Edit to allow same pre and post conditions.

void ReadXML(int *Width, int *Height, int *Highscores){

    FILE *fp;
    char curLine[555];
    int isWidth, isHeight, isHighscore;
    int width, height, highscore;

    fp = fopen("data.xml", "r");
    isWidth = 0;
    isHeight = 0;
    isHighscore = 0;

    if(fp == NULL)
    {
        printf("Error opening configuration file (data.xml)\n");
        return;
    }

    while ( /* fscanf(fp, "%s", curLine) != 0 */ fgets ( curLine, sizeof curLine, fp ) != NULL ) 
    {
        int lineLen;
        if( curLine != NULL  &&  strcmp(curLine, "") != 0 ) // Check to see if the line is NULL or empty (an error)
        {
            lineLen = strlen(curLine);

            if( curLine[0] == '<' )
            {
                int valueLen = 1;
                int startI;

                if( strncmp(curLine, "<Width>", 7) == 0 )
                {
                    startI = 7;
                }
                else if( strncmp(curLine, "<Height>", 8) == 0 )
                {
                    startI = 8;
                }
                else if( strncmp(curLine, "<Highscores>", 12) == 0 )
                {
                    startI = 12;
                }
                else 
                {
                    startI = -1;
                }

                if( startI != -1 )
                {
                    for(int i = startI; i < lineLen; i++){
                        if(curLine[i] != '<')
                        {
                            valueLen++;
                        }
                        else 
                        {
                            break;
                        }
                    }

                    char *valueStr = malloc(sizeof(char) * (lineLen - (startI * 2 + 1) ) + 1);
                    memcpy( valueStr, &curLine[startI], valueLen);
                    valueStr[valueLen] = '\0';

                    if( strncmp(curLine, "<Width>", 7) == 0 )
                    {
                        width = atoi(valueStr);

                        if(width != 0)
                        {
                            isWidth = 1;
                        }
                        else 
                        {
                            printf("Invalid Width value: %s\n", valueStr);
                        }
                    }
                    else if( strncmp(curLine, "<Height>", 8) == 0 )
                    {
                        height = atoi(valueStr);

                        if(height != 0)
                        {
                            isHeight = 1;
                        }
                        else 
                        {
                            printf("Invalid Height value: %s\n", valueStr);
                        }
                    }
                    else if( strncmp(curLine, "<Highscores>", 12) == 0 )
                    {
                        highscore = atoi(valueStr);

                        if(highscore != 0)
                        {
                            isHighscore = 1;
                        }
                        else 
                        {
                            printf("Invalid Highscore value: %s\n", valueStr);
                        }
                    }
                    free(valueStr);
                }    
            }
        }
        else 
        {
            printf("Empty or NULL line encountered in configuration file.\n");
            fclose(fp);
            return;
        }
    }

    fclose(fp);

    if(isWidth && isHeight)
    {
        *Width = width;
        *Height = height;
    }
    else 
    {
        printf("Invalid Configuration file.\n");
    }

    if(isHighscore)
    {
        *Highscores = highscore;
    }
    else 
    {
        *Highscores = 0;
    }

    return;
}

/*
void ReadXML(int *Width, int *Height, int *Highscores)
{
    char curLine[555]; // This assumes max line length is 554 characters
    char str2[20][20];
    char s[4] = "<>";
    char *token;
    int counter;
    int counter1;
    int counter3;
    int lineLen;
    int found;
    int savePlace;
    int column;
    int row; 
    int list; 
    int flag ; // Possibly flag for if a line doesnt contain a valid format

    found = 0;
    savePlace = 0;
    column = 0;
    row = 0;
    list = 0;
    flag = 0;

    FILE* file = fopen("data.xml" , "r");

    while (
        fscanf(file, "%s", curLine) != EOF && // Check to see if EOF is a valid return for fscanf
        flag == 0
        )
    {
        // Take each line of xml file and store it in curLine
        lineLen = strlen(curLine);

        counter = 0;
        found = 0;

        if ( lineLen > 3 )
        {
            if(
                // If curLine is "<~~~>", "<~~~>X", "<~~~>XX", or "<~~~>XXX"
                curLine[counter] == '<'  && 
                ( 
                    curLine[lineLen - 1] == '>'  || 
                    curLine[lineLen - 2] == '>'  || 
                    curLine[lineLen - 3] == '>'  || 
                    curLine[lineLen - 4] == '>'
                ) 
            )
            {
                counter++;
            }
            else if ( curLine[counter+1] == '<' && curLine[lineLen - 1] == '>' )
            {
                // If curLine is "X<~~~>"
                counter += 2;
            }
            else if ( curLine[counter+2] == '<' &&  curLine[lineLen - 1] == '>' )
            {
                // If curLine is "XX<~~~>"
                counter += 3;
            }
            else if ( curLine[counter+3] == '<' &&  curLine[lineLen - 1] == '>' )
            {
                // If curLine is XXX<~~~>
                counter += 4;
            }
            else
            {
                // if curLine doesnt follow any of the above formats, found (found what???) = 1
                found = 1;
            }


            if (found == 0)
            {
                while(counter < lineLen-2 )
                {
                    if( 
                        (  curLine[counter] >= 'A'  &&  curLine[counter] <= 'z'  )  || 
                           curLine[counter] == '<'                                   || 
                           curLine[counter] == '>'                                   || 
                           curLine[counter] == '/'                                   
                        )
                    {
                        // If curLine[counter] is a letter, or '<', '>', '/'
                        // Do nothing
                    }
                    else if (found == 0)
                    {
                        if(
                            curLine[counter+1] == '\0'  || 
                            curLine[counter+2] == '\0'  || 
                            curLine[counter+3] == '\0'  ||
                            curLine[counter+4] == '\0'  
                        )
                        {
                            if(curLine[counter-1] != '>')
                            {
                                flag = 1;
                            }
                            // Else ??
                        }
                        else if(curLine[counter-1] == '>' && curLine[counter+1] == '<' )
                        {
                            // What
                        }
                        else if (curLine[counter-1] == '>' && curLine[counter+2] == '<')
                        {
                            // Is  
                        }
                        else if (curLine[counter-1] == '>' && curLine[counter+3] == '<')
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

        token = strtok(curLine,s); // Returns pointer to first occurance of token

        counter = 0;

        if (curLine[counter] == '<')
        {   // Wasnt this already checked?
            counter = 1;
        }

        if (token == NULL)
        {
            flag = 1;
        }

        found = 0;


        while( token != NULL && flag == 0 )
        {
            counter3 = 0 ;
            counter1 = 0;

            if (curLine[counter] == '<')
            {
                counter++;
            }

            while ( strlen(token) > counter1 )
            {
                if ( (lineLen == 1 || lineLen == 2 || lineLen == 3) && found == 0 )
                {
                    counter = 0;
                    found = 1;
                }

                if (curLine[counter] == token[counter1] )
                {
                    counter3++;
                }
                counter1++;
                counter++;
            }
            if ( curLine[counter +1 ] == '>' || curLine[counter+1] == '<')
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
                    column = 0; 
                    width = atoi(str2[counter+1]);
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
	
    if( column = 0; > 3  && column = 0; < 13 && row > 3 && row < 13
            && list >= 0 && list < 13)
    {
        *Width = column = 0; 
        *Height = row;
        *Highscores = list;
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
*/