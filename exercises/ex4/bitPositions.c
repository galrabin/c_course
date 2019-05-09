#include <stdio.h>

/*************************************************
*  bitPositions.c
*  --------------
*  A program containing functions for determining
*  the bits turned on in the binary
*  representation of integers
*************************************************/

/************************************************/
/* IMPORTANT NOTE:                              */
/* !! MODIFY CODE ONLY IN THE MARKED PLACES !!  */
/************************************************/

/********************************/
/**    FUNCTION DECLARATIONS   **/
/********************************/

/*********************************
* Problem 2.2
* computes the LSB of a given number
*********************************/
int getLSBpos(int);

/*********************************
* Problem 2.3
* computes the MSB of a given number
*********************************/
int getMSBpos(int);

/*********************************
* Problem 2.4
* computes the next bit turned on
* in the binary representation
* of a given number
*********************************/
int getNextBitPos(int);

/*********************************
* Problem 2.5
* prints all bit positions turned on
* in the binary representation
* of a given number
*********************************/
void printBP(int);


/********************************/
/**    FUNCTION DEFINITIONS    **/
/********************************/


/*********************************
* Problem 2.2
* computes the LSB of a given number
* param:
* a (int)
* returns the LSB of a
*********************************/
int getLSBpos(int a) {
   /*** Problem 2.2:                   ***/
   /*** vvvv MODIFY HERE vvvv          ***/
     if (a == 0){
         return -1;
     } else {
         if (a & 1 == 1) {
             return 0;
         } else {
             return getLSBpos(a / 2) + 1;
         }
     }

   /*** ^^^^ MODIFY HERE ^^^^          ***/
}

/*********************************
* Problem 2.3
* computes the MSB of a given number
* param:
* a (int)
* returns the MSB of a
*********************************/
int getMSBpos(int a)  {
   /*** Problem 2.3:                   ***/
   /*** vvvv MODIFY HERE vvvv          ***/
   if (a == 0){
       return -1;
   } else {
       if (a > 0) {
           int move = getLSBpos(a) + 1;
           if (a == 1) {
               a = 0;
           } else {
               a = a >> move;
           }
           return getMSBpos(a) + move;
       } else if (a < 0){
           return 31;
       }
   }
   /*** ^^^^ MODIFY HERE ^^^^          ***/
}


/*********************************
* Problem 2.4
* computes the next bit turned on
* in the binary representation
* of a given number
* param:
* a (int)
* if parameter a equals the last number that the function was called with,
* then return the next bit position in bp(a).
* if previous bit position was the MSB, then reutrn -1.
* if parameter a is differnt from the last number that the function was called with, 
* or the last position returned was -1, then return the LSB.
*********************************/
int getNextBitPos(int a) {
   /*** Problem 2.3:                                     ***/
   /*** last a the function was called with              ***/
   static int last_a   =  0;
   /*** last position that the function returned         ***/
   static int last_pos = -1;

   /***             vvvv MODIFY HERE vvvv               ***/
   /***             ^^^^ MODIFY HERE ^^^^               ***/
   if (a != last_a){
       last_a = a;
       last_pos = getLSBpos(a);
       return last_pos;
   }
   if (last_pos == getMSBpos(a)) {
       last_pos = -1;
       return last_pos;
   } else {
       int move = last_pos + 1;
       a = a >> move;
       int next_one = getLSBpos(a);
       last_pos += next_one + 1;
       return last_pos;
   }
}

/*********************************
* Problem 2.5
* prints all bit positions turned on
* in the binary representation
* of a given number
* param:
* a (int)
* uses the following format: bp(a) = pos1 pos2 ...
* there should be a single space character between every two positions
* and a newline should be printed in the end.
*********************************/
void printBP(int a){
   /***             vvvv MODIFY HERE vvvv               ***/
   /***             ^^^^ MODIFY HERE ^^^^               ***/
   int current = getNextBitPos(a);
   while (current != -1){
       printf("%d ", current);
       current = getNextBitPos(a);
   }
   printf("\n");
}






int main() {
  
   /***         USE THIS CODE FOR TESTING     ***/
   /***     YOU MAY ALSO ADD MORE TESTS HERE  ***/
   /***      AND MODIFY FUNCTION AS YOU WISH  ***/

   printf("Tests for Problem 2.2:\n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   printf("getLSBpos(%3d) = %3d\n", 4 , getLSBpos( 4));
   printf("getLSBpos(%3d) = %3d\n", 24, getLSBpos(24));
   printf("getLSBpos(%3d) = %3d\n", 0 , getLSBpos( 0));
   printf("getLSBpos(%3d) = %3d\n", 17, getLSBpos(17));
   printf("getLSBpos(%3d) = %3d\n", -1, getLSBpos(-1));
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
   
   printf("\nTests for Problem 2.3:\n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   printf("getMSBpos(%3d) = %3d\n",  4, getMSBpos( 4));
   printf("getMSBpos(%3d) = %3d\n", 24, getMSBpos(24));
   printf("getMSBpos(%3d) = %3d\n",  0, getMSBpos( 0));
   printf("getMSBpos(%3d) = %3d\n", 17, getMSBpos(17));
   printf("getMSBpos(%3d) = %3d\n", -1, getMSBpos(-1));
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");
   
   printf("\nTests for Problem 2.4:\n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   int i=1;
   printf("%2d) getNextBitPos(%3d) = %3d\n",i++,44,getNextBitPos(44));
   printf("%2d) getNextBitPos(%3d) = %3d\n",i++,44,getNextBitPos(44));
   printf("%2d) getNextBitPos(%3d) = %3d\n",i++,44,getNextBitPos(44));
   printf("%2d) getNextBitPos(%3d) = %3d\n",i++,44,getNextBitPos(44));
   printf("%2d) getNextBitPos(%3d) = %3d\n",i++,44,getNextBitPos(44));
   printf("%2d) getNextBitPos(%3d) = %3d\n",i++,44,getNextBitPos(44));
   printf("%2d) getNextBitPos(%3d) = %3d\n",i++, 6,getNextBitPos( 6));
   printf("%2d) getNextBitPos(%3d) = %3d\n",i++,44,getNextBitPos(44));
   printf("%2d) getNextBitPos(%3d) = %3d\n",i++, 6,getNextBitPos( 6));
   printf("%2d) getNextBitPos(%3d) = %3d\n",i++, 6,getNextBitPos( 6));
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n");

   printf("\nTests for Problem 2.5:\n");
   printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
   printf("printBP(%3d):\n",  44);
   printBP(44);
   printf("printBP(%3d):\n",   6);
   printBP( 6);
   printf("printBP(%3d):\n",   0);
   printBP( 0);
   printf("printBP(%3d):\n",  -1);
   printBP(-1);
   printf("getNextBitPos(%3d) = %3d\n", 44,getNextBitPos(44));
   printf("printBP(%3d) (after calling getNextBitPos):\n",  44);
   printBP(44);
   return 0;
}

