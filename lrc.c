/*This program was written by Md Shafiul Haque. It is a simple l r c game. */
#include<stdio.h>
#include<stdlib.h>

int main()
{
    typedef enum faciem {LEFT,RIGHT,CENTER,PASS} faces;
    faces die[] = {LEFT, RIGHT, CENTER, PASS,PASS,PASS};
    const char *names[] = {"Whoopi","Dale", "Rosie", "Jimmie", "Barbara", "Kyle", "Raven","Tony","Jenny","Clint"};
    unsigned int seed; // The seed is unsigned, it is assigned using scan
    int players;
    int randomNumber;
    printf("Random Seed: ");
    scanf("%u", &seed);// First ask for the seeds
    printf("How many players? ");
    scanf("%d", &players);// Next ask for the number of players
    srand(seed);
    int banks[players];// Creates an array of bank for each players
    for (int i=0; i<players;i++)
    {
        banks[i]=3;//Gives $3 to every player that plays
    }
    int center=0;//Counts the amount of money in the pot.
    
    
    for (int i=0; i<players;i++)
    {
        if (banks[i]!=0)// When someone has money, it prints another line. Then prints the name.
	{
            printf("\n");
            printf("%s rolls... ",names[i]);
        }
        
        int k= banks[i];// Looks for the money that the bank has.
        
        for (int j=0;j<k && j<3;j++)
	{
            randomNumber = rand()%6;// Randomizes the numbers.
            if (die[randomNumber]==LEFT)// The array for the die is left.
	    {
                banks[(i+players-1)%players]+=1;// this is the equation used to determine the position of the left player. Gives $1 to the next player.
                banks[i]-=1;// Takes out a dollar from the person.
                printf("gives $1 to %s ",names[(i+players-1)%players]);
            }
            else if (die[randomNumber]==RIGHT)// Checks if the roll is right.
	    {
                banks[(i+players+1)%players]+=1;// This is the equation used to give a dollar to the right person.
                banks[i]-=1;// Lowes one dollars.
                printf("gives $1 to %s ",names[(i+players+1)%players]);
            }
            else if (die[randomNumber]==CENTER)// If the random number is at the center
	    {
                banks[i]-=1;// decreases the amount by a dollar.
                center+=1;// increases the amount by one.
                printf("puts $1 in the pot ");
            }
            else if (die[randomNumber]==PASS)// if its a pass
 	    {
                printf("gets a pass ");
            }
        }
        int loosers=0;// Looks for the number of inactive players. The local variable is 0, becuase it checkes after each player.
        for (int k=0;k<players;k++)
	{
            if (banks[k]==0)//It constantly counts the number of people with $0
	    {
                loosers++;
                if (loosers==players-1)
	        {
                    for (int i=0;i<players;i++)//it looks for the player that doesn't have 0 dollars
		    {
                        if(banks[i]!=0)// The game  stops and announces the winner
			{
                            printf("\n%s wins the $%d pot with $%d left in the bank! \n",names[i],center,banks[i]);   
                        }
                    }
                    return 0;//This is used to stop the game, when the winner is announced
                }
                
            }
            
        }
        if(i==players-1 && loosers!=players-1)//If more than one person has money, the game loops.
	{
            i=-1;//Then the loop increment by 1 from -1 and starts from the position 0 player.
        }   
    }
    return 0;
}
