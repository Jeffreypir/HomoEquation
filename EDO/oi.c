#include <stdio.h>
#include <stdlib.h>
#define EXIT_SUCESS 0

/*==================== PROGRAM ==============================
 * Program: oi.c
 * Description: progrma simple 
 * Date of Create: sáb 12 out 2019 13:54:54 -03
 * Update in: sáb 12 out 2019 13:55:04 -03
 * Author:Jefferson Bezerra dos Santos
 * Compiler: gcc oi.c -o oi  
 *===========================================================
 */


/*=================== FUNCTION MAIN () ======================
 * Function: main()
 * Description: program simple
 * ==========================================================
 */
int main(int argc, char *argv[]){
	int i = 0, n = atoi(argv[1]);
	while ( ++i <= n){
		printf("%20d\n",i);
	}
		return EXIT_SUCESS;
}/*----------End of function-----------------*/
