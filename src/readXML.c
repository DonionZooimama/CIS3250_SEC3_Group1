/**
 *  Jordan Evans
 *  0964044
 *  The ReadXML function is a parser for a custom xml-like filetype. The
 *  function opens the "data.xml" file and reads it into memory. It then
 *  checks each line for either the width tag (<Width>), height tag (<Height>)
 *  or the highscores tag (<Highscores>). If height or width arent present
 *  in the file, an error is printed to stdout. If highscore isn't present,
 *  *Highscore is set to 0. If all tags are present, the parser extracts the
 *  value between the open and close tags and assigns it to the *Width, 
 *  *Height and *Highscores pointers.
 */

#include "header.h"

//Jordan
// Edit to allow same pre and post conditions.

void ReadXML(int *width, int *height, int *highscores){

    FILE *fp;
    char curLine[555];
    int isWidth = 0;
    int isHeight = 0;
    int isHighscore = 0;
    int bWidth = 0;
    int bHeight = 0;
    int bHighscore = 0;

    fp = fopen( "data.xml", "r" );

    if( fp == NULL )
    {
        printf( "Error opening configuration file (data.xml)\n" );
        return;
    }

    while ( /* fscanf(fp, "%s", curLine) != 0 */ fgets ( curLine, sizeof curLine, fp ) != NULL ) 
    {
        int lineLen = 0;
        if( curLine != NULL  &&  strcmp( curLine, "" ) != 0 ) // Check to see if the line is NULL or empty (an error)
        {
            lineLen = strlen( curLine );

            if( curLine[ 0 ] == '<' )
            {
                int valueLen = 1;
                int startI;

                if( strncmp( curLine, "<Width>", 7 ) == 0 )
                {
                    startI = 7;
                }
                else if( strncmp( curLine, "<Height>", 8 ) == 0 )
                {
                    startI = 8;
                }
                else if( strncmp( curLine, "<Highscores>", 12 ) == 0 )
                {
                    startI = 12;
                }
                else 
                {
                    startI = -1;
                }

                if( startI != -1 )
                {
                    for( int i = startI; i < lineLen; i++ ){
                        if( curLine[i] != '<' )
                        {
                            valueLen++;
                        }
                        else 
                        {
                            break;
                        }
                    }

                    char *valueStr = malloc( sizeof( char ) * ( lineLen - ( startI * 2 + 1 ) ) + 1 );
                    memcpy( valueStr, &curLine[ startI ], valueLen );
                    valueStr[ valueLen ] = '\0';

                    if( strncmp( curLine, "<Width>", 7 ) == 0 )
                    {
                        bWidth = atoi( valueStr );

                        if( bWidth != 0 )
                        {
                            isWidth = 1;
                        }
                        else 
                        {
                            printf( "Invalid Width value: %s\n", valueStr );
                        }
                    }
                    else if( strncmp( curLine, "<Height>", 8 ) == 0 )
                    {
                        bHeight = atoi( valueStr );

                        if( bHeight != 0 )
                        {
                            isHeight = 1;
                        }
                        else 
                        {
                            printf( "Invalid Height value: %s\n", valueStr );
                        }
                    }
                    else if( strncmp( curLine, "<Highscores>", 12 ) == 0 )
                    {
                        bHighscore = atoi( valueStr );

                        if( bHighscore != 0 )
                        {
                            isHighscore = 1;
                        }
                        else 
                        {
                            printf( "Invalid Highscore value: %s\n", valueStr );
                        }
                    }
                    free( valueStr );
                }    
            }
        }
        else 
        {
            printf( "Empty or NULL line encountered in configuration file.\n" );
            fclose( fp );
            return;
        }
    }

    fclose( fp );

    if( isWidth && isHeight )
    {
        *width = bWidth;
        *height = bHeight;
    }
    else 
    {
        printf( "Invalid Configuration file.\n" );
    }

    if( isHighscore )
    {
        *highscores = bHighscore;
    }
    else 
    {
        *highscores = 0;
    }

    return;
}

